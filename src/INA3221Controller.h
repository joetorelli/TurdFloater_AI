#ifndef INA3221_CONTROLLER_H
#define INA3221_CONTROLLER_H

class INA3221Controller
{
public:
	INA3221Controller();
	void init();
	float WaterLevel();
	float WaterFlow();
	float ChlorineLevel();

private:
	INA3221 ina;
};

#endif

/*To use your INA3221Controller class in your main.cpp file, you need to create an instance of the class.
You can do this by including the header file for the INA3221Controller class at the top of your main.cpp
file and then creating an instance of the class, like so:

#include "INA3221Controller.h"

// Create an instance of the INA3221Controller class
INA3221Controller inaController;

You can then call the methods of the INA3221Controller class using the instance you just created, like so:

// Call the init method to initialize the INA3221
inaController.init();

// Read the water level using the WaterLevel method
float waterLevel = inaController.WaterLevel();

// Read the water flow using the WaterFlow method
float waterFlow = inaController.WaterFlow();

// Read the chlorine level using the ChlorineLevel method
float chlorineLevel = inaController.ChlorineLevel();
Note that you will need to make sure that the INA3221 library is properly installed and included in your project,
 and that the necessary header files are included in your INA3221Controller.h and INA3221Controller.cpp files.*/