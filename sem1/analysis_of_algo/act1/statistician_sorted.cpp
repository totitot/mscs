// ////////////////////////////
// author: Kenth Remon Crisolo
// email: kcrisolo07@gmail.com
// ////////////////////////////

#include <cstring>
#include "statistician_sorted.h"
#include "binary_search.h"
#include "quicksort.h"

// O(1) to add at end
// O(nlogn) to sort
// O(n) to resize/expand
void StatisticianSorted::add( int data ){
	arr[ref_cnt] = data;
	ref_cnt++;

	quicksort(arr,0,ref_cnt-1);

	if( ref_cnt == capacity ){
		resize(capacity);
	}

	return;
}

// Copies to a temporary buffer before expanding
// O(n)
void StatisticianSorted::resize( int start_size ){
	int * temp_buf = new int[start_size];
	memcpy(temp_buf,arr,start_size*sizeof(int));
	delete [] arr;
	arr = new int[start_size+10];
	memcpy(arr,temp_buf,start_size*sizeof(int));
	delete [] temp_buf;

	return;
}

// remove entries with value of data
// O(log n) for check for multiple entries 
// O(n) for copying from temp_buf
void StatisticianSorted::remove( int data ){
	int * temp_buf = new int[ref_cnt];
	int lb = lower_bound(data, arr, 0, ref_cnt);
	int ub = upper_bound(data, arr, 0, ref_cnt);
	cout << "lb : " << lb << " ub: " << ub << endl;

	for( int i = 0; i < lb; i++ ){
		temp_buf[i] = arr[i];
	}

	for( int i = ub; i < ref_cnt; i++ ){
		temp_buf[lb+i-ub] = arr[i];
	}

	for( int i = 0; i < ref_cnt-(ub-lb); i++ ){
		arr[i] = temp_buf[i];
	}

	ref_cnt -= (ub-lb);

	delete[] temp_buf;

	return;
}

// worst case no match or end of array O(n)
// best case at beginning of array O(1)
bool StatisticianSorted::contains( int data ){
	return (binary_search(data,arr,0,ref_cnt)>=0);
}

// O(n)
int StatisticianSorted::sum(){
	int ret = 0;

	for( int i = 0; i < ref_cnt; i++ ){
		ret += arr[i];
	}

	return ret;
	
}

// O(1)
int StatisticianSorted::min(){
	return (arr[0]);
}

// O(1)
int StatisticianSorted::max(){
	return (arr[ref_cnt]);
}

// O(n) because of sum()
float StatisticianSorted::mean(){
	return (sum()/static_cast<float>(ref_cnt));
}

// median is always at the middle
// O(1)
int StatisticianSorted::median(){
	return (arr[ref_cnt/2]);
}

// display all contents
// O(n)
void StatisticianSorted::display(){
	for( int i = 0; i < ref_cnt; i++ ){
		cout << arr[i] << " ";
	}
	cout << endl;

	return;
}

