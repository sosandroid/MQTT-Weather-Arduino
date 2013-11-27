/******
* Weather data sensor project
* File : 99_weather_setuploop.ino
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
void setup ()
{

  //start serial debug
  serialdebug("enable");
  
  //Set LED pin
  init_led();
  
  //start network
  init_network();
  
  // Start I2C devices
  init_i2cbus();
  
  //start MQTT connection
  init_ConnectionMQTT();
}

void loop ()
{
        mqttclient.loop();
        delay(500); 	
        getWeather();
	publishWeatherMQTT();
	//publishWeatherSense();
	//listenMQTT();
	delay(loop_delay);
}

