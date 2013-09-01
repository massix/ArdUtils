/*
 * NumericDisplay.cpp
 *
 *  Created on: Aug 30, 2013
 *      Author: massi
 */

#include <Arduino.h>
#include <NumericDisplay.hpp>

namespace utils {


// We have to do initialization here because Arduino's using C++ pre0x standard -_-'
//const int NumericDisplay::digitSelectorsPins[] = {12, 9, 8, 6};
//const int NumericDisplay::digitSegmentsPins[] = {11, 7, 4, 2, 1, 10, 5};
const int NumericDisplay::Numbers[10][7] =
{
		{1, 1, 1, 1, 1, 1, 0}, // 0
		{0, 1, 1, 0, 0, 0, 0}, // 1
		{1, 1, 0, 1, 1, 0, 1}, // 2
		{1, 1, 1, 1, 0, 0, 1}, // 3
		{0, 1, 1, 0, 0, 1, 1}, // 4
		{1, 0, 1, 1, 0, 1, 1}, // 5
		{1, 0, 1, 1, 1, 1, 1}, // 6
		{1, 1, 1, 0, 0, 0, 0}, // 7
		{1, 1, 1, 1, 1, 1, 1}, // 8
		{1, 1, 1, 1, 0, 1, 1}, // 9
};

NumericDisplay::NumericDisplay() :
		_digitalDotPin(0) {
	init();
};

NumericDisplay::NumericDisplay(const int digitSelectors[4], const int digitSegments[7], const int & dotPin) :
		_digitalDotPin(dotPin) {

	for (int i = 0; i < 4; i++)
		_digitSelectorsPins[i] = digitSelectors[i];

	for (int i = 0; i < 7; i++)
		_digitSegmentsPins[i] = digitSegments[i];

	init();
}

NumericDisplay::~NumericDisplay() {

}

void NumericDisplay::init() {
	for (int i = 0; i < SELECTORS; i++)
		pinMode(_digitSelectorsPins[i], OUTPUT);

	for (int j = 0; j < SEGMENTS; j++)
		pinMode(_digitSegmentsPins[j], OUTPUT);

	pinMode(_digitalDotPin, OUTPUT);
	digitalWrite(_digitalDotPin, HIGH);
}

void NumericDisplay::turnOff() {
	clearDisplay();

	// This might sound stupid, but we're actually turning the numbers off..
	activate(0, true);
	activate(1, true);
	activate(2, true);
	activate(3, true);
}

void NumericDisplay::fullWriteNumber(int number) {
	digitalWrite(_digitalDotPin, LOW);
	clearDisplay();
	activate(0, true);
	writeNumber(number / 1000 % 10);

	clearDisplay();
	activate(1, true);
	writeNumber(number / 100 % 10);

	clearDisplay();
	activate(2, true);
	writeNumber(number / 10 % 10);

	clearDisplay();
	activate(3, true);
	writeNumber(number % 10);
}

void NumericDisplay::fullWriteNumber(double number) {
	clearDisplay();
	activate(0, true);
	writeNumber((int)number / 100 % 10);

	clearDisplay();
	activate(1, true);
	writeNumber((int)number / 10 % 10);

	clearDisplay();
	activate(2, true);
	digitalWrite(_digitalDotPin, HIGH);
	writeNumber((int)number % 10);

	clearDisplay();
	activate(3, true);
	float decimal = number * 10.0;
	writeNumber((int)decimal % 10);
}

void NumericDisplay::activate(int digit, boolean activated) {
	for (int i = 0; i < SELECTORS; i++)
		digitalWrite(_digitSelectorsPins[i], HIGH);

	digitalWrite(_digitSelectorsPins[digit], (activated? LOW : HIGH));
}

void NumericDisplay::clearDisplay() {
	for (int i = 0; i < SEGMENTS; i++) {
		digitalWrite(_digitSegmentsPins[i], LOW);
	}

	digitalWrite(_digitalDotPin, LOW);
}

void NumericDisplay::writeNumber(int number) {
	for (int i = 0; i < 7; i++) {
		digitalWrite(_digitSegmentsPins[i],
				(Numbers[number][i] == 0 ? LOW : HIGH));
	}
}

}



