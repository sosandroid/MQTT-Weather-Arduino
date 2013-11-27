/******
* Weather data sensor project
* File : 10_func_init.ino
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
void init_led() {
	//set led for status feedback
	pinMode(ledpin,OUTPUT);
	digitalWrite(ledpin, ledstatus);
	if (debug_enabled) {
		Serial.println("LED active, output low");
	}
}
void init_network() {
	if (Ethernet.begin(mac) == 0) {
		Ethernet.begin(mac, ip);
		if (debug_enabled) Serial.println("DHCP failed");
	}
	if (debug_enabled) serialprintIP();	
}
void init_i2cbus() {
	Wire.begin();
	if (debug_enabled) Serial.println("I2C bus started");
	barometer.initialize();
	if (debug_enabled) Serial.println(barometer.testConnection() ? "BMP085 connection successful" : "BMP085 connection failed");
}
void init_ConnectionMQTT() {
	mqttclient.connect(mqttclientname);
	if (debug_enabled && mqttclient.connected()) Serial.println("MQTT connected");
	subscribeMQTT();
}