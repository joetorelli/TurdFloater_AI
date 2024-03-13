/*
changed ticker. see esp32_tickertwo/tickertwo
 */

#include "INA3221Controller.h"
#include "PumpController.h"
#include "FlowSwitchController.h"
#include "MCP23017Controller.h"
#include "WaterFlowChecker.h"

INA3221Controller SensorIF;
PumpController pump;
MCP23017Controller mcp;
WaterFlowChecker flowChecker(SensorIF, pump, mcp);
// Create an instance of the FlowSwitchController class
FlowSwitchController flowSwitch();

// Create a Ticker object to turn off the pump after 1 second
Ticker pumpOffTimer;
bool shouldTurnOffPump = false;

void setup()
{
  SensorIF.init();
  pump.init();
  mcp.init();
}

void loop()
{

  // Read the water flow using the WaterFlow method
  float waterFlow = SensorIF.WaterFlow();

  // Read the chlorine level using the ChlorineLevel method
  float chlorineLevel = SensorIF.ChlorineLevel();
  // Read the water level using the WaterLevel method

  float waterLevel = SensorIF.WaterLevel();
  if (waterLevel >= 2000)
  {
    pump.turnOn();
    flowChecker.begin(); // start checking flow
  }

  /*This code will start the Ticker object to turn off the pump after 1 second,
  and then wait for the pump to run and check the flow switch. If the flow switch is not active,
  the pump will be turned off, the alarm relay will be set, and the Ticker object will be stopped.
  If the pump has not been turned off already, it will be turned off after the Ticker object triggers.
  Finally, the flag is reset to allow the code to repeat the process.*/

  // Start the Ticker to turn off the pump after 1 second
  pumpOffTimer.Once(1, {shouldTurnOffPump = true});

  // Wait for the pump to run and check if the flow switch is active
  while (!shouldTurnOffPump)
  {
    // Check if the flow switch is active
    if (!flowSwitch.isActive())
    { // Turn off the pump relay and set alarm relay
      pumpRelay(false);
      alarmRelay(true);
      mcp.AutoLed(0);
      mcp.AirLed(0);
      mcp.FlowLed(1);
      mcp.CL(0);
      mcp.AlarmLed(1);
      mcp.Remote(0);

      // Stop the Ticker and exit the loop
      pumpOffTimer.detach();
      break;
    }

    // Do other tasks while waiting for the pump to run
    // ...
  }

  // Turn off the pump if it hasn't been turned off already
  if (!shouldTurnOffPump)
  {
    pumpRelay(false);
  }

  // Reset the flag
  shouldTurnOffPump = false;
}