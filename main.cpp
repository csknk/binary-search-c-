#include <iostream>
#include <limits>
#include <assert.h>
#include "recursive.h"
#include "iterative.h"


int A[] = {1, 10, 20, 47, 59, 63, 75, 88, 99, 107, 120, 133, 155, 162, 176, 188, 199, 200, 210, 222};

void testCorrectVals()
{
	for (size_t i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
		std::cout << "Searching for " << A[i] << "... ";
//		int res = binarySearch(A, A[i], 0, (sizeof(A) / sizeof(A[0]) - 1));
		int res = binarySearchIterative(A, sizeof(A) / sizeof(A[0]), A[i]);
		if (res != -1 ) {
			std::cout << "found at index " << res << ".\n";
		} else {
			std::cout << "not found.\n";
		}
		assert((int)i == res && "FAIL. Should have matched.");
	}
	std::cout << "All tests passed..." << std::endl;
}

int main()
{
	int val;
	std::cout << "Please enter an integer: ";
	while (!(std::cin >> val)) {
		std::cout << "Can't read that as an integer - please try again:" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	int r = binarySearchIterative(A, sizeof(A) / sizeof(A[0]), val);
	std::cout << "r = " << r << std::endl;
	testCorrectVals();
	return 0;
}
