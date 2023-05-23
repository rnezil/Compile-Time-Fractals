#include "ra/cexpr_basic_string.hpp"
#include <iostream>
#include <stdexcept>

int main(){
	constexpr ra::cexpr::cexpr_basic_string<char, 4> empty_string;
	//empty_string.print_ascii();
	constexpr const char* c = "Oh hello there!";
	constexpr ra::cexpr::cexpr_basic_string<char, 20> constd_string(c);
	constd_string.print_ascii();
	constexpr ra::cexpr::cexpr_basic_string<char, 6> oversized_string(c);
	oversized_string.print_ascii();
	return 0;
}
