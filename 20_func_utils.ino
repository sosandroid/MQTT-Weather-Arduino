/******
* Weather data sensor project
* File : 20_utils
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
void ledswitch()
{
  ledstatus = !ledstatus;
  digitalWrite(ledpin, ledstatus);
}

void ledrevert_1s()
{
//switch led status during 1s and revert
  ledstatus = !ledstatus;
  digitalWrite(ledpin, ledstatus);
  delay(1000);
  ledstatus = !ledstatus;
  digitalWrite(ledpin, ledstatus);
}

void ledrevert_cust(int delayt)
{
//switch led status during 'delayt' milliseconds and revert
  ledstatus = !ledstatus;
  digitalWrite(ledpin, ledstatus);
  delay(delayt);
  ledstatus = !ledstatus;
  digitalWrite(ledpin, ledstatus);
}
void ledblink_1s()
{
//blink led status during 1s and revert
  ledstatus = !ledstatus;
  digitalWrite(ledpin, ledstatus);
  delay(1000);
  ledstatus = !ledstatus;
  digitalWrite(ledpin, ledstatus);
  delay(1000);
}

void ledblink_cust(int delayt)
{
//blink led status during 'delayt' milliseconds and revert
  ledstatus = !ledstatus;
  digitalWrite(ledpin, ledstatus);
  delay(delayt);
  ledstatus = !ledstatus;
  digitalWrite(ledpin, ledstatus);
  delay(delayt);
}

void setLoopDelay (int delai) {
	if (delai < 1000) delai = 1000; //minimum delai for main loop 1000 milliseconds
	loop_delay = delai;
}

