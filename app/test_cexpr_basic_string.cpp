#include "ra/cexpr_basic_string.hpp"
#include <iostream>

int main(){
	constexpr ra::cexpr::cexpr_basic_string<char, 4> empty_string;
	empty_string.print_ascii();
	return 0;
}
