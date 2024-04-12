#include <iostream>
#include <bitset>
#include <array>
#include <cstdint>
#include <ctime>



void bitSwapper(uint16_t* begin, size_t byteLength) {
	for (size_t i = 0; i < byteLength; ++i) {
		const auto mask = rand();
		auto& number    = begin[i];
		
		std::cout << std::bitset<16>(number) << '\t' << std::bitset<16>(mask) << '\t';
		
		number ^= mask;

		std::cout << std::bitset<16>(number) << std::endl;
	}
}



int main() {
	srand(time(0));
	
	std::array<uint16_t, 10> arr;
	
	for (auto& el : arr) {
		el = rand();
	}

	std::cout << "Before swapper: " << std::endl;
	for (const auto& el : arr) {
		std::cout << el << ' ';
	}
	std::cout << "\n\n\n";
	
	bitSwapper(arr.data(), arr.size());

	std::cout << "\n\nAfter swapper: " << std::endl;
	for (const auto& el : arr) {
		std::cout << el << ' ';
	}
}