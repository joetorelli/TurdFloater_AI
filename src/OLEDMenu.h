

#ifndef OLED_MENU_H
#define OLED_MENU_H

#include <Adafruit_SSD1306.h>

#define OLED_WIDTH 128
#define OLED_HEIGHT 32
#define OLED_RESET 16
#define MENU_MAX_ITEMS 10
#define MENU_ITEM_WIDTH 12
#define MENU_ITEM_HEIGHT 10
#define MENU_ITEM_PADDING 3
#define MENU_ITEM_SELECTED_COLOR WHITE
#define MENU_ITEM_UNSELECTED_COLOR BLACK
#define MENU_INDICATOR_SIZE 4

class OLEDMenu
{
public:
	OLEDMenu();

	void addItem(const char *label);

	void begin();

	void draw(int16_t position);

	int16_t select();

private:
	Adafruit_SSD1306 _display;
	uint8_t _itemCount;
	const char *_items[MENU_MAX_ITEMS];
};

#endif

// MenuController.h

#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Encoder.h>

class MenuController
{
public:
	MenuController(Adafruit_SSD1306 *display, Encoder *encoder);
	void init();
	void run();

private:
	Adafruit_SSD1306 *_display;
	Encoder *_encoder;
	int _menuItems;
	int _selectedItem;
	int _encoderPosition;
	void drawMenu();
	void handleEncoder();
};

#endif