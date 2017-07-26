#include <iostream>
#include <utility>

using namespace std;

template<typename T, size_t N>
T partition(T (&Array)[N], const T& lo, const T& hi ){
	auto pivot = Array[hi];
	auto i = lo-1;
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

template<typename T, size_t N>
void quicksort(T (&Array)[N], const T& lo, const T& hi ){
	if( lo < hi ){
		auto p = partition( Array, lo, hi );
		quicksort( Array, lo, p-1 );
		quicksort( Array, p+1, hi );
	}
	return;
}

int main(){
	int arr[5]={2,1,4,5,3};
	for( size_t i = 0; i < 5; i++ ){
		cout << arr[i] << " ";
	}
	cout << endl;
	quicksort(arr,0,4);
	for( size_t i = 0; i < 5; i++ ){
		cout << arr[i] << " ";
	}
	cout << endl;
	return 1;
}
