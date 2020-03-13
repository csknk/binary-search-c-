#include "recursive.h"

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

