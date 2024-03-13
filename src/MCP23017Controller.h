#ifndef MCP23017_CONTROLLER_H
#define MCP23017_CONTROLLER_H

class MCP23017Controller
{
public:
	MCP23017Controller();
	void init();
	void PumpRelay(bool State);
	void AlarmRelay(bool State);
	void AutoLed(int State);
	void AirLed(int State);
	void FlowLed(int State);
	void CLLed(int State);
	void AlarmLed(bool State);
	void Remote(bool State);

private:
	Adafruit_MCP23X17 mcp;
};

#endif

/*Great, to use your MCP23017Controller class in your main function, you will need to do the following:

Include the necessary header files in your main file:

#include <Wire.h>
#include <Adafruit_MCP23X17.h>
#include "MCP23017Controller.h"

Declare an instance of your MCP23017Controller class:

MCP23017Controller mcpController;

Call the init() method of your MCP23017Controller object in the setup() function:

void setup() {
  // initialize I2C bus and MCP23017
  Wire.begin();
  mcpController.init();
}

Call the other methods of your MCP23017Controller object as needed in the loop() function:

void loop() {
  // turn on pump relay
  mcpController.PumpRelay(true);

  // add delay for stability
  delay(1000);

  // turn off pump relay
  mcpController.PumpRelay(false);

  // add delay for stability
  delay(1000);
}
Of course, you will need to modify the code above to suit your specific needs,
but this should give you an idea of how to use your MCP23017Controller class in your main file.*/