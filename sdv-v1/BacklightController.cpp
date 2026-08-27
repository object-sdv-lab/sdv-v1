#include "BacklightController.h"

BacklightController::BacklightController(Backlight* backlight): backlight_(backlight){ }

void
BacklightController::on_event(const int& event) {
	if (event < 10) {
		backlight_->turn_on();
	}
}