// ////////////////////////////
// author: Kenth Remon Crisolo
// email: kcrisolo07@gmail.com
// ////////////////////////////

#include <iostream>
#include <string>

#ifndef STATISTICIAN_SORTED__H
#define STATISTICIAN_SORTED__H
using namespace std;

class StatisticianSorted{
public:
	StatisticianSorted( int i = 10 ):
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
