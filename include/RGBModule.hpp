/*
 * RGBModule.hpp
 *
 *  Created on: Sep 1, 2013
 *      Author: massi
 */

#ifndef RGBMODULE_HPP_
#define RGBMODULE_HPP_

#include <Arduino.h>
#include <Print.h>
#include <Printable.h>

namespace utils {
	class RGBModule : public Printable {
	public:
		RGBModule(int red, int green, int blue);
		virtual ~RGBModule() {};

		void setBlue(int value);
		void setGreen(int value);
		void setRed(int value);

		void setColor(uint32_t rgbcolor);

		virtual size_t printTo(Print& p) const;

	private:
		int _red;
		int _green;
		int _blue;

		int _redValue;
		int _greenValue;
		int _blueValue;
	};
}



#endif /* RGBMODULE_HPP_ */
