#include "MCP23017Controller.h"
#include <Adafruit_MCP23X17.h>

#define MCP_ADDRESS 0x20
#define AutoGrnPin 0
#define AutoRedPin 1
#define FlowGrnPin 2
#define FlowRedPin 3
#define AirGrnPin 4
#define AirRedPin 5
#define CLGrnPin 6
#define CLRedPin 7
#define AlarmPin 8
#define RemotePin 9
#define PumpRelayPin 10
#define AlarmRelayPin 11

MCP23017Controller::MCP23017Controller() : mcp() {}

void CLLed(int State);

void MCP23017Controller::init()
{
	mcp.begin_I2C(MCP_ADDRESS);
	// set pin modes for all pins
	for (int i = 0; i < 16; i++)
	{
		mcp.pinMode(i, OUTPUT);
	}
	// mcp.pinMode(AutoGrnPin, OUTPUT);
	// mcp.pinMode(AutoRedPin, OUTPUT);
	// mcp.pinMode(FlowGrnPin, OUTPUT);
	// mcp.pinMode(FlowRedPin, OUTPUT);
	// mcp.pinMode(AirGrnPin, OUTPUT);
	// mcp.pinMode(AirRedPin, OUTPUT);
	// mcp.pinMode(CLGrnPin, OUTPUT);
	// mcp.pinMode(CLRedPin, OUTPUT);
	// mcp.pinMode(AlarmPin, OUTPUT);
	// mcp.pinMode(RemotePin, OUTPUT);
}

void MCP23017Controller::PumpRelay(bool State)
{
	mcp.digitalWrite(PumpRelayPin, State ? HIGH : LOW);
}

void MCP23017Controller::AlarmRelay(bool State)
{
	mcp.digitalWrite(AlarmRelayPin, State ? HIGH : LOW);
}

void MCP23017Controller::AlarmLed(bool State)
{
	mcp.digitalWrite(AlarmPin, State ? HIGH : LOW);
}

void MCP23017Controller::Remote(bool State)
{
	mcp.digitalWrite(RemotePin, State ? HIGH : LOW);
}

void MCP23017Controller::AutoLed(int State)
{
	// mcp.digitalWrite(RemotePin, on ? HIGH : LOW);
	switch (State)
	{
	case 0: // off
		mcp.digitalWrite(AutoGrnPin, LOW);
		mcp.digitalWrite(AutoRedPin, LOW);

		break;
	case 1: // grn
		mcp.digitalWrite(AutoGrnPin, HIGH);
		mcp.digitalWrite(AutoRedPin, LOW);

		break;
	case 2: // red
		mcp.digitalWrite(AutoGrnPin, LOW);
		mcp.digitalWrite(AutoRedPin, HIGH);

		break;
	default:
		// do something
	}
}

void MCP23017Controller::CLLed(int State)
{
	// mcp.digitalWrite(RemotePin, on ? HIGH : LOW);
	switch (State)
	{
	case 0: // off
		mcp.digitalWrite(CLGrnPin, LOW);
		mcp.digitalWrite(CLRedPin, LOW);

		break;
	case 1: // grn
		mcp.digitalWrite(CLGrnPin, HIGH);
		mcp.digitalWrite(CLRedPin, LOW);

		break;
	case 2: // red
		mcp.digitalWrite(CLGrnPin, LOW);
		mcp.digitalWrite(CLRedPin, HIGH);

		break;
	default:
		// do something
	}
}

void MCP23017Controller::AirLed(int State)
{
	// mcp.digitalWrite(RemotePin, on ? HIGH : LOW);
	switch (State)
	{
	case 0: // off
		mcp.digitalWrite(AirGrnPin, LOW);
		mcp.digitalWrite(AirRedPin, LOW);

		break;
	case 1: // grn
		mcp.digitalWrite(AirGrnPin, HIGH);
		mcp.digitalWrite(AirRedPin, LOW);

		break;
	case 2: // red
		mcp.digitalWrite(AirGrnPin, LOW);
		mcp.digitalWrite(AirRedPin, HIGH);

		break;
	default:
		// do something
	}
}

void MCP23017Controller::FlowLed(int State)
{
	// mcp.digitalWrite(RemotePin, on ? HIGH : LOW);
	switch (State)
	{
	case 0: // off
		mcp.digitalWrite(FlowGrnPin, LOW);
		mcp.digitalWrite(FlowRedPin, LOW);

		break;
	case 1: // grn
		mcp.digitalWrite(FlowGrnPin, HIGH);
		mcp.digitalWrite(FlowRedPin, LOW);

		break;
	case 2: // red
		mcp.digitalWrite(FlowGrnPin, LOW);
		mcp.digitalWrite(FlowRedPin, HIGH);

		break;
	default:
		// do something
	}
}