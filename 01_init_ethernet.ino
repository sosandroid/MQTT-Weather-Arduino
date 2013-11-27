/******
* Weather data sensor project
* File : 01_init_ethernet.ino
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


//Define other global variables
byte mac[]    = { 0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED }; // mac addresse of the board
byte ip[]     = { 192, 168, 35, 114 }; //default address if DHCP fails

//Create objects
EthernetClient ethClient;

