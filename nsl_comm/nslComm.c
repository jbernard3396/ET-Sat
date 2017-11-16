#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "MQTTClient.h"

#define ADDRESS     "mqtt.xinabox.cc:1883"
#define CLIENTID    "dataPosting"
#define TOPIC       "MQTT Examples"
#define PAYLOAD     "{'GS': {'SW01': {'Temperature(C)': 99, 'Humidity(%)': 27, 'Pressure(Pa)': 99000}, 'SL01': {'Lux': 6, 'UVA(mW/m^2)': 0, 'UVB(mW/m^2': 0, 'UVI': 0}, 'CW01': {'RSSI': 66, 'Chip ID': 19938676, 'MAC': '11:22:33:77:88:99'}, 'Input': {'Unit Name': 'Jacobs Test Unit', 'Organization': 'Satelite Software Team', 'Location_lat_lon': [0.0, -180], 'Altitude': 2002000}, 'Timestamp': {'Created': '2017-11-14T21:11:38'}}}"
#define QOS         1
#define TIMEOUT     10000L

int main(int argc, char* argv[])
{
    MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    conn_opts.username = "nsl";
    conn_opts.password = "PasswordGoesHere";
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    MQTTClient_deliveryToken token;
    int rc;

    MQTTClient_create(&client, ADDRESS, CLIENTID,
        MQTTCLIENT_PERSISTENCE_NONE, NULL);
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;

    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        exit(-1);
    }
    pubmsg.payload = PAYLOAD;
    pubmsg.payloadlen = strlen(PAYLOAD);
    pubmsg.qos = QOS;
    pubmsg.retained = 0;
    while(1) {
        MQTTClient_publishMessage(client, TOPIC, &pubmsg, &token);
        printf("Waiting for up to %d seconds for publication of %s\n"
                "on topic %s for client with ClientID: %s\n",
                (int)(TIMEOUT/1000), PAYLOAD, TOPIC, CLIENTID);
        rc = MQTTClient_waitForCompletion(client, token, TIMEOUT);
        printf("Message with delivery token %d delivered\n", token);
        for(int i=0;i<100000;i++){
	    for(int j=0;j<100000;j++){
            }
	}
    }
    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);
    return rc;
}
