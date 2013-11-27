/******
* Weather data sensor project
* File : 01_init_bmp085.ino
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
int32_t lastMicros;
//create object
BMP085 barometer;

