// ////////////////////////////
// author: Kenth Remon Crisolo
// email: kcrisolo07@gmail.com
// ////////////////////////////

#include <cstring>
#include <sstream>
#include "statistician_unsorted.h"
#include "quicksort.h"

// O(1) to add
// O(n) to resize/expand
void StatisticianUnsorted::add( int data ){
	arr[ref_cnt] = data;
	ref_cnt++;

	if( ref_cnt == capacity ){
		resize(capacity);
	}

	return;
}

// Copies to a temporary buffer before expanding
// O(n)
void StatisticianUnsorted::resize( int start_size ){
	int * temp_buf = new int[start_size];
	memcpy(temp_buf,arr,start_size*sizeof(int));
	delete [] arr;
	arr = new int[start_size+10];
	memcpy(arr,temp_buf,start_size*sizeof(int));
	delete [] temp_buf;

	return;
}

// remove entries with value of data
// O(n)
void StatisticianUnsorted::remove( int data ){
	int * temp_buf = new int[ref_cnt];
	int j = 0;
	int loop_cnt = ref_cnt;
	for( int i = 0; i < loop_cnt; i++ ){
		if( arr[i] != data ){
			temp_buf[j] = arr[i];
			j++;
		}
		else{
			ref_cnt--;
		}
	}
	memcpy(arr,temp_buf,ref_cnt*sizeof(int));
	delete[] temp_buf;

	return;
}

// worst case no match or end of array O(n)
// best case at beginning of array O(1)
bool StatisticianUnsorted::contains( int data ){
	bool match = false;
	for( int i = 0; i < ref_cnt; i++ ){
		if( arr[i] == data ){
			match = true;
			break;
		}
	}

	return match;
}

// O(n)
int StatisticianUnsorted::sum(){
	int ret = 0;

	for( int i = 0; i < ref_cnt; i++ ){
		ret += arr[i];
	}

	return ret;
	
}

// O(n)
int StatisticianUnsorted::min(){
	int ret = arr[0];

	for( int i = 1; i < ref_cnt; i++ ){
		if( arr[i] < ret ) ret = arr[i];
	}

	return ret;
}

// O(n)
int StatisticianUnsorted::max(){
	int ret = arr[0];

	for( int i = 1; i < ref_cnt; i++ ){
		if( arr[i] > ret ) ret = arr[i];
	}

	return ret;
}

// O(n) because of sum()
float StatisticianUnsorted::mean(){
	return (sum()/static_cast<float>(ref_cnt));
}

// best case O(nlogn) because of quicksort()
// worst case O(n2)
// copied to a temporary buffer to maintain "unsortedness"
int StatisticianUnsorted::median(){
	int * temp_buf = new int[ref_cnt];
	memcpy(temp_buf,arr,ref_cnt*sizeof(int));
	quicksort(temp_buf,0,ref_cnt-1);
	int ret = temp_buf[ref_cnt/2];
	delete [] temp_buf;
	return ret;
}

// display all contents
// O(n)
void StatisticianUnsorted::display(){
	for( int i = 0; i < ref_cnt; i++ ){
		cout << arr[i] << " ";
	}
	cout << endl;

	return;
}
