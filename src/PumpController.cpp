#include "PumpController.h"

PumpController::PumpController(uint8_t pin, uint8_t inaChannel1, uint8_t inaChannel2)
	: _pin(pin), _inaController(inaChannel1, inaChannel2)
{
}

void PumpController::init()
{
	_mcp.begin();
	_mcp.pinMode(_pin, OUTPUT);
	_mcp.digitalWrite(_pin, LOW);
}

void PumpController::turnOn()
{
	_mcp.digitalWrite(_pin, HIGH);
	_ticker.once(1, [this]()
				 { checkWaterFlow(); }); // Check water flow after 1 sec
}

void PumpController::turnOff()
{
	_mcp.digitalWrite(_pin, LOW);
}

void PumpController::checkWaterFlow()
{
	float flow = _inaController.WaterFlow();
	if (flow == 0)
	{
		turnOff();
		_mcp.digitalWrite(ALARM_RELAY_PIN, HIGH);
		_mcp.digitalWrite(NO_FLOW_LED_PIN, HIGH);
	}
	else
	{
		while (true)
		{
			float level = _inaController.WaterLevel();
			if (level < 500 || _inaController.WaterFlow() == 0)
			{
				turnOff();
				break;
			}
			turnOn();
		}
	}
}
