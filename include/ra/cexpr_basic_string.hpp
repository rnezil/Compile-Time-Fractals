//A class template for representing a sequence of characters that can be used in constexpr contexts
//Allowed character types: char, unsigned char, wchar_t
//Has parameter for maximum number of characters that can be held in the string
//Uses C-style array to store characters
//Stores data internally in null-terminated form -> dummy character with value value_type(0) stored immediately after last character in the string

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <cassert>

namespace ra::cexpr {
	//std::size_t represents a size in bytes that is the maximum size 
	template <class T, std::size_t M>
	class cexpr_basic_string
	{
	public:
		//Unsigned integral type used to represent sizes
		using size_type = std::size_t;

		//The type of each character in the string, ie alias for the template parameter T
		using value_type = T;

		//The type of a mutating pointer to each character in the string
		using pointer = T*;

		//The type of a non-mutating pointer to each character in the string
		using const_pointer = const T*;

		//The type of a mutating reference to a character in the string
		using reference = T&;

		//The type of a non-mutating reference to a character in the string
		using const_reference = const T&;

		//A mutating iterator type for the elements in the string
		using iterator = pointer;

		//A non-mutating iterator type for the elements in the string
		using const_iterator = const_pointer;

		//Creates an empty string
		constexpr cexpr_basic_string()/* : string_{""}, mutator_ {nullptr}*/ {}

		//Copy constructor
		constexpr cexpr_basic_string( const cexpr_basic_string& )= default;

		//Assignment operator
		constexpr cexpr_basic_string& operator=( const cexpr_basic_string& ) = default;

		//Destructor
		~cexpr_basic_string() = default;

		//Creates a string with the contents given by the null-terminated character array pointed to by s. If the string does not have sufficient capacity to hold the character data provided, throw an exception of type std::run_error
		constexpr cexpr_basic_string( const value_type* s ) :/* string_ {s}, mutator_ { nullptr },*/ array_() {
			size_type i {0};
			while( (i < M+1) && (*(s+i) != value_type(0)) ) {
				++i;
			}//prototype oversize check
			if( i == M+1 ){
				throw std::runtime_error {"Wide load error"};
			}	

			i = 0;
			while( *(s + i) != value_type(0) ) {
				array_[i] = *(s + i);
				++i;
			}
			array_[i] = value_type {0};
		}	

		constexpr cexpr_basic_string( const_iterator first, const_iterator last ):/* string_ {first}, mutator_ {nullptr},*/ array_() {
			size_type i {0};
			while( (i < M+1) && (first + i != last) ){
				++i;
			}
			if( i == M+1 ){
				throw std::runtime_error {"Wide load error"};
			}


			i = 0;
			while( *(first + i) != value_type(0) ) {
				array_[i] = *(first + i);
				++i;
			}
			array_[i] = value_type {0};
			//add guards for aliasing, ie if first == last
		}

		static constexpr size_type max_size() { return M; }

		constexpr size_type capacity() const { return M; }

		constexpr size_type size() const {
			size_type i {0};
			while( array_[i] != value_type(0) ) {
				++i;
			}
			return i;
		}
		/*
		value_type* data() {
			if( mutator_ == nullptr ) {
				size_type i {0};
				while( *(string_ + i) != value_type(0) ) {
					array_[i] = *(string_ + i);
					++i;
				}
				array_[i] = value_type(0);
				mutator_ = &array_[0];
				string_ = mutator_;
			}
			return mutator_;
		}

		const value_type* data() const { return string_; }

		constexpr iterator begin() { return mutator_; }	

		constexpr const_iterator begin() const { return string_; }

		constexpr iterator end() {
			if( mutator_ == nullptr ){
				return mutator_;
			}else{
				return mutator_ + size();
			}
		}
		
		constexpr const_iterator end() const { return string_ + size();	}

		constexpr reference operator[](size_type i) {
			assert( i >= 0 && i <= size() );
			if( mutator_ == nullptr ){
				return mutator_;
			}else{
				return *( mutator_ + i );
			}
		}

		constexpr const_reference operator[](size_type i) const {
			assert( i >= 0 && i <= size() );
			return *( string_ + i );
		}

		constexpr void push_back( const T& x ){
			//can never 'actually' be called at compile time
			assert( size() != capacity() );
			if( mutator_ != nullptr ){
				*(mutator_ + size()) = x;
				*(mutator_ + size() + 1) = value_type(0); 
			}
		}

		constexpr void pop_back(){
			if( size() == 0 ){
				throw std::runtime_error {"Ain't nuthin' worth poppin' off an empty string brother"};
			}
			
			if( mutator_ != nullptr ){
				*(mutator_ + size() - 1) = value_type(0);
			}
		}

		constexpr cexpr_basic_string& append( const value_type* s ) {
			assert( s != nullptr );
			size_type i {0};
			while( *(s + i) != value_type(0) ){
				++i;
			}
			
			if( size() + i <= M ){
				throw std::runtime_error {"Wide load error"};
			}

			if( mutator_ != nullptr ){
				for( size_type j {0}; 
*/
		//Function for debugging
		void print_ascii() const {
			for( std::size_t i {0}; i < M && array_[i]!= value_type(0); ++i) {
				std::cout << array_[i];
			}
			std::cout << "\n";
			for( std::size_t i {0}; i < M+1; ++i) {
				std::cout << (unsigned)array_[i] << " ";
			}
			std::cout << "\n";
		}
	private:
		//Underlying storage member
		//const_pointer string_;
		//pointer mutator_;
		value_type array_[M+1] = {""};
	};

	template<std::size_t M>
	using cexpr_string = cexpr_basic_string<char, M>;
	
	//Converts integer n to its equivalent decimal null-terminated string representation
	//Buffer to be used to store the result starts at the location pointed to by buffer and has a size of size characters
	//resulting string produced by the function is null-terminated
	//number of characters written to the buffer, excluding the null character, is returned
	//if end is non-null, *end is set to point to the null character at the end of the converted string
	//if buffer provided does not have sufficient capacity to hold the string resulting from the conversion process, throw std::runtime_error
	constexpr std::size_t to_string( std::size_t n, char* buffer, std::size_t size, char** end );
}
