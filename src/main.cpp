#include <iostream>

#include "int_sorter_facade.h"

int main() {
	std::cout << "Hi C++\n";

	IntSorterFacade sorter {};

	sorter.put(6);
	sorter.put(12);
	sorter.put(13);
	sorter.put(23);
	sorter.put(42);

	for (int i = 0; i < 5; ++i) {
		std::cout << i << ": " << sorter.get() << "\n";
	}


	std::cout << "Bye C++\n";
	return 0;
}
