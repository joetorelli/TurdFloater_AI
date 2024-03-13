/*This class has a constructor that initializes the OLED display,
as well as methods to clear the display and print messages to it.*/

#include <Adafruit_SSD1306.h>

class OLEDController
{
public:
	OLEDController();
	void init();
	void clear();
	void print(const char *message);
	void print(int number);

private:
	Adafruit_SSD1306 _display;
};

/*Here's a brief explanation of what's going on in the code:

The SSD1327Display class is defined in the SSD1327Display.h file, which includes the necessary headers and function declarations.
The constructor for the SSD1327Display class takes three arguments: sdaPin, sclPin, and rstPin. These are used to configure
 the I2C interface and reset pin for the display.
The begin() method initializes the display by calling the begin() method of the Adafruit_SSD1327 class.
The clearDisplay() method clears the display by calling the clearDisplay() method of the Adafruit_SSD1327 class.
The displayText() method displays text on the screen by setting the text size, cursor position, printing the text,
and then calling the display() method of the Adafruit_SSD1327 class to update the display.
*/

#ifndef SSD1327Display_h
#define SSD1327Display_h

#include <Adafruit_SSD1327.h>

class SSD1327Display
{
public:
	SSD1327Display(uint8_t sdaPin, uint8_t sclPin, uint8_t rstPin);
	void begin();
	void clearDisplay();
	void displayText(const char *text, uint8_t size, uint8_t x, uint8_t y);

private:
	Adafruit_SSD1327 _display;
};

#endif
