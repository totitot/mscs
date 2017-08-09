// ////////////////////////////
// author: Kenth Remon Crisolo
// email: kcrisolo07@gmail.com
// ////////////////////////////

#ifndef NODE__H
#define NODE__H

#include <iostream>

using namespace std;

class Statv3;

struct Node{
	Node(int v, Node * p):
		  value(v)
		, parent(p)
		, lptr(nullptr)
		, rptr(nullptr)
	{}

	friend class Statv3;

	void add(int data);
	Node * search(int data);
	void display();
	int value;
	int sum();
	int min();
	int max();
	void remove(int data);
	int median(int & cnt, int mid);

private:
	Node * lptr, * rptr, * parent; 
};

#endif
