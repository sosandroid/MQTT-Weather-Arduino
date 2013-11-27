/******
* Weather data sensor project
* File : 01_init_weather.ino
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
float weather_data[] = {
	0.0, // lumiere
	0.0, // temperature BMP085
	0.0, // pressure BMP085
	0.0, // temperature SHT15
	0.0  // humidity SHT15
	};
