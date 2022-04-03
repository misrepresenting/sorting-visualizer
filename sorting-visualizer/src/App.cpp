#include "App.h" // catch certain errors at compile time instead of linker
#include <iostream>
#include <chrono>
#include <thread>
#include <algorithm>

// constructors
app::app() : m_video_mode(600, 400) {
	m_window.create(m_video_mode, "Sort Thing | Press any key to reset"); // create the window after the construction of the sf::Window instance
	app::init_columns();
}

// functions
// --private
void app::poll_events() {
	sf::Event event;

	while (m_window.pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::KeyReleased:
				init_columns();
				break;

			default:
				break;

		}
	}
}

void app::init_columns() {
	delete[] m_columns; // delete any previous heap allocs to prevent mem leak
	m_columns = new column[constants::column_count]; // if we reassign this before deleting, the memory its pointing towards to is still there

	for (int i = 0; i < constants::column_count; i++) {
		//			rand value between 1 and height
		int value = 1 + std::rand() % constants::window_height;
		m_columns[i].init(static_cast<float>(value));
		m_columns[i].setPosition(i * constants::column_size, static_cast<float>(constants::window_height - value));
	}
}

void app::draw_columns() {
	for (int i = 0; i < constants::column_count; i++) {
		m_window.draw(m_columns[i]);
	}
}

// swaps columns (so we can use bubble sort)
void app::swap_columns(int i, int j) {
	// swap them in the heap table
	column temp = m_columns[i];
	m_columns[i] = m_columns[j];
	m_columns[j] = temp;

	// change positons to reflect it
	m_columns[i].setPosition(i * constants::column_size, m_columns[i].getPosition().y);
	m_columns[j].setPosition(j * constants::column_size, m_columns[j].getPosition().y);

	// render and wait
	render(); // render here so it gets rendered each time
	std::this_thread::sleep_for(std::chrono::microseconds(1));
}

void app::render() {
	m_window.clear();

	// draw objects
	draw_columns();

	m_window.display();
}



// --public
void app::update() {
	poll_events();

	// swap objects each time until sorted?
	// bubble sort
	for (int i = 0; i < constants::column_count; i++) {
		for (int j = 0; j < constants::column_count - 1; j++) {
			if (m_columns[j].m_value > m_columns[j + 1].m_value) {
				poll_events(); // so we can interact w the window while this is happening

				swap_columns(j, j + 1); // draw
				//return; //(makes a other type of sorting algo?)
			}
		}
	}

	render(); // keep rendering if already sorted
}

bool app::is_open() {
	return m_window.isOpen();
}