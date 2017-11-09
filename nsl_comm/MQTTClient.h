/*******************************************************************************
  * Copyright (c) 2009, 2017 IBM Corp.
  *
  * All rights reserved. This program and the accompanying materials
  * are made available under the terms of the Eclipse Public License v1.0
  * and Eclipse Distribution License v1.0 which accompany this distribution.
  *
  * The Eclipse Public License is available at
  *    http://www.eclipse.org/legal/epl-v10.html
  * and the Eclipse Distribution License is available at
  *   http://www.eclipse.org/org/documents/edl-v10.php.
  *
  * Contributors:
  *    Ian Craggs - initial API and implementation and/or initial documentation
  *    Ian Craggs, Allan Stockdill-Mander - SSL updates
  *    Ian Craggs - multiple server connection support
  *    Ian Craggs - MQTT 3.1.1 support
  *    Ian Craggs - remove const from eyecatchers #168
  *******************************************************************************/
 
   #if defined(__cplusplus)
    extern "C" {
   #endif
   #if !defined(MQTTCLIENT_H)
   #define MQTTCLIENT_H
   
   #if defined(WIN32) || defined(WIN64)
     #define DLLImport __declspec(dllimport)
     #define DLLExport __declspec(dllexport)
   #else
     #define DLLImport extern
     #define DLLExport __attribute__ ((visibility ("default")))
   #endif
   
   #include <stdio.h>
   
   #if !defined(NO_PERSISTENCE)
   #include "MQTTClientPersistence.h"
   #endif
   
   #define MQTTCLIENT_SUCCESS 0
   
   #define MQTTCLIENT_FAILURE -1
   
   /* error code -2 is MQTTCLIENT_PERSISTENCE_ERROR */
   
   #define MQTTCLIENT_DISCONNECTED -3
   
   #define MQTTCLIENT_MAX_MESSAGES_INFLIGHT -4
   
   #define MQTTCLIENT_BAD_UTF8_STRING -5
   
   #define MQTTCLIENT_NULL_PARAMETER -6
   
   #define MQTTCLIENT_TOPICNAME_TRUNCATED -7
   
   #define MQTTCLIENT_BAD_STRUCTURE -8
   
   #define MQTTCLIENT_BAD_QOS -9
   
   #define MQTTCLIENT_SSL_NOT_SUPPORTED -10
   
   #define MQTTVERSION_DEFAULT 0
   
   #define MQTTVERSION_3_1 3
   
   #define MQTTVERSION_3_1_1 4
   
   #define MQTT_BAD_SUBSCRIBE 0x80
   
   typedef struct
   {
           char struct_id[4];
           int struct_version;
           int do_openssl_init;
   } MQTTClient_init_options;
   
   #define MQTTClient_init_options_initializer { {'M', 'Q', 'T', 'G'}, 0, 0 }
   
   void MQTTClient_global_init(MQTTClient_init_options* inits);
   
   typedef void* MQTTClient;
   typedef int MQTTClient_deliveryToken;
   typedef int MQTTClient_token;
   
   typedef struct
   {
           char struct_id[4];
           int struct_version;
           int payloadlen;
           void* payload;
           int qos;
           int retained;
           int dup;
           int msgid;
   } MQTTClient_message;
   
   #define MQTTClient_message_initializer { {'M', 'Q', 'T', 'M'}, 0, 0, NULL, 0, 0, 0, 0 }
   
   typedef int MQTTClient_messageArrived(void* context, char* topicName, int topicLen, MQTTClient_message* message);
   
   typedef void MQTTClient_deliveryComplete(void* context, MQTTClient_deliveryToken dt);
   
   typedef void MQTTClient_connectionLost(void* context, char* cause);
   
   DLLExport int MQTTClient_setCallbacks(MQTTClient handle, void* context, MQTTClient_connectionLost* cl,
                                                                           MQTTClient_messageArrived* ma, MQTTClient_deliveryComplete* dc);
   
   
   DLLExport int MQTTClient_create(MQTTClient* handle, const char* serverURI, const char* clientId,
                   int persistence_type, void* persistence_context);
   
   typedef struct
   {
           char struct_id[4];
           int struct_version;
           const char* topicName;
           const char* message;
           int retained;
           int qos;
           struct
           {
           int len;            
                   const void* data;  
           } payload;
   } MQTTClient_willOptions;
   
   #define MQTTClient_willOptions_initializer { {'M', 'Q', 'T', 'W'}, 1, NULL, NULL, 0, 0, {0, NULL} }
   
   typedef struct
   {
           char struct_id[4];
           int struct_version;
   
           const char* trustStore;
   
           const char* keyStore;
   
           const char* privateKey;
           const char* privateKeyPassword;
   
           const char* enabledCipherSuites;
   
       int enableServerCertAuth;
   
   } MQTTClient_SSLOptions;
   
   #define MQTTClient_SSLOptions_initializer { {'M', 'Q', 'T', 'S'}, 0, NULL, NULL, NULL, NULL, NULL, 1 }
   
   typedef struct
   {
           char struct_id[4];
           int struct_version;
           int keepAliveInterval;
           int cleansession;
           int reliable;
           MQTTClient_willOptions* will;
           const char* username;
           const char* password;
           int connectTimeout;
           int retryInterval;
           MQTTClient_SSLOptions* ssl;
           int serverURIcount;
           char* const* serverURIs;
           int MQTTVersion;
           struct
           {
                   const char* serverURI;     
                   int MQTTVersion;     
                   int sessionPresent;  
           } returned;
     struct {
           int len;            
                   const void* data;  
           } binarypwd;
   } MQTTClient_connectOptions;
   
   #define MQTTClient_connectOptions_initializer { {'M', 'Q', 'T', 'C'}, 5, 60, 1, 1, NULL, NULL, NULL, 30, 20, NULL, 0, NULL, 0,         {NULL, 0, 0}, {0, NULL} }
   
   typedef struct
   {
           const char* name;
           const char* value;
   } MQTTClient_nameValue;
   
   DLLExport MQTTClient_nameValue* MQTTClient_getVersionInfo(void);
   
   DLLExport int MQTTClient_connect(MQTTClient handle, MQTTClient_connectOptions* options);
   
   DLLExport int MQTTClient_disconnect(MQTTClient handle, int timeout);
   
   DLLExport int MQTTClient_isConnected(MQTTClient handle);
   
   
   /* Subscribe is synchronous.  QoS list parameter is changed on return to granted QoSs.
      Returns return code, MQTTCLIENT_SUCCESS == success, non-zero some sort of error (TBD) */
   
   DLLExport int MQTTClient_subscribe(MQTTClient handle, const char* topic, int qos);
   
   DLLExport int MQTTClient_subscribeMany(MQTTClient handle, int count, char* const* topic, int* qos);
   
   DLLExport int MQTTClient_unsubscribe(MQTTClient handle, const char* topic);
   
   DLLExport int MQTTClient_unsubscribeMany(MQTTClient handle, int count, char* const* topic);
   
   DLLExport int MQTTClient_publish(MQTTClient handle, const char* topicName, int payloadlen, void* payload, int qos, int retained,
                                                                                                                                    MQTTClient_deliveryToken* dt);
   DLLExport int MQTTClient_publishMessage(MQTTClient handle, const char* topicName, MQTTClient_message* msg, MQTTClient_deliveryToken* dt);
   
   
   DLLExport int MQTTClient_waitForCompletion(MQTTClient handle, MQTTClient_deliveryToken dt, unsigned long timeout);
   
   
   DLLExport int MQTTClient_getPendingDeliveryTokens(MQTTClient handle, MQTTClient_deliveryToken **tokens);
   
   DLLExport void MQTTClient_yield(void);
   
   DLLExport int MQTTClient_receive(MQTTClient handle, char** topicName, int* topicLen, MQTTClient_message** message,
                   unsigned long timeout);
   
   DLLExport void MQTTClient_freeMessage(MQTTClient_message** msg);
   
   DLLExport void MQTTClient_free(void* ptr);
   
   DLLExport void MQTTClient_destroy(MQTTClient* handle);
   
   #endif
   #ifdef __cplusplus
        }
   #endif
