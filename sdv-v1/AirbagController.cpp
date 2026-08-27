#include "AirbagController.h"

AirbagController::AirbagController(Airbag* airbag) : airbag_(airbag) { }

void
AirbagController::on_event(const int& event) {
	if (event == 0) {
		airbag_->activate();
	}
}