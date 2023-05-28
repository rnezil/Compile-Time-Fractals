#include <iostream>
#include <cmath>
#include <cstddef>

namespace ra::fractal {

struct cexpr_complex {
	constexpr cexpr_complex( const cexpr_complex& ) = default;
	constexpr cexpr_complex& operator=( const cexpr_complex& ) = default;
	~cexpr_complex() = default;
	constexpr cexpr_complex() : real {0}, imag {0} {}
	constexpr cexpr_complex( const double R, const double I ) : real {R}, imag {I} {}
	constexpr double get_real() const { return real; }
	constexpr double get_imag() const { return imag; }
	constexpr double get_mag() const { return std::sqrt( real*real + imag*imag ); }
	constexpr cexpr_complex operator+( const cexpr_complex& other ) const {
		cexpr_complex result( get_real() + other.get_real(), get_imag() + other.get_imag() );
		return result;
	}
	constexpr cexpr_complex operator-( const cexpr_complex& other ) const {
		cexpr_complex result( get_real() - other.get_real(), get_imag() - other.get_imag() );
		return result;
	}
	constexpr cexpr_complex operator*( const cexpr_complex& other ) const {
		cexpr_complex result( get_real() * other.get_real() - get_imag() * other.get_imag(), get_real() * other.get_imag() + get_imag() * other.get_real() );
		return result;
	}
	void print() const {
		std::cout << "(" << get_real() << " + " << get_imag() << "i)";
	}
	private:
		double real;
		double imag;
};

constexpr char is_mandelous( const cexpr_complex& c ) const {
	cexpr_complex zn = c;
	cexpr_complex zn1;
	for( std::size_t i {0}; i < 16; ++i ) {
		if( zn.get_mag() > 2 ) {
			return '0';
		}
		zn1 = zn;
		zn = zn1 * zn1 + c;
	}

	return '1';
}

//W>2 and H>1
//P1 W H\n00000\n00000\n00000\n so size needed to allocate for string is:
//2(P1) + 1(space) + (#chars for W) + 1(space) + (#chars for H) + 1(newline) + (W + 1)*H
//mandelbrot variable will be cexpr_string<
template< std::size_t W, std::size_t H >
constexpr auto mandelbrot;
}
