/*This is the header file for the TankMonitor class. It includes the necessary libraries and defines the class
and its public and private members.

The private members include the pin numbers for the pump, water level sensor, and flow switch, the turn on
and turn off water level thresholds, the maximum pump runtime, an instance of the Adafruit_INA3221 class to interface
with the INA3221 sensor, a Ticker object to handle the flow switch polling, and various other state variables used
for monitoring the system.

The public members include the constructor for the class, a setup method, a loop method, and methods to turn the
pump on or off and read the water level.

Overall, this header file defines the interface for the TankMonitor class and its underlying implementation details.*/

// #ifndef TANK_MONITOR_H
// #define TANK_MONITOR_H

// #include <Arduino.h>
// #include <Wire.h>
// #include "INA3221.h"
// #include <Ticker.h>

#ifndef TankMonitor_h
#define TankMonitor_h

#include <Arduino.h>
#include <Wire.h>
#include "INA3221.h"
#include <Ticker.h>

class TankMonitor
{
private:
	int _pumpPin;
	int _levelPin;
	int flowSwitchPin;
	int _turnOnLevel;
	int _turnOffLevel;
	int _maxPumpRuntime;
	// SDL_Arduino_INA3221 _ina3221;
	Ticker _flowSwitchTicker;
	bool _flowSwitchState;
	SDL_Arduino_INA3221 _waterLevelSensor;
	bool _pumpState;
	bool _pumpAutoState;
	unsigned long _pumpStartTime;
	void checkPumpAutoState();
	void handleFlowSwitch();

public:
	TankMonitor(int pumpPin, int levelPin, int flowPin, int turnOnLevel, int turnOffLevel, int maxPumpRuntime);
	void setup();
	void loop();
	void turnOnPump();
	void turnOffPump();
	float readWaterLevel();
};

#endif

/* class TankMonitor
{
public:
	TankMonitor(int pumpPin, int flowSwitchPin, int waterLevelSensorPin, int turnOnLevel, int turnOffLevel, int minLevel, int maxLevel);
	void init();
	void run();

private:
	SDL_Arduino_INA3221 ina3221;
	Ticker flowSwitchTicker;
	int pumpPin;
	int flowSwitchPin;
	int waterLevelSensorPin;
	int turnOnLevel;
	int turnOffLevel;
	int minLevel;
	int maxLevel;
	bool pumpOn;
	unsigned long flowSwitchStartMillis;
	bool flowSwitchTimerStarted;
	bool flowSwitchOn;
	bool tankDraining;
	float waterLevelPercentage;
	void readWaterLevel();
	void handleWaterLevel();
	void handlePump();
	void handleFlowSwitch();
	void turnPumpOn();
	void turnPumpOff();
};

#endif*/
