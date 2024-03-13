#include "INA3221Controller.h"
#include <Wire.h>
#include <INA3221.h>

INA3221Controller::INA3221Controller() : ina(INA3221_ADDR40_GND) {}

void INA3221Controller::init()
{
	Wire.begin();
	ina.begin();
	/// ina.begin(&Wire);
	ina.reset();
	ina.setShuntRes(10, 10, 10);
}

float INA3221Controller::WaterLevel()
{
	// ina.getCurrent(INA3221_CH1) * 1000,

	return ina.getCurrent(INA3221_CH1) / 1000.0;
	;
}

float INA3221Controller::WaterFlow()
{
	return ina.getCurrent(INA3221_CH2) / 1000.0;
}

float INA3221Controller::ChlorineLevel()
{
	return ina.getCurrent(INA3221_CH3) / 1000.0;
}

/*
this is the main for mpc and ina controller files


#include <WiFi.h>
#include "MCP23017Controller.h"
#include "INA3221Controller.h"

#define WIFI_SSID "your_wifi_ssid"
#define WIFI_PASSWORD "your_wifi_password"

#define MCP_ADDRESS 0x20
#define PUMP_RELAY_PIN 0
#define PUMP_LED_PIN 1
#define FAULT_LED_PIN 2

MCP23017Controller mcp;
INA3221Controller ina;

const float WATER_LEVEL_TURN_ON = 10.0; // in volts
const float WATER_LEVEL_TURN_OFF = 5.0; // in volts
const float CHLORINE_LEVEL_TURN_ON = 5.0; // in volts
const float CHLORINE_LEVEL_TURN_OFF = 10.0; // in volts

void setup() {
  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
	delay(1000);
  }

  mcp.init();
  ina.init();

  mcp.setPumpRelay(false);
  mcp.setPumpLed(false);
  mcp.setFaultLed(false);
}

void loop() {
  float waterLevel = ina.getBusVoltage_WaterLevel(WATER_LEVEL_CHANNEL);
  float waterFlow = ina.getCurrent_WaterFlow(WATER_FLOW_CHANNEL);
  float chlorineLevel = ina.getBusVoltage_Chlorine(CHLORINE_CHANNEL);

  if (waterLevel >= WATER_LEVEL_TURN_ON) {
	mcp.setPumpRelay(true);
	delay(1000);
	if (waterFlow == 0) {
	  mcp.setPumpRelay(false);
	  mcp.setFaultLed(true);
	  Serial.println("Warning: no water flow detected");
	  delay(5000);
	  mcp.setFaultLed(false);
	} else {
	  while (waterLevel >= WATER_LEVEL_TURN_OFF) {
		waterLevel = ina.getBusVoltage_WaterLevel(WATER_LEVEL_CHANNEL);
	  }
	  mcp.setPumpRelay(false);
	}
  }

  if (chlorineLevel <= CHLORINE_LEVEL_TURN_ON) {
	mcp.setFaultLed(true);
	Serial.println("Warning: low chlorine level detected");
	delay(5000);
	mcp.setFaultLed(false);
  }

  delay(1000);
}
*/
