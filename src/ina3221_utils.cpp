#include "INA3221_Utils.h"
#include <Wire.h>

uint8_t INA3221_addr = INA3221_DEFAULT_ADDR; // default INA3221 address
float INA3221_ShuntResistorValue = INA3221_DEFAULT_SHUNT_RESISTOR_VALUE;

void INA3221_begin()
{
	Wire.begin();
}

void INA3221_setAddress(uint8_t addr)
{
	INA3221_addr = addr;
}

void INA3221_setShuntResistorValue(float value)
{
	INA3221_ShuntResistorValue = value;
}

float INA3221_getBusVoltage(uint8_t channel)
{
	Wire.beginTransmission(INA3221_addr);
	Wire.write(INA3221_REG_BUS_VOLTAGE_BASE + (channel - 1) * 2);
	Wire.endTransmission();
	Wire.requestFrom(INA3221_addr, (uint8_t)2);

	uint16_t value = Wire.read() << 8 | Wire.read();

	// Convert the raw value to a voltage in volts
	return value * 0.00125;
}

float INA3221_getShuntVoltage(uint8_t channel)
{
	Wire.beginTransmission(INA3221_addr);
	Wire.write(INA3221_REG_SHUNT_VOLTAGE_BASE + (channel - 1) * 2);
	Wire.endTransmission();
	Wire.requestFrom(INA3221_addr, (uint8_t)2);

	int16_t value = Wire.read() << 8 | Wire.read();

	// Convert the raw value to a voltage in millivolts
	return value * 0.00001;
}

float INA3221_getCurrent(uint8_t channel)
{
	float shuntVoltage = INA3221_getShuntVoltage(channel);

	// Calculate the current using Ohm's law (I = V / R)
	return shuntVoltage / INA3221_ShuntResistorValue;
}
