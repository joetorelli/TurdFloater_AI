
#include "OLEDMenu.h"

OLEDMenu::OLEDMenu()
{
	_itemCount = 0;
}

void OLEDMenu::addItem(const char *label)
{
	if (_itemCount < MENU_MAX_ITEMS)
	{
		_items[_itemCount++] = label;
	}
}

void OLEDMenu::begin()
{
	_display.begin(SSD1306_SWITCHCAPVCC, OLED_RESET);
	_display.clearDisplay();
	_display.display();
}

void OLEDMenu::draw(int16_t position)
{
	_display.clearDisplay();
	_display.setTextSize(1);
	_display.setTextColor(MENU_ITEM_SELECTED_COLOR);
	for (uint8_t i = 0; i < _itemCount; i++)
	{
		int16_t y = i *

		// MenuController.cpp

#include "MenuController.h"

					MenuController::MenuController(Adafruit_SSD1306 * display, Encoder * encoder)
		{
			_display = display;
			_encoder = encoder;
			_menuItems = 3; // number of menu items
			_selectedItem = 0;
			_encoderPosition = 0;
		}

		void MenuController::init()
		{
			_display->clearDisplay();
			_display->setTextSize(1);
			_display->setCursor(0, 0);
			_display->println("Menu:");
			drawMenu();
			_display->display();
		}

		void MenuController::run()
		{
			handleEncoder();
		}

		void MenuController::drawMenu()
		{
			_display->setTextColor(WHITE);
			_display->setCursor(10, 20);
			_display->println("Item 1");
			_display->setCursor(10, 30);
			_display->println("Item 2");
			_display->setCursor(10, 40);
			_display->println("Item 3");
		}

		void MenuController::handleEncoder()
		{
			int newPosition = _encoder->read();
			if (newPosition != _encoderPosition)
			{
				_encoderPosition = newPosition;
				int item = _encoderPosition / 4 % _menuItems;
				if (item != _selectedItem)
				{
					_selectedItem = item;
					_display->clearDisplay();
					_display->setTextSize(1);
					_display->setCursor(0, 0);
					_display->println("Menu:");
					drawMenu();
					_display->fillRect(0, _selectedItem * 10 + 20, 128, 10, WHITE);
					_display->display();
				}
			}
		}

	/*This code defines a MenuController class with methods to initialize and run the menu system.
	The constructor takes pointers to the OLED display and the encoder. The init method sets up the
	initial display and draws the menu items. The run method is called repeatedly to check for encoder changes.
	The drawMenu method draws the menu items on the display, and the handleEncoder method checks for changes in
	the encoder position and updates the display and selected item accordingly.*/
