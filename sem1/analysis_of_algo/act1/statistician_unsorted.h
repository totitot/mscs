// ////////////////////////////
// author: Kenth Remon Crisolo
// email: kcrisolo07@gmail.com
// ////////////////////////////

#include <memory>
#include <iostream>
#include <string>

#ifndef STATISTICIAN_UNSORTED__H
#define STATISTICIAN_UNSORTED__H
using namespace std;

class StatisticianUnsorted{
public:
	StatisticianUnsorted( int i = 10 ):
		  capacity(i)
		, arr(new int [i])
		, ref_cnt(0)
	{}

	void add( int data );
	void remove(int data);
	bool contains( int data );
	int sum();
	int min();
	int max();

	float mean();
	int median();
	void display();

private:
	int capacity;
	int * arr;
	int ref_cnt;

	void resize(int);
	
};

#endif
