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

	//tests constructor wide load error
/*	constexpr ra::cexpr::cexpr_string<20> just_right("01234567890123456789");
	just_right.print_ascii();
	const char* greg = "0123456789";
	const char* ory = greg + 6;
	const ra::cexpr::cexpr_string<6> gregory(greg, ory);
	gregory.print_ascii();
	const ra::cexpr::cexpr_string<5> GREGORYYYY(greg, ory);
	ra::cexpr::cexpr_basic_string<char, 20> big_mother("012345678901234567890");
*/
	//tests push wide load error
/*	ra::cexpr::cexpr_string<5> jah("1234");
	jah.print_ascii();
	jah.push_back('5');
	jah.print_ascii();
	jah.push_back('6');
*/	

	//test pop error
/*	ra::cexpr::cexpr_string<3> harvey;
	harvey.print_ascii();
	harvey.pop_back();
*/	
/*	ra::cexpr::cexpr_string<1> tate("L");
	tate.print_ascii();
	tate.pop_back();
	tate.print_ascii();
	tate.pop_back();
*/	
/*	ra::cexpr::cexpr_string<0> homer("");
	homer.print_ascii();
	*/
	
	//tests append function
	ra::cexpr::cexpr_string<5> donny("Wall");
	const char* excla = "!";
	donny.append(excla).print_ascii();
	donny.pop_back();
	donny.print_ascii();
	//const char* exclas = "!!";
	//donny.append(exclas);
	ra::cexpr::cexpr_string<10> barrack("Obama");
	constexpr ra::cexpr::cexpr_string<12> osama("Care!");
	constexpr ra::cexpr::cexpr_string<400> saddam("Stare!");
	barrack.append(osama).print_ascii();
	barrack.pop_back();
	barrack.pop_back();
	barrack.pop_back();
	barrack.pop_back();
	barrack.pop_back();
	//barrack.append(saddam).print_ascii();

	//test to_string helper function
	char buffer[10];
       	char* end;
	char** ptr = &end;
	std::size_t num {133742069};
	std::cout << "Wrote " << ra::cexpr::to_string( num, buffer, 9, ptr )
		<< " characters: ";
	for( std::size_t i {0}; &buffer[i] != end; ++i ){
		std::cout << buffer[i];
	}
	std::cout << "\n";

	//test clear function
	string dookie("Ewwwww gross man");
	dookie.print_ascii();
	dookie.clear();
	dookie.print_ascii();
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
