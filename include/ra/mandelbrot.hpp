#include <iostream>
#include <cstddef>
#include "ra/cexpr_basic_string.hpp"

namespace ra::fractal {

struct cexpr_complex {
	constexpr cexpr_complex( const cexpr_complex& ) = default;
	constexpr cexpr_complex& operator=( const cexpr_complex& ) = default;
	~cexpr_complex() = default;
	constexpr cexpr_complex() : real {0}, imag {0} {}
	constexpr cexpr_complex( const double R, const double I ) : real {R}, imag {I} {}
	constexpr double get_real() const { return real; }
	constexpr double get_imag() const { return imag; }
	constexpr double get_mag() const { return real*real + imag*imag; }
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

struct cexpr_pair {
	constexpr cexpr_pair( const cexpr_pair& ) = default;
	constexpr cexpr_pair& operator=( const cexpr_pair& ) = default;
	~cexpr_pair() = default;
	constexpr cexpr_pair() : k {0}, l {0} {}
	constexpr cexpr_pair( const double x, const double y ) : k {x}, l {y} {}
	constexpr double get_k() const { return k; }
	constexpr double get_l() const { return l; }
	private:
		double k;
		double l;
};

constexpr const char is_mandelous( const cexpr_complex& c ) {
	cexpr_complex zn = c;
	cexpr_complex zn1;
	for( std::size_t i {0}; i < 16; ++i ) {
		if( zn.get_mag() > 4 ) {
			return '0';
		}
		zn1 = zn;
		zn = zn1 * zn1 + c;
	}

	return '1';
}

constexpr const cexpr_complex megatron( const double k, const double l, const std::size_t W, const std::size_t H ) {
	double real = -1.6 + k * 2.2 / ((double)W - 1);
	double imag = -1.1 + ((double)H - 1 - l) * 2.2 / ((double)H - 1);
	cexpr_complex result( real, imag );
	return result;
}

/*constexpr const std::size_t string_sizer( const std::size_t W, const std::size_t H ) {
	char Wsize[20] = "";
	char Hsize[20] = "";
	std::size_t identifier = 2 + 1 + ra::cexpr::to_string( W, Wsize, 20, nullptr ) + 1 + ra::cexpr::to_string( H, Hsize, 20, nullptr ) + 1;
	std::size_t body = H * (W + 1);
	return identifier + body;
}*/

template< std::size_t W, std::size_t H >
constexpr const ra::cexpr::cexpr_string< 45 + H * (W + 1) > string_maker() {
	ra::cexpr::cexpr_string< 45 + H * (W + 1) > result;
	char identifier[46] = "P1 ";
	char* id = identifier;
	std::size_t Wsize = ra::cexpr::to_string( W, id + 3, 20, nullptr );
	*(id + 3 + Wsize) = ' ';
	std::size_t Hsize = ra::cexpr::to_string( H, id + 3 + Wsize + 1, 20, nullptr );
	*(id + 3 + Wsize + 1 + Hsize) = '\n';
	*(id + 3 + Wsize + 1 + Hsize + 1) = char(0);
	char fractal[H * (W + 1) + 1] = "";
	char* fr = fractal;
	for( std::size_t y {H}; y > 0; --y ) {
		for( std::size_t x {0}; x < W; ++x ) {
			*fr =  is_mandelous( megatron( (double)x, (double)y, W, H ) );
			++fr;
		}
		*fr = '\n';
		++fr;
	}
	*fr = char(0);
	return result.append( identifier ).append( fractal );
}

//W>2 and H>1
//P1 W H\n00000\n00000\n00000\n so size needed to allocate for string is:
//2(P1) + 1(space) + (#chars for W) + 1(space) + (#chars for H) + 1(newline) + (W + 1)*H
//mandelbrot variable will be cexpr_string<
template< std::size_t W, std::size_t H >
constexpr auto mandelbrot = string_maker< W, H >();
}
