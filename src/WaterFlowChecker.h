/*This class uses the INA3221Controller, PumpController, and MCP23017Controller classes
that we have previously defined to check the water flow every second using the Ticker library.
If there is no flow, the pump is turned off, the alarm relay is activated, and the flow LED is turned on.
If there is flow, the water level and flow rate are checked to see if the pump needs to be turned off.
Once the required condition is met, the Ticker is detached to stop checking the flow.*/

#include <Ticker.h>
#include "INA3221Controller.h"
#include "PumpController.h"
#include "MCP23017Controller.h"

class WaterFlowChecker
{
public:
	WaterFlowChecker(INA3221Controller &ina, PumpController &pump, MCP23017Controller &mcp)
		: ina(ina), pump(pump), mcp(mcp) {}
	void begin()
	{
		ticker.attach(1, &WaterFlowChecker::checkFlow, this);
	}

private:
	INA3221Controller &ina;
	PumpController &pump;
	MCP23017Controller &mcp;
	Ticker ticker;
	void checkFlow()
	{
		float waterFlow = ina.WaterFlow();
		if (waterFlow == 0)
		{
			pump.TurnOff();
			mcp.AlarmRelay(true);
			mcp.FlowLed(1);
			ticker.detach();
		}
		else
		{
			float waterLevel = ina.WaterLevel();
			if (waterLevel < 500 || waterFlow < 0)
			{
				pump.TurnOff();
				mcp.FlowLed(0);
				ticker.detach();
			}
		}
	}
};
