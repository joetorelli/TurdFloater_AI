#ifndef FLOW_SWITCH_CONTROLLER_H
#define FLOW_SWITCH_CONTROLLER_H

#include <INA3221.h>

class FlowSwitchController
{
public:
	FlowSwitchController(INA3221 &ina);
	void init();
	bool isActive();

private:
	INA3221 &ina_;
};

#endif // FLOW_SWITCH_CONTROLLER_H
