#include "Relay_Utils.h"

Relay_Utils::Relay_Utils(uint8_t relay_pin)
{
	pinMode(relay_pin, OUTPUT);
	_relay_pin = relay_pin;
	turnOff();
}

void Relay_Utils::turnOn()
{
	digitalWrite(_relay_pin, HIGH);
}

void Relay_Utils::turnOff()
{
	digitalWrite(_relay_pin, LOW);
}
/* void turnOnRelay(int relay_pin, Ticker &ticker)
{
	digitalWrite(relay_pin, HIGH);		// Set the relay pin to HIGH to turn on the relay
	ticker.attach(1.0, readFlowSwitch); // Attach the Ticker to call readFlowSwitch() function every 1 second
}

void turnOffRelay(int relay_pin, Stream &serial, Ticker &ticker)
{
	digitalWrite(relay_pin, LOW); // Set the relay pin to LOW to turn off the relay
	ticker.detach();			  // Detach the Ticker to stop calling readFlowSwitch() function
	if (digitalRead(FLOW_SWITCH_PIN) == LOW)
	{											  // If the flow switch is activated
		serial.println("Flow switch activated!"); // Print a message indicating the flow switch is activated
	}
} */