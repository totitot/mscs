// ////////////////////////////
// author: Kenth Remon Crisolo
// email: kcrisolo07@gmail.com
// ////////////////////////////

#include "node.h"

void Node::add( int data ){
	if( data < value ){
		if( lptr == nullptr ){
			lptr = new Node(data, this);
		}
		else{
			lptr->add(data);
		}
	}
	else{
		if( rptr == nullptr ){
			rptr = new Node(data, this);
		}
		else{
			rptr->add(data);
		}
	}
	return;
}

// in-order
void Node::display(){
	if( lptr != nullptr )
		lptr->display();

	cout << value << " ";

	if( rptr != nullptr )
		rptr->display();

	return;
}

// in-order, recursive
int Node::median(int & cnt, int mid){
	int ret = 0;

	if((lptr != nullptr) && (cnt < mid)){
		ret = lptr->median(cnt,mid);
	}

	cnt++;

	if( cnt == mid ){
		ret = value;
	}
	else if((rptr != nullptr) && (cnt < mid)){
		ret = rptr->median(cnt,mid);
	}

	return ret;
}

// recursive, can be implemented as iterative using while
Node * Node::search(int data){
	Node * ret = nullptr;
	if( value == data ) ret = this;
	else if( data < value ){
		if( lptr != nullptr ) ret = lptr->search(data);
	}
	else{
		if( rptr != nullptr ) ret = rptr->search(data);
	}

	return ret;
}

// recursive, can be implemented as iterative using while
int Node::sum(){
	int ret = value;
	if( lptr != nullptr ) ret += lptr->sum();
	if( rptr != nullptr ) ret += rptr->sum();

	return ret;
}

// recursive, can be implemented as iterative using while
int Node::min(){
	if( lptr == nullptr ) return value;
	else{
		return lptr->min();
	}
}

// recursive, can be implemented as iterative using while
int Node::max(){
	if( rptr == nullptr ) return value;
	else{
		return rptr->max();
	}
}
