/******
* Weather data sensor project
* File : 20_mqtt
*
* Weather station using MQTT transmission, BMP085, SHT15 and TEMT6000
*
* Depends on 
* PubSubClient (modified) https://github.com/sosandroid/pubsubclient - (Original) https://github.com/knolleary/pubsubclient
* I2CDevlib https://github.com/jrowberg/i2cdevlib
* I2CDevlib BMP085 https://github.com/jrowberg/i2cdevlib/tree/master/Arduino/BMP085
* SHT1x pseudo I2C library https://github.com/practicalarduino/SHT1x
*
* 2013 October
* Emmanuel Havet
********/

void subscribeMQTT() {
	//Subscribe to each needed topics
	for (int i = 0; i < 3 ; i++) {
		mqttclient.subscribe(topics_in[i]);
		if (serialdebug) {
			Serial.print("MQTT subscribed to ");
			Serial.println(topics_in[i]);
		}
	}
}

void initConnectionMQTT() {
	mqttclient.connect(mqttclientname);
	subscribeMQTT();
}

void publishWeatherMQTT() {
	if (mqttclient.connected()) {
	    for (int i = 0; i < 5; i++) {
                        // publish float values
			if (mqttclient.publish(topics_out[i], weather_data[i], true, 4, 2)) {
                          if (serialdebug) {
                              Serial.print("published ");
                              Serial.print(topics_out[i]);
                              Serial.print(" : ");
                              serialPrintFloat(weather_data[i]);
                          }
                        }
                        else {
                          if (serialdebug) {
                              Serial.print(topics_out[i]);
                              Serial.println(" not published");
                          }
                        }
		}
        }
        else {
            if (serialdebug) Serial.println("MQTT disconnected, try to connect...");
            mqttclient.connect(mqttclientname);
            publishWeatherMQTT();
        }
}
void listenMQTT() {
     mqttclient.loop(); 
}


void callbackMQTT(char* topic, byte* payload, unsigned int length) {

    if (serialdebug) {
		Serial.println("Got a message, let's analyse");
		Serial.print("Topic : ");
		Serial.println(topic);
		Serial.print("Message : ");
		Serial.println(payload);
	}
	
	if (topic == topics_in[0]) {
		//set main loop delay
		int value = atoi((char*) payload);
		setLoopDelay(value);
		if (serialdebug) {
			Serial.print("main loop delay modified to ");
			Serial.println((char*) payload);
		}
	}
	
	if (topic == topics_in[1]) {
		//blink the led twice 1s
		ledblink_1s();
		ledblink_1s();
		if (serialdebug) Serial.println("LED blinked twice");
	}
	
	if (topic == topics_in[2]) {
		//set / unset the serial debug
                char* buffer = (char*)payload;
		serialdebug (buffer);
		// no debug message here as this is embed in the serialdebug function
	}
	//topics out of this range does nothing
}
