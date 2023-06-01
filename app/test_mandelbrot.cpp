#include <iostream>
#include "ra/mandelbrot.hpp"

int main() {
	constexpr auto s = ra::fractal::mandelbrot< 1024, 1024 >;

	std::cout << s.begin() << '\n';
}
