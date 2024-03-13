/* This is the header file for the INA3221_Utils class, which provides a convenient interface for working with the INA3221
 three-channel voltage and current sensor. It includes the Wire library for I2C communication and the Adafruit_INA3221
 library for interacting with the INA3221 chip.

The INA3221_Utils class includes public methods for setting up and configuring the INA3221 chip, as well as for reading
the bus voltage, shunt voltage, and current for each of the three channels. It also includes private member variables
for storing the INA3221 object, the number of samples to average for each measurement, the conversion times for voltage
and current measurements, and the value of the shunt resistor used in the circuit. */

#ifndef INA3221_UTILS_H
#define INA3221_UTILS_H

#include <Wire.h>
#include "INA3221.h"

class INA3221_Utils
{
public:
	INA3221_Utils();
	void begin();
	void setAveraging(uint8_t samples);
	void setVoltageConversionTime(uint16_t time);
	void setCurrentConversionTime(uint16_t time);
	void setShuntResistorValue(float value);
	float getBusVoltage(uint8_t channel);
	float getShuntVoltage(uint8_t channel);
	float getCurrent(uint8_t channel);

private:
	INA3221 ina3221;
	uint8_t averagingSamples;
	uint16_t voltageConversionTime;
	uint16_t currentConversionTime;
	float shuntResistorValue;
};

#endif /* INA3221_UTILS_H */
