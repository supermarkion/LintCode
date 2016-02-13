// impelement binary search in C language

// if we use recursion method
#define E_TARGET_NOT_IN_ARRAY -1
#define E_ARRAY_UNORDERED -2
#define E_LIMITS_REVERSED -3

int BinarySearch(int* array, int lower, int upper, int target)
{
	int center, range;

	range = upper - lower;
	if (range < 0) {
		return E_LIMITS_REVERSED;
	} else if (range == 0 && array[low] != target) {
		return E_TARGET_NOT_IN_ARRAY;
	}

	if (array[lower] > array[upper]) {
		return E_ARRAY_UNORDERED;
	}

	center = ((range)/2) + lower;

	if (target == array[center]) {
		return center;
	} else if (target < array[center]) {
		return BinarySearch(array, lower, center - 1, target);
	} else {
		return BinarySearch(array, center + 1, upper, target);
	}
}

int IterBinarySearch(int* array, int lower, int upper, int target)
{
	int center, range;

	if (lower > upper) {
		return E_LIMITS_REVERSED;
	}
	
	while (1) {
		range = upper - lower;
		if (range == 0 && array[lower] != target) {
			return E_TARGET_NOT_IN_ARRAY;
		}

		if (array[lower] > array[upper]) {
			return E_ARRAY_UNORDERED;
		}

		center = ((range)/2) + lower;

		if (target == array[center]) {
			return center;
		} else if (target < array[center]) {
			upper = center - 1;
		} else {
			lower = center + 1;
		}
	}

}