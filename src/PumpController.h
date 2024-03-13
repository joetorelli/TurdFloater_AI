#ifndef PumpController_h
#define PumpController_h

#include <Adafruit_MCP23X17.h>
#include <Ticker.h>
#include "INA3221Controller.h"

class PumpController
{
public:
	PumpController(uint8_t pin, uint8_t inaChannel1, uint8_t inaChannel2);
	void init();
	void turnOn();
	void turnOff();

private:
	uint8_t _pin;
	Adafruit_MCP23X17 _mcp;
	INA3221Controller _inaController;
	Ticker _ticker;

	void checkWaterFlow();
};

#endif
