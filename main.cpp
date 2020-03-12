#include <iostream>
#include <limits>
#include <assert.h>

int A[] = {1, 10, 20, 47, 59, 63, 75, 88, 99, 107, 120, 133, 155, 162, 176, 188, 199, 200, 210, 222};

int binarySearch(int A[], int targetValue, int low, int high)
{
	if (low > high) {
		return -1;
	}	       
	int i = low + ((high - low) / 2);
	if (A[i] == targetValue) {
		return i;
	} else if (A[i] > targetValue) {
		return binarySearch(A, targetValue, low, i - 1);
	} else {
		return binarySearch(A, targetValue, i + 1, high);
	}
}

int binarySearch2(int A[], int targetValue, int len)
{
	static int base = 0;
	if (len < 1) {
		return -1;
	}	       
	int midIndex = (len % 2) ? len / 2 : (len / 2) - 1;
	midIndex = midIndex + base;
	if (A[midIndex] == targetValue) {
		return midIndex;
	}

	if (A[midIndex] < targetValue) {
	       	// Go RIGHT
		base = midIndex + 1;
		return binarySearch2(A, targetValue, len / 2);
	} else {
	       	// Go LEFT
		int newLen = len % 2 ? len / 2 : (len / 2) - 1;
		return binarySearch2(A, targetValue, newLen);
	}
}

void testCorrectVals()
{
	for (size_t i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
		std::cout << "Searching for " << A[i] << "... ";
		int res = binarySearch(A, A[i], 0, (sizeof(A) / sizeof(A[0]) - 1));
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
	int r = binarySearch(A, val, 0, (sizeof(A) / sizeof(A[0]) - 1));
	int r2 = binarySearch2(A, val, sizeof(A) / sizeof(A[0]));
	std::cout << "r = " << r << std::endl;
	std::cout << "r2 = " << r2 << std::endl;
	testCorrectVals();
	return 0;
}
