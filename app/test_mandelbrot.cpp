#include <iostream>
#include "ra/mandelbrot.hpp"

int main() {
	constexpr auto s = ra::fractal::mandelbrot< 512, 512 >;

	std::cout << s.begin() << '\n';
}
