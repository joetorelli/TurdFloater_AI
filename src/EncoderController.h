/*This class has a constructor that takes three pins: one for the A channel of the encoder, one for the B channel of the encoder,
 and one for the push button. It also has methods to initialize the encoder and update its state,
 as well as methods to get the current position and button state.*/

#ifndef ENCODERCONTROLLER_H
#define ENCODERCONTROLLER_H

#include <AiEsp32RotaryEncoder.h>

class EncoderController
{
public:
	EncoderController(int pinA, int pinB, int pinButton);

	void begin();
	void loop();

	int32_t getPosition() const;
	bool getButtonState() const;

private:
	int _pinA;
	int _pinB;
	int _pinButton;
	AiEsp32RotaryEncoder _encoder;
	volatile int32_t _position;
	volatile bool _buttonState;
};

#endif

class EncoderController
{
public:
	EncoderController(int pinA, int pinB, int pinButton);
	void init();
	void update();

	int getPosition();
	bool isButtonPressed();

private:
	int _pinA;
	int _pinB;
	int _pinButton;
	int _position;
	bool _buttonPressed;
};

#ifndef ROTARYENCODER_H
#define ROTARYENCODER_H

#include <Arduino.h>

class RotaryEncoder
{
public:
	RotaryEncoder(uint8_t pinA, uint8_t pinB, uint8_t buttonPin);

	int16_t read();

	bool buttonPressed();

private:
	uint8_t _pinA;
	uint8_t _pinB;
	uint8_t _buttonPin;
	uint8_t _lastState;
	bool _lastButtonState;
	int16_t _position;
};

#endif