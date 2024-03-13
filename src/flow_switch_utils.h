#ifndef FLOW_SWITCH_UTILS_H
#define FLOW_SWITCH_UTILS_H

#include <Arduino.h>
#include <Ticker.h>

void readFlowSwitch()
{
	static bool first_read = true;		// Flag to delay the first reading
	static bool ticker_started = false; // Flag to check if the Ticker is already started
	Ticker ticker;						// Create a Ticker object
	int interval_ms = 1000;				// Set the interval in milliseconds
	if (first_read)
	{
		if (digitalRead(RELAY_PIN) == HIGH)
		{												   // If the relay is on
			first_read = false;							   // Clear the flag to start reading the flow switch
			ticker_started = true;						   // Set the flag to indicate the Ticker is started
			ticker.attach_ms(interval_ms, readFlowSwitch); // Attach the Ticker to call readFlowSwitch() function every 1 second
		}
	}
	else
	{
		int flow_switch_state = digitalRead(FLOW_SWITCH_PIN); // Read the state of the flow switch
		if (flow_switch_state == LOW)
		{											  // If the flow switch is activated
			Serial.println("Flow switch activated!"); // Print a message indicating the flow switch is activated
		}
	}
	if (digitalRead(RELAY_PIN) == LOW && ticker_started)
	{							// If the relay is turned off and the Ticker is started
		ticker.detach();		// Detach the Ticker to stop calling readFlowSwitch() function
		ticker_started = false; // Clear the flag to indicate the Ticker is stopped
	}
}

#endif
