#include "TankMonitor.h"

#define WATER_LEVEL_SENSOR_SHUNT_VALUE 0.01f  // 10mOhm
#define WATER_LEVEL_SENSOR_MAX_CURRENT 0.020f // 20mA

// TankMonitor::TankMonitor(pumpPin(PUMP_PIN), _waterLevelSensor(0x40))
// {
// 	_pumpPin = PUMP_PIN;
// }

// void TankMonitor::begin()
// {
// 	// Initialize pump pin
// 	pinMode(_pumpPin, OUTPUT);
// 	digitalWrite(_pumpPin, LOW);

// 	// Initialize INA3221
// 	_waterLevelSensor.begin();
// 	_waterLevelSensor.setCalibration_320V_1A(WATER_LEVEL_SENSOR_SHUNT_VALUE, WATER_LEVEL_SENSOR_MAX_CURRENT);
// }

float TankMonitor::readWaterLevel()
{
	// Read the voltage across the shunt resistor
	float shuntVoltage = _waterLevelSensor.getBusVoltage_V(1);

	// Calculate the current flowing through the sensor
	float current = shuntVoltage / WATER_LEVEL_SENSOR_SHUNT_VALUE;

	// Map the current to a level percentage
	float levelPercentage = map(current, 4.0f, 20.0f, 0.0f, 100.0f);
	levelPercentage = constrain(levelPercentage, 0.0f, 100.0f);

	return levelPercentage;
}

void TankMonitor::turnOnPump()
{
	digitalWrite(_pumpPin, HIGH);
}

void TankMonitor::turnOffPump()
{
	digitalWrite(_pumpPin, LOW);
}
void TankMonitor::handleFlowSwitch()
{
	if (digitalRead(flowSwitchPin) == LOW)
	{
		Serial.println("Water flow detected.");
	}
	else
	{
		Serial.println("No water flow detected. Turning off pump.");
		digitalWrite(_pumpPin, LOW);
		pumpOn = false;
	}
}

/*#include "TankMonitor.h"

TankMonitor::TankMonitor(int relayPin, int flowSwitchPin, int waterLevelPin) {
  // Initialize the relay pin
  _relayPin = relayPin;
  pinMode(_relayPin, OUTPUT);
  turnOffPump();

  // Initialize the flow switch pin
  _flowSwitchPin = flowSwitchPin;
  pinMode(_flowSwitchPin, INPUT_PULLUP);
  _flowSwitchState = false;

  // Initialize the water level pin
  _waterLevelPin = waterLevelPin;
  pinMode(_waterLevelPin, INPUT);
  _waterLevelValue = 0;
}

void TankMonitor::turnOnPump() {
  digitalWrite(_relayPin, HIGH);
  _pumpState = true;
}

void TankMonitor::turnOffPump() {
  digitalWrite(_relayPin, LOW);
  _pumpState = false;
}

void TankMonitor::readWaterLevel() {
  // Read the water level value from the INA3221 channel 1
  _waterLevelValue = analogRead(_waterLevelPin);
}

void TankMonitor::handleFlowSwitch() {
  // Check if the flow switch is open
  if (digitalRead(_flowSwitchPin) == LOW) {
	// Flow switch is closed
	if (!_flowSwitchState) {
	  // Pump has just been turned on
	  _flowSwitchState = true;
	  _startTime = millis();
	}
	else {
	  // Pump has been on for at least 1 second
	  if (millis() - _startTime >= 1000) {
		// Check if there is flow
		if (digitalRead(_flowSwitchPin) == LOW) {
		  // No flow detected
		  turnOffPump();
		  Serial.println("Warning: No flow detected!");
		}
	  }
	}
  }
  else {
	// Flow switch is open
	_flowSwitchState = false;
  }
}

bool TankMonitor::isPumpOn() {
  return _pumpState;
}

int TankMonitor::getWaterLevel() {
  return _waterLevelValue;
}
*/