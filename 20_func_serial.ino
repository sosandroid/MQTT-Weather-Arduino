/******
* Weather data sensor project
* File : 20_serial
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
void serialdebug (char* message)
{
//manage debug on / off
	if (message == "enable" && debug_enabled == false) {
		debug_enabled = true;
		Serial.begin(38400);
		Serial.println("\n Debug started \n");
	}
	else if (debug_enabled) {
		Serial.println("\n Debug stopped \n");
		debug_enabled = false;
		Serial.end();
	}
}
void serialprint_startup ()
{
//print to serial lines startup info
	if (debug_enabled)
	{
		Serial.println("Weather station starting up");
		Serial.println("LED pin set as output low");
		serialprintIP();
		Serial.println(mqttclient.connected() ? "MQTT connection successful" : "MQTT connection failed");
		Serial.println(barometer.testConnection() ? "I2C & BMP085 connection successful" : "I2C or BMP085 connection failed");
		Serial.println("Data capture about to start");
		Serial.println();
	}
	//serialdebug ("disable");
}

void serialprintIP() 
{
//print IP address of the arduino board to serial
	Serial.print("My IP address: ");
	for (byte thisByte = 0; thisByte < 4; thisByte++) {
		// print the value of each byte of the IP address:
		Serial.print(Ethernet.localIP()[thisByte], DEC);
		Serial.print(".");
	}
	Serial.println();
}

void printSerialFloat(char* text, float number = 0.0) {
	char buffer[25];
	dtostrf(number, 4, 3, buffer);
	Serial.print(text);
        Serial.print(" ");
	Serial.println(buffer);
}
void serialPrintFloat(float number) {
        char buffer[25];
        dtostrf(number, 4, 3, buffer);
        Serial.println(buffer);
}
