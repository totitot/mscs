// ////////////////////////////
// author: Kenth Remon Crisolo
// email: kcrisolo07@gmail.com
// ////////////////////////////

#ifndef BINARY_SEARCH__H
#define BINARY_SEARCH__H
#include <iostream>

// O(log n) worst case
template<typename T>
T binary_search(T const& value, T arr[], size_t lo, size_t hi) {
	while (lo <= hi) {
		size_t mid = lo + ((hi-lo) / 2); // try to avoid overflow
		if (arr[mid] == value)
			return mid;
		else if (arr[mid] > value)
			hi = mid - 1;
		else
			lo = mid + 1;
	}
	return -1;
}

// O(log n) worst case
template<typename T>
T upper_bound(T const& value, T arr[], size_t lo, size_t hi) {
	while (lo <= hi) {
		size_t mid = lo + ((hi-lo) / 2); // try to avoid overflow
		if (arr[mid] > value)
			hi = mid - 1;
		else
			lo = mid + 1;
	}
	return lo;
}

// O(log n) worst case
template<typename T>
T lower_bound(T const& value, T arr[], size_t lo, size_t hi) {
	while (lo <= hi) {
		size_t mid = lo + ((hi-lo) / 2); // try to avoid overflow
		if (arr[mid] >= value)
			hi = mid - 1;
		else
			lo = mid + 1;
	}
	return lo;
}

#endif
