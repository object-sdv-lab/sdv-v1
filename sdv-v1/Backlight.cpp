#include "Backlight.h"
#include <iostream>

Backlight::Backlight() : is_on_(false) { }

void
Backlight::turn_on() {
	is_on_ = true;
}

void
Backlight::turn_off() {
	is_on_ = false;
}

void
Backlight::run() {
	if (is_on_) {
		std::cout << "Backlight ON \n";
	}
	else {
		std::cout << "Backlight OFF \n";
	}
}