#include "ra/cexpr_basic_string.hpp"
#include <iostream>
#include <stdexcept>
#include <cstring>

int main(){/*
	constexpr ra::cexpr::cexpr_basic_string<char, 4> empty_string;
	empty_string.print_ascii();
	constexpr const char* c = "Oh hello there!!!";
	constexpr ra::cexpr::cexpr_basic_string<char, 20> constd_string(c);
	constd_string.print_ascii();
	//ra::cexpr::cexpr_basic_string<char, 6> oversized_string(c);
	constexpr const char* start = "What's up dawg?";
	constexpr const char* end = start + 9;
	constexpr ra::cexpr::cexpr_basic_string<char, 20> iter_string(start, end);
	iter_string.print_ascii();
	constexpr std::size_t maximum = ra::cexpr::cexpr_basic_string<char, 69>::max_size();
	std::cout << "Maximum size: " << maximum << "\n";
	constexpr std::size_t empty_string_size = empty_string.size();
	constexpr std::size_t empty_string_capacity = empty_string.capacity();
	constexpr std::size_t constd_string_size = constd_string.size();
	constexpr std::size_t constd_string_capacity = constd_string.capacity();
	constexpr std::size_t iter_string_size = iter_string.size();
	constexpr std::size_t iter_string_capacity = iter_string.capacity();
	std::cout << "Empty string size: " << empty_string_size << "\n";
	std::cout << "Empty string capacity: " << empty_string_capacity << "\n";
	std::cout << "Constd string size: " << constd_string_size << "\n";
	std::cout << "Constd string capacity: " << constd_string_capacity << "\n";
	std::cout << "Iter string size: " << iter_string_size << "\n";
	std::cout << "Iter string capacity: " << iter_string_capacity << "\n";
	const char* booboo = constd_string.data();
	std::cout << "Constd string data (const version): " << *booboo << "\n";
	ra::cexpr::cexpr_basic_string<char, 50> clank("Why did the chicken cross the road?");
	char* doodoo = clank.data();
	std::cout << "Clank data: ";
	for( unsigned i {0}; *(doodoo+i) != char(0); ++i ){
		std::cout << *(doodoo+i);
	}std::cout << "\n";	
	*(doodoo+8) = 'h';
	*(doodoo+9) = 'i';
	*(doodoo+10) = 's';
	std::cout << "Clank tampered: ";
	for( unsigned i {0}; *(doodoo+i) != char(0); ++i ){
		std::cout << *(doodoo+i);
	}std::cout << "\n";*/	
	/*
	constexpr ra::cexpr::cexpr_basic_string<char, 29> ARNIE("PUMP PUMP PUMP");
	constexpr const char* clovis = ARNIE.begin();
	std::cout << "Arnie says ";
	for( unsigned i {0}; *(clovis+i) != char(0); ++i ) {
		std::cout << *(clovis+i);
	}std::cout << "\n";
	*/
	/*
	ra::cexpr::cexpr_basic_string<char, 14> ricky("Hey bud");
	char* bapu = ricky.begin();
	for( unsigned i {0}; *(bapu+i) != char(0); ++i ) {
		std::cout << *(bapu+i);
	}std::cout << "\n";
	*bapu = 'B';
	*(bapu+1) = 'y';
	*(bapu+2) = 'e';
	for( unsigned i {0}; *(bapu+i) != char(0); ++i ) {
		std::cout << *(bapu+i);
	}std::cout << "\n";
	char& greasy = ricky[4];
	char& slimy = ricky[5];
	char& sleazy = ricky[6];
	std::cout << greasy << slimy << sleazy << "\n";
	greasy = 'n';
	slimy = 'u';
	sleazy = 'g';
	std::cout << greasy << slimy << sleazy << "\n";
	*/
	constexpr ra::cexpr::cexpr_basic_string<char, 69> nah("Oh nah son");
	constexpr const char& sonnyboy = nah[0];
	std::cout << sonnyboy << "\n";
	return 0;
}
