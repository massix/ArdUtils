/*
 * NumericDisplay.cpp
 *
 *  Created on: Sep 1, 2013
 *      Author: massi
 */

#include <Arduino.h>
#include <RGBModule.hpp>

namespace utils {


RGBModule::RGBModule(int red, int green, int blue) :
					Printable(),
					_red(red),
					_green(green),
					_blue(blue),
					_redValue(0),
					_greenValue(0),
					_blueValue(0) {

	pinMode(_red, OUTPUT);
	pinMode(_blue, OUTPUT);
	pinMode(_green, OUTPUT);

	setGreen(0);
	setBlue(0);
	setRed(0);

}

void RGBModule::setGreen(int value) {
	_greenValue = value;
	analogWrite(_green, _greenValue);
}

void RGBModule::setBlue(int value) {
	_blueValue = value;
	analogWrite(_blue, _blueValue);
}

void RGBModule::setRed(int value) {
	_redValue = value;
	analogWrite(_red, _redValue);
}

void RGBModule::setColor(uint32_t rgbcolor) {
	_blueValue = rgbcolor & 0xff;
	_greenValue = (rgbcolor >> 8) & 0xff;
	_redValue = (rgbcolor >> 16) & 0xff;

	setBlue(_blueValue);
	setGreen(_greenValue);
	setRed(_redValue);
}

size_t RGBModule::printTo(Print & p) const {
	char buffer[1024];
	sprintf(buffer, "0x%2x%2x%2x", _redValue, _greenValue, _blueValue);
	return p.print(buffer);
}

}



