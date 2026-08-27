#include "Airbag.h"
#include <iostream>

Airbag::Airbag() : is_activate_(false) {

}

void
Airbag::activate() {
	is_activate_ = true;
}

void
Airbag::run() {
	if (is_activate_) {
		std::cout << "AirBag Activated \n";
	}
}