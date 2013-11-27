MQTT-Weather-Arduino
====================
V 0.1

A quick project for one weather station sending sensor data to one MQTT broker. This is part of a larger project which deals with home automation.
Still in heavy development.


## Features ##
- Light measurement
- Temperature
- Atmosphere pressure
- Humidity
- Publishing through MQTT
- Multi-boards support into the code

## Boards tested ##

- Arduino Mega with ethernet shield
- Arduino Ethernet R3 (without POE)


## Todo / Not supported ##

- Read settings from MQTT broker
- Connect Open.Sen.Se platform
- Add more sensors (such as wind / rain / GPS)
- Use timer lib instead of delay function
- Use cellular connection if needed - datalogger mode
- Reduce energy draining to the maximum using other very low power board 


## Depends On ##

- [PubSubClient modified](https://github.com/sosandroid/pubsubclient) - [Original from Nick O'Leary](https://github.com/knolleary/pubsubclient)
- [i2cdevlib](https://github.com/jrowberg/i2cdevlib)
- [i2cdevlib's BMP085 lib](https://github.com/jrowberg/i2cdevlib/tree/master/Arduino/BMP085)
- [SHT1x pseudo I2C library](https://github.com/practicalarduino/SHT1x)

## Side notes ##

Requesting too heavilly the BMP085 device makes temperature sensing false

To build the Arduino sketch, import the files one by one. The whole sketch is split to ease coding