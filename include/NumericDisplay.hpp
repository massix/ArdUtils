/*
 * NumericDisplay.hpp
 *
 *  Created on: Aug 30, 2013
 *      Author: massi
 */

#ifndef NUMERICDISPLAY_HPP_
#define NUMERICDISPLAY_HPP_

#include <Arduino.h>
#define SELECTORS 4
#define SEGMENTS 7

namespace utils {
class NumericDisplay {
public:
	NumericDisplay();
	explicit NumericDisplay(
			const int digitSelectors[4],
			const int digitSegments[7],
			const int & dotPin);
	~NumericDisplay();

	void init();
	void turnOff();
	void fullWriteNumber(int number);
	void fullWriteNumber(double number);

private:
	// Digit Selectors
	int _digitSelectorsPins[SELECTORS];
	int _digitSegmentsPins[SEGMENTS];
	int _digitalDotPin;
	static const int Numbers[10][7];

	void activate(int digit, boolean activated);

	void clearDisplay();

	void writeNumber(int number);
};

}



#endif /* NUMERICDISPLAY_HPP_ */
