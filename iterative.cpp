#include "iterative.h"

// Iterative algorithm: binary search
// 1. Set values for low and high indices - starting condition, low == 0, high == len -1.
// 2. Determine the mid index (or leftmost mid index if length is even)
// 3. If value at the mid index == target value, return the index.
// 4. If value at the mid index > target value, make a partition of elements with indices < mid index.
// 5. If value at the mid index < target value, make a partition of elements with indices > mid index.
// 6. Repeat until either:
//	- low > high OR
//	- high < low
int binarySearchIterative(int A[], int len, int targetVal)
{
	std::cout << "inside binarySearchIterative...\n";
	int high = len - 1;
	int low = 0, midIndex = 0;
	while (high >= low && low <= high) {
		midIndex = ((high - low) / 2) + low;
		int val = A[midIndex];
		if (val == targetVal) {
			return midIndex;
		}
		if (val > targetVal) {
			high = midIndex - 1;
			continue;
		}
		if (val < targetVal) {
			low = midIndex + 1;
			continue;
		}	
	}
	return -1;	
}

