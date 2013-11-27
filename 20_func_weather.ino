/******
* Weather data sensor project
* File : 20_func_weather.ino
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

void getWeather() {
	//populates the weather_data array
	ledswitch();
	if (debug_enabled) printSerialFloat("start weather data capture");
	
	weather_data[0] = analogRead(temt6000analogPin) * 1.0;
	if (debug_enabled) printSerialFloat("Light Temt6000 (lux): ", weather_data[0]);
	
	weather_data[1] = getTempBMP085();
	if (debug_enabled) printSerialFloat("Temp BMP085 (degC): ", weather_data[1]);
	
	weather_data[2] = getPresBMP085();
	if (debug_enabled) printSerialFloat("Pressure BMP085 (hPa): ", weather_data[2]);
	
	weather_data[3] = sht1x.readTemperatureC();
	if (debug_enabled) printSerialFloat("Temp SHT15 (degC): ", weather_data[3]);
	
	weather_data[4] = sht1x.readHumidity();
	if (debug_enabled) {
		printSerialFloat("Humidity SHT15 (%HR): ", weather_data[4]);
		printSerialFloat("end of weather data capture");
	}
	
	ledswitch();
}

float getTempBMP085() {
	barometer.setControl(BMP085_MODE_TEMPERATURE);
	lastMicros = micros();
	while (micros() - lastMicros < barometer.getMeasureDelayMicroseconds());
	return barometer.getTemperatureC();
}
float getPresBMP085() {
	barometer.setControl(BMP085_MODE_PRESSURE_3);
	lastMicros = micros();
	while (micros() - lastMicros < barometer.getMeasureDelayMicroseconds());
	return barometer.getPressure() / 100; //pressure in hPa
}
