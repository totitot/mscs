// ////////////////////////////
// author: Kenth Remon Crisolo
// email: kcrisolo07@gmail.com
// ////////////////////////////

#ifndef NODE__H
#define NODE__H

#include <iostream>

using namespace std;

struct Node{
	Node(int v, Node * p):
		  value(v)
		, parent(p)
		, lptr(nullptr)
		, rptr(nullptr)
	{}

	void add(int data);
	bool contains(int data);
	void display();
	int value;
	int sum();
	int min();
	int max();
	void remove(int data);
	int median(int & cnt, int mid);
	Node * lptr, * rptr, * parent; 
};

#endif
