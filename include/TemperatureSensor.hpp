/*
 * TemperatureMonitor.hpp
 *
 *  Created on: Aug 30, 2013
 *      Author: massi
 */

#ifndef TEMPERATURESENSOR_HPP_
#define TEMPERATURESENSOR_HPP_

#include <Arduino.h>

namespace utils {
class TemperatureSensor {
public:
	TemperatureSensor(int analogPin);
	~TemperatureSensor();

	float readTemperatureFloat();
	int readTemperatureInt();

	int getLastTemperatureInt();
	float getLastTemperatureFloat();

	int readVoltage();

private:
	float _lastTemperatureFloat;
	int _lastTemperatureInt;
	int _analogPin;
};

};


#endif /* TEMPERATUREMONITOR_HPP_ */
