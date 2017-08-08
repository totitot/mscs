// ////////////////////////////
// author: Kenth Remon Crisolo
// email: kcrisolo07@gmail.com
// ////////////////////////////

#include <iostream>
#include "node.h"

#ifndef STATV3__H
#define STATV3__H
using namespace std;


class Statv3{
public:
	Statv3(): root(nullptr),ref_cnt(0){}

	void add( int data );
	void display();
	bool contains( int data );
	int sum();
	int min();
	int max();
	int median();
	float mean();
	void remove(int data);

private:
	Node * root;
	int ref_cnt;
	Node * search(Node * current_node, int data);
	
};

#endif
