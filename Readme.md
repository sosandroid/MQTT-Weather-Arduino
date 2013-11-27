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


## Todo / Not supported ##

- Connect Open.Sen.Se platform
- Add more sensors (such as wind / rain)
- Read settings from MQTT broker


## Depends On ##

- [PubSubClient modified](https://github.com/sosandroid/pubsubclient) - [Original from Nick O'Leary](https://github.com/knolleary/pubsubclient)
- [I2CDevlib](https://github.com/jrowberg/i2cdevlib)
- [I2CDevlib BMP085](https://github.com/jrowberg/i2cdevlib/tree/master/Arduino/BMP085)
- [SHT1x pseudo I2C library](https://github.com/practicalarduino/SHT1x)

## Side note ##

Requesting too heavilly the BMP085 device makes temperature sensing false