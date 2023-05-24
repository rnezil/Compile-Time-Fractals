#include "ra/cexpr_basic_string.hpp"
#include <iostream>
#include <stdexcept>

int main(){
	constexpr ra::cexpr::cexpr_basic_string<char, 4> empty_string;
	//empty_string.print_ascii();
	constexpr const char* c = "Oh hello there!";
	constexpr ra::cexpr::cexpr_basic_string<char, 20> constd_string(c);
	constd_string.print_ascii();
	//ra::cexpr::cexpr_basic_string<char, 6> oversized_string(c);
	constexpr const char* start = "What's up dawg?";
	constexpr const char* end = start + 9;
	constexpr ra::cexpr::cexpr_basic_string<char, 20> iter_string(start, end);
	iter_string.print_ascii();
	return 0;
}
