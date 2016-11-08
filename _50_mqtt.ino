/*
 Basic MQTT example with Authentication
 
  - connects to an MQTT server, providing username
    and password
  - publishes "hello world" to the topic "outTopic"
  - subscribes to the topic "inTopic"
*/

#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

byte mqtt_server[] = { 192,168, 1, 3 };

void callback(char* topic, byte* payload, unsigned int length) {
  payload[length] = '\0';
  String strPayload = String((char*)payload);
  Serial.print("IN: ");
  Serial.println(strPayload);
  executeRemoteCommand(strPayload);  
}


PubSubClient mqtt_client(mqtt_server, 1883, callback, client);

void sendMqttState(String state) {
  Serial.print("STATE: ");
  Serial.print(state);
  boolean connected = mqtt_client.connected();
  if (!connected) {
     initializeMqtt();
  }
  char ssid[state.length()+1];        state.toCharArray(ssid, state.length()+1);
  boolean publishState = mqtt_client.publish("/houseIn", ssid); 
  Serial.print(" connected: ");
  Serial.print(connected);

  Serial.print(" published: ");
  Serial.println(publishState);
}

void initializeMqtt()
{
  if (mqtt_client.connect("arduinoClient", "openHab", "openHabPass")) {
    mqtt_client.subscribe("/house");
    Serial.println("MQTT connect OK");
  } else {
    Serial.println("MQTT connect failed");
    
  }
}

void checkMqtt()
{
  mqtt_client.loop();
}


