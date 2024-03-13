/*This implementation uses the Adafruit_SSD1306 library to interface with the OLED display.
The init() method initializes the display, clear() clears the display, and print() prints a message to the display.*/

#include "OLEDController.h"

OLEDController::OLEDController() : _display(128, 64, &Wire, -1)
{
}

void OLEDController::init()
{
	_display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
	_display.clearDisplay();
}

void OLEDController::clear()
{
	_display.clearDisplay();
	_display.display();
}

void OLEDController::print(const char *message)
{
	_display.setTextSize(1);
	_display.setTextColor(WHITE);
	_display.setCursor(0, 0);
	_display.println(message);
	_display.display();
}

void OLEDController::print(int number)
{
	_display.setTextSize(1);
	_display.setTextColor(WHITE);
	_display.setCursor(0, 0);
	_display.println(number);
	_display.display();
}

#include "SSD1327Display.h"

SSD1327Display::SSD1327Display(uint8_t sdaPin, uint8_t sclPin, uint8_t rstPin) : _display(128, 128, &Wire, -1, rstPin)
{
	_display.begin(SSD1327_SWITCHCAPVCC, 0x3C);
	Wire.setPins(sdaPin, sclPin);
}

void SSD1327Display::begin()
{
	_display.begin(SSD1327_SWITCHCAPVCC, 0x3C);
}

void SSD1327Display::clearDisplay()
{
	_display.clearDisplay();
}

void SSD1327Display::displayText(const char *text, uint8_t size, uint8_t x, uint8_t y)
{
	_display.setTextSize(size);
	_display.setCursor(x, y);
	_display.println(text);
	_display.display();
}

#include "SSD1327Controller.h"

// Constructor
SSD1327Controller::SSD1327Controller(int16_t width, int16_t height, uint8_t address) : display(width, height, &Wire, -1, address) {}

// Initialize display
void SSD1327Controller::init()
{
	display.begin(SSD1327_SWITCHCAPVCC);
	display.clearDisplay();
	display.display();
}

// Clear the display
void SSD1327Controller::clearDisplay()
{
	display.clearDisplay();
}

// Display text on the screen
void SSD1327Controller::displayText(const char *text, int16_t x, int16_t y, uint16_t textSize, uint16_t textColor, uint16_t bgColor)
{
	display.setCursor(x, y);
	display.setTextSize(textSize);
	display.setTextColor(textColor, bgColor);
	display.print(text);
	display.display();
}

// Display an image on the screen
void SSD1327Controller::displayImage(const uint8_t *image, int16_t x, int16_t y, int16_t width, int16_t height)
{
	display.drawBitmap(x, y, image, width, height, SSD1327_WHITE);
	display.display();
}
