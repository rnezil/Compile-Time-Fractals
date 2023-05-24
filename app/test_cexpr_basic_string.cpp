#include "ra/cexpr_basic_string.hpp"
#include <iostream>
#include <stdexcept>

int main(){
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
	ra::cexpr::cexpr_basic_string<char, 50> clank("Why did the chicken cross the road"?);
	char* doodoo = clank.data();
	std::cout << "Clank data (non const version): " << *doodoo << "\n";
	return 0;
}
