/*In this example, the EncoderController class takes three constructor arguments: the pins for
the quadrature encoder's A and B channels, and the pin for the push button. The class initializes an
AiEsp32RotaryEncoder object using these pins, and sets up the encoder's boundaries, button handling, and loop function.

The begin function is called in the setup function of your main sketch to initialize the pins
and setup the encoder. The loop function should be called in the main loop function of your sketch
to update the encoder's position and button state.

The getPosition function returns the current position of the encoder, while the getButtonState
function returns the current state of the push button.
*/

#include "EncoderController.h"

EncoderController::EncoderController(int pinA, int pinB, int pinButton)
	: _pinA(pinA), _pinB(pinB), _pinButton(pinButton), _encoder(AiEsp32RotaryEncoder(_pinA, _pinB)) {}

void EncoderController::begin()
{
	pinMode(_pinButton, INPUT_PULLUP);

	_encoder.begin();
	_encoder.setup([]
				   { return digitalRead(_pinA); },
				   []
				   { return digitalRead(_pinB); },
				   []
				   { return digitalRead(_pinButton); });
	_encoder.setBoundaries(-100, 100, true);
}

void EncoderController::loop()
{
	_encoder.loop();
	_position = _encoder.getPosition();
	_buttonState = _encoder.getButton();
}

int32_t EncoderController::getPosition() const
{
	return _position;
}

bool EncoderController::getButtonState() const
{
	return _buttonState;
}

#include "EncoderController.h"
#include <Encoder.h>

EncoderController::EncoderController(int pinA, int pinB, int pinButton)
	: _pinA(pinA), _pinB(pinB), _pinButton(pinButton), _position(0), _buttonPressed(false)
{
}

void EncoderController::init()
{
	pinMode(_pinButton, INPUT_PULLUP);
}

void EncoderController::update()
{
	static Encoder encoder(_pinA, _pinB);
	int newPosition = encoder.read();
	if (newPosition != _position)
	{
		_position = newPosition;
	}
	_buttonPressed = !digitalRead(_pinButton);
}

int EncoderController::getPosition()
{
	return _position;
}

bool EncoderController::isButtonPressed()
{
	return _buttonPressed;
}

#include "RotaryEncoder.h"

RotaryEncoder::RotaryEncoder(uint8_t pinA, uint8_t pinB, uint8_t buttonPin)
{
	_pinA = pinA;
	_pinB = pinB;
	_buttonPin = buttonPin;

	pinMode(_pinA, INPUT_PULLUP);
	pinMode(_pinB, INPUT_PULLUP);
	pinMode(_buttonPin, INPUT_PULLUP);

	_lastState = digitalRead(_pinA);
	_position = 0;
}

int16_t RotaryEncoder::read()
{
	uint8_t state = digitalRead(_pinA);
	if (state != _lastState)
	{
		if (digitalRead(_pinB) != state)
		{
			_position++;
		}
		else
		{
			_position--;
		}
	}
	_lastState = state;
	return _position;
}

bool RotaryEncoder::buttonPressed()
{
	bool buttonState = digitalRead(_buttonPin);
	bool result = false;
	if (buttonState != _lastButtonState)
	{
		delay(50);
		if (buttonState == LOW)
		{
			result = true;
		}
	}
	_lastButtonState = buttonState;
	return result;
}
