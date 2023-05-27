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
		constexpr cexpr_basic_string() {}

		//Copy constructor
		constexpr cexpr_basic_string( const cexpr_basic_string& )= default;

		//Assignment operator
		constexpr cexpr_basic_string& operator=( const cexpr_basic_string& ) = default;

		//Destructor
		~cexpr_basic_string() = default;

		//Creates a string with the contents given by the null-terminated character array pointed to by s. If the string does not have sufficient capacity to hold the character data provided, throw an exception of type std::run_error
		constexpr cexpr_basic_string( const value_type* s ) : array_() {
			size_type i {0};
			while( (i < M+1) && (*(s+i) != value_type(0)) ) {
				++i;
			}

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

		constexpr cexpr_basic_string( const_iterator first, const_iterator last ): array_() {
			size_type i {0};
			while( (i < M+1) && (first + i != last) ){
				++i;
			}

			if( i == M+1 ){
				throw std::runtime_error {"Wide load error"};
			}

			i = 0;
			while( first + i != last ) {
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
		
		value_type* data() {
			return array_;
		}

		const value_type* data() const { return array_; }

		//kind of sketchy because it should be impossible to get a 
		//non-const pointer to a constexpr object
		constexpr iterator begin() { return array_; }	

		constexpr const_iterator begin() const { return array_; }
		
		//sketchy for same reasons as non-const begin()
		constexpr iterator end() { return array_ + size(); }
		
		constexpr const_iterator end() const { return array_ + size();	}

		constexpr reference operator[](size_type i) {
			assert( i >= 0 && i <= size() );
			return array_[i];
		}

		constexpr const_reference operator[](size_type i) const {
			assert( i >= 0 && i <= size() );
			return array_[i];
		}

		constexpr void push_back( const T& x ){
			assert( size() != capacity() );
			array_[size()] = x;
			array_[size() + 1] = value_type(0);
		}

		constexpr void pop_back(){
			if( size() == 0 ){
				throw std::runtime_error {"Ain't nuthin' worth poppin' off an empty string brother"};
			}

			array_[size() - 1] = value_type(0);
		}

		constexpr cexpr_basic_string& append( const value_type* s ) {
			assert( s != nullptr );
			size_type i {0};
			while( *(s + i) != value_type(0) ){
				++i;
			}
			
			if( size() + i > M ){
				throw std::runtime_error {"Wide load error"};
			}
			
			for( size_type j {0}; j < i; ++j ){
				push_back( *(s + j) );
			}
			array_[size()] = value_type(0);//ensure null-terminated
			return *this;
		}

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
