import paho.mqtt.client as mqtt
import time
import math
import random

host          = "mqtt.xinabox.cc"
client_id     = "dataPosting"
username      = "nsl"
# Please keep password private!
password      = "PasswordGoesHere"
port          = 1883
clean_session = True

mqttc = mqtt.Client(client_id, clean_session)
mqttc.username_pw_set(username, password)
mqttc.connect(host, port)


def getUTC():
    def padZero(number):
        temp = str(number)
        if len(temp) == 1:
            temp = "0" + temp
        return temp
    UTCtime = time.gmtime()
    utc = "%s-%s-%sT%s:%s:%s" % (UTCtime.tm_year,
                                 padZero(UTCtime.tm_mon),
                                 padZero(UTCtime.tm_mday),
                                 padZero(UTCtime.tm_hour),
                                 padZero(UTCtime.tm_min),
                                 padZero(UTCtime.tm_sec))
    return utc

# Settings for the getRand function, which is called by jsonRandom
# 'dataType':[start,min,max,step]
values={'t':[15, -15, 35, 1],
        'h':[30, 0, 100, 3],
        'p':[100000,80000,180000,1000],
        'l':[8, 0, 15, 1],
        'r':[65, 55, 85, 1],
        'a':[2000000, 1700000, 2300000, 1000],
        }

def getRand(i):
    a=values[i][0] #last
    b=values[i][1] #min
    c=values[i][2] #max
    d=values[i][3] #step
    f=2*d          #local range
    while True:
        g=random.randrange(a-f,   # local min
                           a+f+1, # local max
                           d)     # step
        if b <= g <= c:
            values[i][0] = g
            return g

def jsonRandom(i, chipID):
    # i: all positive integers (use loop variable)
    # latitude: sine output of i
    # longitude: -180 through 180, then repeat

    f = lambda x: 80 * math.sin(x/80)

    t=getRand('t')
    h=getRand('h')
    p=getRand('p')
    l=getRand('l')
    r=getRand('r')
    a=getRand('a')
    latitude    = round(f(i),4)
    longitude   = (i%360)-180
    unitname    = "Jacobs Test Unit"
    org         = "Satelite Software Team"
    timestamp   = getUTC()

    jsonFile = {"GS": {
        "SW01":{"Temperature(C)": t,
                "Humidity(%)": h,
                "Pressure(Pa)": p},
        "SL01":{"Lux": l,
                "UVA(mW/m^2)": 0,
                "UVB(mW/m^2": 0,
                "UVI": 0},
        "CW01":{"RSSI":r,
                "Chip ID":chipID,
                 "MAC":"11:22:33:77:88:99"},
        "Input":{"Unit Name": unitname,
                 "Organization": org,
                 "Location_lat_lon": [
                     latitude,
                     longitude],
                 "Altitude": a},
        "Timestamp":{"Created": timestamp}}}

    return jsonFile

print("Running jsonRandom")
MQTTtopic = "nsl/data/TUThinSat"
i = 0
while True:
    chipID = 19938676
    payload = str(jsonRandom(i, chipID)).replace('\'', '"')
    print(payload)
    print("Publish status = ", mqttc.publish(MQTTtopic, payload, qos=2, retain=False))
    print("Connection status = ", mqttc.connect(host, port))
    i += 5
    time.sleep(random.randrange(1, 3))
