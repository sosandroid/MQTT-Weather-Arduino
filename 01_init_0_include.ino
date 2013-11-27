/******
* Weather data sensor project
* File : 01_init_0_include.ino
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

//Include libraries needed - global declaration
#include <Wire.h>
#include <SPI.h>
#include <math.h>
#include <I2Cdev.h>
#include <BMP085.h>
#include <SHT1x.h>
#include <Ethernet.h>
#include <PubSubClient.h>
//#include <SensuinoEth.h>
//#include <SensuinoSerial.h>


//Define board model
#define MEGA2650
// #define ETHERNETNOPOE //ethernet R3


//Define general const and variables
#ifdef MEGA2650
	const int ledpin = 13; //D13
#endif

#ifdef ETHERNETNOPOE
	const int ledpin = 9; //D9
#endif

//Define other global variables
int loop_delay = 20000; //number of milliseconds to wait before starting again main loop
boolean debug_enabled = false; //enable or disable debug through serial port
boolean ledstatus = false; //to work with LED on/off

