#include "WiperActuator.h"
#include <iostream>

using namespace std;

WiperActuator::WiperActuator() : wiper_speed_(WiperSpeed::OFF) {};

void WiperActuator::update(WiperSpeed wiper_speed) {
	this->wiper_speed_ = wiper_speed;
	run();
}

void WiperActuator::run() {
	switch (wiper_speed_)
	{
	case WiperSpeed::OFF:
		cout << "Wiper state: OFF\n";
		break;
	case WiperSpeed::Low:
		cout << "Wiper state: Move low speed\n";
		break;
	case WiperSpeed::Mid:
		cout << "Wiper state: Move middle speed\n";
		break;
	case WiperSpeed::High:
		cout << "Wiper state: Move high speed\n";
		break;
	default:
		cout << "Wiper state: OFF\n";
	}
}