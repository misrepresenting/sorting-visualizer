#include "App.h"

int main() {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	app application;

	while (application.is_open()) {
		application.update(); // render is handled in update (calls render each time we sort (loop is just to keep app open)
	}

	// make loop thats only for sorting

	return 0;
}
