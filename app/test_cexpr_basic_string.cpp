#include "ra/cexpr_basic_string.hpp"
#include <iostream>
#include <stdexcept>
#include <cstring>

using string = ra::cexpr::cexpr_basic_string<char, 69>;

int main(){
	//tests constructors
	constexpr ra::cexpr::cexpr_basic_string<char, 4> empty_string;
	empty_string.print_ascii();
	constexpr ra::cexpr::cexpr_basic_string<char, 20> a_string("Oh hello there!");
	a_string.print_ascii();

	//tests size() function
	constexpr std::size_t a_string_size = a_string.size();
	std::cout << "Size of above string: " << a_string_size << "\n";
	constexpr std::size_t empty_string_size = empty_string.size();
	std::cout << "Size of an empty string: " << empty_string.size() << "\n";
	
	//tests data() function
	ra::cexpr::cexpr_basic_string<char, 17> mutable_string("Ruh roh Scraggy");
	char* scoob = mutable_string.data();
	for( std::size_t i {0}; *(scoob + i) != char(0); ++i ){
		std::cout << *(scoob+i);
	}std::cout << "\n";
	*scoob = 'D';
	std::cout << *scoob << *(scoob+1) << *(scoob+2) << "\n";
	const ra::cexpr::cexpr_basic_string<char, 17> cmon = mutable_string;
	const char* cmon_scoob = cmon.data();
	for(std::size_t i {0}; *(cmon_scoob+i) != char(0); ++i ){
		std::cout << *(cmon_scoob+i);
	}std::cout << "\n";
	
	//tests begin() and end() functions
	string doo("Meddling kids");
	static constexpr string scoo("Mystery");
	char* velma = doo.begin();
	constexpr const char* fred = scoo.begin();
	for( std::size_t i {0}; *(fred+i) != char(0); ++i ){
		std::cout << *(fred+i);
	}std::cout << "\n";
	constexpr const char* daphne = scoo.end();
	std::cout << *(daphne - 1) << "\n";

	//tests [] operator
	constexpr string ronny("Can't keep my *exception* in my pants");
	constexpr char j = ronny[14];
	std::cout << "Can't keep my " << j << j << j << j << " in my pants!" << "\n";
	
	//tests push_back() and pop() functions
	string n("N");
	n.push_back('.');
	n.push_back('W');
	n.push_back('.');
	n.push_back('A');
	n.print_ascii();
	n.pop_back();
	n.pop_back();
	n.pop_back();
	n.pop_back();
	n.push_back('i');
	n.push_back('c');
	n.push_back('e');
	n.push_back('.');
	n.print_ascii();

	//tests append function
	string ricky("Keep off my da");
	const char* bubbles = "mn grass!!!";
	(ricky.append(bubbles)).print_ascii();

	//tests cexpr_string hotkey
	constexpr ra::cexpr::cexpr_string<30> monkey("bananas bananas bananas");
	monkey.print_ascii();

	//tests iterator based constructor
	constexpr const char* binky = "Blindsided mate";
	constexpr const char* boinky = binky+9;
	constexpr string blanky(binky, boinky);
	std::cout << "[" << *binky << ", " << *boinky << "]\n";
	blanky.print_ascii();
	return 0;
}

/*
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
	
	//constexpr ra::cexpr::cexpr_basic_string<char, 69> nah("Oh nah son");
	//constexpr const char& sonnyboy = nah[0];
	//std::cout << sonnyboy << "\n";
	return 0;
}*/
