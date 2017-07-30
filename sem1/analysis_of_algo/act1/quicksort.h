// ////////////////////////////
// author: Kenth Remon Crisolo
// email: kcrisolo07@gmail.com
// ////////////////////////////

#include <iostream>
#include <utility>

using namespace std;

template<typename T>
T partition(T Array[], const T& lo, const T& hi ){
	T pivot = Array[hi];
	T i = lo-1;
	for( size_t j = lo; j < hi; j++ ){
		if( Array[j] < pivot ){
			i++;
			std::swap(Array[i],Array[j]);
		}
	}
	if( Array[hi] < Array[i+1] ){
		std::swap(Array[i+1],Array[hi]);
	}

	return i+1;
}

template<typename T>
void quicksort(T Array[], const T& lo, const T& hi ){
	if( lo < hi ){
		T p = partition( Array, lo, hi );
		quicksort( Array, lo, p-1 );
		quicksort( Array, p+1, hi );
	}
	return;
}

