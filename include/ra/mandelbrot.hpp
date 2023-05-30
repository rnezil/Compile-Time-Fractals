#include <iostream>
#include <cstddef>
#include "ra/cexpr_basic_string.hpp"

namespace ra::fractal {

/*struct cexpr_complex {
	double real;
	double imag;
	constexpr cexpr_complex( const cexpr_complex& ) = default;
	constexpr cexpr_complex& operator=( const cexpr_complex& ) = default;
	~cexpr_complex() = default;
	constexpr cexpr_complex() : real {0}, imag {0} {}
	constexpr cexpr_complex( const double& R, const double& I ) : real {R}, imag {I} {}
	constexpr double mag() const { return real*real + imag*imag; }
	constexpr cexpr_complex operator+( const cexpr_complex& other ) const {
		cexpr_complex result( real + other.real, imag + other.imag );
		return result;
	}
	constexpr cexpr_complex operator-( const cexpr_complex& other ) const {
		cexpr_complex result( real - other.real, imag - other.imag );
		return result;
	}
	constexpr cexpr_complex operator*( const cexpr_complex& other ) const {
		cexpr_complex result( real * other.real - imag * other.imag, real * other.imag + imag * other.real );
		return result;
	}
	void print() const {
		std::cout << "(" << real << " + " << imag << "i)";
	}
};*/

constexpr char is_mandelous( /*const cexpr_complex& c*/ const double& seed_real, const double& seed_imag ) {
	/*cexpr_complex zn = c;
	cexpr_complex zn1;*/
	double current_real(seed_real);
	double current_imag(seed_imag);
	double old_real(0);
	double old_imag(0);
	for( std::size_t i {0}; i < 16; ++i ) {
		if(/*zn.mag() > 4*/ current_real*current_real + current_imag*current_imag > 4 ) {
			return '0';
		}
		/*zn1 = zn;
		zn = zn1 * zn1 + c;*/
		old_real = current_real;
		old_imag = current_imag;
		current_real = old_real*old_real - old_imag*old_imag + seed_real;
		current_imag = old_real*old_imag*2 + seed_imag;
	}

	return '1';
}

template< std::size_t W, std::size_t H >
constexpr ra::cexpr::cexpr_string< 45 + H * (W + 1) > string_maker() {
	ra::cexpr::cexpr_string< 45 + H * (W + 1) > result;
	char identifier[46] = "P1 ";
	char* id = identifier;
	std::size_t Wsize = ra::cexpr::to_string( W, id + 3, 20, nullptr );
	*(id + 3 + Wsize) = ' ';
	std::size_t Hsize = ra::cexpr::to_string( H, id + 3 + Wsize + 1, 20, nullptr );
	*(id + 3 + Wsize + 1 + Hsize) = '\n';
	*(id + 3 + Wsize + 1 + Hsize + 1) = char(0);
	result.append( identifier );/*
	double real_seed(0);
	double image_seed(0);
	double current_real(0);
	double current_imag(0);
	double old_real(0);
	double old_imag(0);*/
	for( std::size_t l {H}; l > 0; --l ) {
		for( std::size_t k {0}; k < W; ++k ) {
			result.push_back( is_mandelous( (-1.6 + k * 2.2 / (W - 1)) , (-1.1 + (H - 1 - l) * 2.2 / (H - 1)) ) );
			
			/*for( std::size_t i {0}; i < 16; ++i ) {
				if( current_real*current_real + current_imag*current_imag > 4 ) {
					return '0';
				}
				old_real = current_real;
				old_imag = current_imag;
				current_real = old_real*old_real - old_imag*old_imag + seed_real;
				current_imag = old_real*old_imag*2 + seed_imag;*/

		}
		result.push_back( '\n' );
	}
	return result;
}

//W>2 and H>1
//P1 W H\n00000\n00000\n00000\n so size needed to allocate for string is:
//2(P1) + 1(space) + (#chars for W) + 1(space) + (#chars for H) + 1(newline) + (W + 1)*H
//mandelbrot variable will be cexpr_string<
template< std::size_t W, std::size_t H >
constexpr auto mandelbrot(string_maker< W, H >());
}
