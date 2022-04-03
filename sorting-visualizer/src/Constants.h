#pragma once

namespace constants {
	inline constexpr int window_width = 600;
	inline constexpr int window_height = 400;

	inline constexpr int column_count = 50;
	inline constexpr float column_size = window_width / column_count; // bc of sf::Vector2f
}

// TODO: put this in all files