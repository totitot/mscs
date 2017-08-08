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
	if( lptr != nullptr ) lptr->display();
	cout << value << " ";
	if( rptr != nullptr ) rptr->display();

	return;
}

// in-order
int Node::median(int & cnt, int mid){
	int ret = 0;
	if((lptr != nullptr) && (cnt < mid)) ret = lptr->median(cnt,mid);
	cnt++;
	if( cnt == mid ){
		ret = value;
	}
	else if((rptr != nullptr) && (cnt < mid)) ret = rptr->median(cnt,mid);

	return ret;
}

// iterative, can be implemented as non-iterative using while
bool Node::contains(int data){
	bool ret = false;
	if( value == data ) ret = true;
	else if( data < value ){
		if( lptr != nullptr ) ret = lptr->contains(data);
	}
	else{
		if( rptr != nullptr ) ret = rptr->contains(data);
	}

	return ret;
}

// iterative, can be implemented as non-iterative using while
int Node::sum(){
	int ret = value;
	if( lptr != nullptr ) ret += lptr->sum();
	if( rptr != nullptr ) ret += rptr->sum();

	return ret;
}

// iterative, can be implemented as non-iterative using while
int Node::min(){
	if( lptr == nullptr ) return value;
	else{
		return lptr->min();
	}
}

// iterative, can be implemented as non-iterative using while
int Node::max(){
	if( rptr == nullptr ) return value;
	else{
		return rptr->max();
	}
}
