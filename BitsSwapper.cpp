#include <iostream>
#include <bitset>
#include <array>
#include <cstdint>
#include <ctime>
#include <iomanip>



void bitSwapper(uint8_t* begin, size_t byteLength) {
	for (size_t i = 0; i < byteLength; ++i) {
		const auto mask = rand();
		auto& number    = begin[i];
		
		std::cout 
			<< std::left << std::setw(10) << std::bitset<8>(number) 
			<< std::left << std::setw(10) << std::bitset<8>(mask);
		
		number ^= mask;

		std::cout 
			<< std::left << std::setw(10) << std::bitset<8>(number) 
			<< std::endl;
	}
}


void print(uint8_t* arr, size_t size) {
	for (size_t i = 0; i < size; ++i) {
		std::cout << static_cast<unsigned int>(arr[i]) << ' ';
	}
}


int main() {
	srand(time(0));
	
	std::array<uint8_t, 10> arr;
	
	for (auto& el : arr) {
		el = rand();
	}

	std::cout << "Before swapper: " << std::endl;
	print(arr.data(), arr.size());
	std::cout << "\n\n\n";
	
	std::cout 
		<< std::left << std::setw(10) << "Number" 
		<< std::left << std::setw(10) << "Mask" 
		<< std::left << std::setw(10) << "Swapped" 
		<< std::endl;
	bitSwapper(arr.data(), arr.size());

	std::cout << "\n\nAfter swapper: " << std::endl;
	print(arr.data(), arr.size());
}