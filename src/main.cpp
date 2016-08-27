#include <iostream>

#include "int_sorter_facade.h"

int main() {
	std::cout << "Hi C++\n";

	rust::IntSorterFacade sorter {};

	sorter.put(23);
	sorter.put(13);
	sorter.put(6);
	sorter.put(12);
	sorter.put(42);

	// Iterate over all values and exhaust the container by 2
	for (int i = 0; i < 5+2; ++i) {
		std::cout << i << ": " << sorter.get() << "\n";
	}


	std::cout << "Bye C++\n";
	return 0;
}
