#include <iostream>
#include "ra/mandelbrot.hpp"

int main() {
	constexpr auto s = ra::fractal::mandelbrot< 128, 128 >;

	std::cout << s.begin() << '\n';
}
