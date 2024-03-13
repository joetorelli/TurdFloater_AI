#include "FlowSwitchController.h"

FlowSwitchController::FlowSwitchController(INA3221 &ina) : ina_(ina) {}

void FlowSwitchController::init()
{
	// Initialize the INA3221 channel for the flow switch
	ina_.setConfig(2, INA3221_CONFIG_ENABLE_CHAN, INA3221_CONFIG_AVG128, INA3221_CONFIG_VBUS_CONTINUOUS, INA3221_CONFIG_GAIN_1_40MV, INA3221_CONFIG_BADCRES_12BIT, INA3221_CONFIG_SADCRES_12BIT, INA3221_CONFIG_MODE_SANDBVOLT_CONTINUOUS);
}

bool FlowSwitchController::isActive()
{
	// Read the voltage on the flow switch channel
	float voltage = ina_.getBusVoltage_V(2);

	// Check if the voltage is above a threshold to consider the flow switch active
	return voltage > 0.5f; // Change this threshold value as needed
}
