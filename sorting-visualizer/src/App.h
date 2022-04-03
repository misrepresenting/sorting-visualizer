#pragma once

#include <SFML/Graphics.hpp>
#include "Column.h"
#include "Constants.h"

// class that acts as the main application
class app {
	// variables
	sf::RenderWindow m_window; // already constructed?
	sf::VideoMode m_video_mode;
	column* m_columns;

	//functions
	void init_columns();
	void draw_columns();
	void swap_columns(int i, int j);

	void render();
	void poll_events();
public:
	// constructor
	app();

	// functions
	void update();
	bool is_open();
};