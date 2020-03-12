Binary Search Examples in C++
=============================

A collection of binary search ideas in C++.

The first example is a pretty standard recursive approach:

```c++
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
```

The second example arose when trying out an online course, with a web-based terminal that black box tests your function.

In this case, the function signature was limited to three parameters: an integer array, a target integer to search for, and an integer length.

The solution involves carrying the index offset during recursive calls by setting a `static` variable appropriately:

```c++
int binarySearch2(int A[], int targetValue, int len)
{
	static int base = 0; // An offset needed if the search moves to the higher partition.
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
```
This method required a bit more thought in order to calculate the middle index and the new length for the next recursive call. 



