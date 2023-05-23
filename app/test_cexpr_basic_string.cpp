#include "ra/cexpr_basic_string.hpp"
#include <iostream>

int main(){
	constexpr ra::cexpr::cexpr_basic_string<char, 4> empty_string;
	//empty_string.print_ascii();
	char str[16] = { 'O', 'h', ' ', 'h', 'e', 'l', 'l', 'o', ' ', 't', 'h', 'e', 'r', 'e', '!' };
	//char* ptr { &str[0] };
	//problem: the linker is what sorts out array addresses
	//ra::cexpr::cexpr_basic_string<char, 20> constd_string(ptr);
	//constd_string.print_ascii();
	//constexpr char* const c = (const char[]){'a', 'b', 'c', '\0'};
	constexpr const char* c = "Oh hello there!";
	constexpr ra::cexpr::cexpr_basic_string<char, 20> constd_string(c);
	constd_string.print_ascii();
	return 0;
}
