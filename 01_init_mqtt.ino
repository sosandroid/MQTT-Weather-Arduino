/******
* Weather data sensor project
* File : 01_init_mqtt.ino
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

//ethernet client must be initalized before

//Define const
char* mqttclientname = "ArduinoMQTT";

//byte server[] = { 192, 168, 35, 14 }; //local address mosquitto server
byte server[] = { 78, 192, 160, 81}; //public address mosquitto server
//uint16_t port = 1883; //Mosquitto port
uint16_t port = 15998; //Public mosquitto port

//Global array for MQTT topics 
//publish to
char* topics_out[] = {
	"sensors/light/temt6000/lux",
	"sensors/temperature/bmp085/degC",
	"sensors/pressure/bmp085/hPa",
	"sensors/temperature/sht15/degC",
	"sensors/humidity/sht15/%HR"
	};
//subscribe to
char* topics_in[] = {
	"cmd/loopdelay", //wait for string representing milliseconds - not negative
	"cmd/ledblink", //wait for anything
	"cmd/serialdebug" //wait for enable to start or anything to stop
	};
//mqtt callback function does not scan automatically this array. Behaviors are hard coded
	
//Functions proto declaration
void callbackMQTT(char* topic, byte* payload, unsigned int length);
//Create object
PubSubClient mqttclient(server, port, callbackMQTT, ethClient);
