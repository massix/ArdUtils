/*
 * TemperatureSensor.cpp
 *
 *  Created on: Aug 30, 2013
 *      Author: massi
 */

#include <Arduino.h>
#include <TemperatureSensor.hpp>

namespace utils {

TemperatureSensor::TemperatureSensor(int analogPin) :
				_lastTemperatureFloat(.0),
				_lastTemperatureInt(0),
				_analogPin(analogPin) {
	pinMode(_analogPin, OUTPUT);
}


TemperatureSensor::~TemperatureSensor() {
}

float TemperatureSensor::readTemperatureFloat() {
	_lastTemperatureFloat = (5.0 * analogRead(_analogPin) * 100.0) / 1024;
	return _lastTemperatureFloat;
}

int TemperatureSensor::readVoltage() {
	return analogRead(_analogPin);
}

int TemperatureSensor::readTemperatureInt() {
	_lastTemperatureInt = (125 * analogRead(_analogPin)) >> 8;
	return _lastTemperatureInt;
}

int TemperatureSensor::getLastTemperatureInt() {
	return _lastTemperatureInt;
}

float TemperatureSensor::getLastTemperatureFloat() {
	return _lastTemperatureFloat;
}

}



