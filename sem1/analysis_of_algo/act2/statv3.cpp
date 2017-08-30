// ////////////////////////////
// author: Kenth Remon Crisolo
// email: kcrisolo07@gmail.com
// ////////////////////////////

#include "statv3.h"

void Statv3::add( int data ){
	if( root == nullptr ){
		root = new Node(data, nullptr);
	}
	else{
		root->add(data);
	}

	ref_cnt++;
	return;
}

bool Statv3::contains(int data){
	Node * ret = search(root, data);
	return (ret != nullptr);
}

Node * Statv3::search(Node * current_node, int data){
	while( (current_node != nullptr) && (data != current_node->value) ){
		if( data < current_node->value ){
			current_node = current_node->lptr;
		}
		else{
			current_node = current_node->rptr;
		}
	}
	return current_node;
}

void Statv3::remove(int data){
	Node * current_node = search(root,data);
	while(current_node != nullptr){
		// no children
		if(
			   (current_node->lptr == nullptr)
			&& (current_node->rptr == nullptr)
		){
			cout << "current_node : " << current_node->value << " has no children. " << endl;
			if( current_node == current_node->parent->lptr ){
				current_node->parent->lptr = nullptr;
			}
			else{
				current_node->parent->rptr = nullptr;
			}
			delete current_node;
			current_node = nullptr;
		}
		// only one child at lptr
		else if(
			   (current_node->lptr != nullptr)
			&& (current_node->rptr == nullptr)
		){
			cout << "current_node : " << current_node->value << " has one left children. " << endl;
			move(current_node,current_node->lptr);
		}
		// only one child at rptr
		else if(
			   (current_node->lptr == nullptr)
			&& (current_node->rptr != nullptr)
		){
			cout << "current_node : " << current_node->value << " has one right children. " << endl;
			move(current_node,current_node->rptr);
		}
		// two children
		else{
			cout << "current_node : " << current_node->value << " has two children: " << current_node->lptr->value << " and " << current_node->rptr->value << endl;
			Node * temp = minimum(current_node->rptr);
			if( temp->parent != current_node ){
				if( temp->rptr != nullptr ) move( temp, temp->rptr );
				else{
					temp->parent->lptr = nullptr;
				}
				temp->rptr = current_node->rptr;
				temp->rptr->parent = temp;
			}
			move(current_node, temp);
			temp->lptr = current_node->lptr;
			temp->lptr->parent = temp;
		}
		delete current_node;
		current_node = nullptr;
		current_node = search(root,data);
	}
}

void Statv3::move( Node * dst, Node * src ){
	cout << " move " << src->value << " to " << dst->value << endl;
	if( dst->parent == nullptr ){
		root = src;
	}
	else if( dst == dst->parent->lptr ){
		dst->parent->lptr = src;
	}
	else{
		dst->parent->rptr = src;
	}

	if( src != nullptr ){
		src->parent = dst->parent;
	}

	cout << " move done " << endl;
	return;
}

Node * Statv3::successor(Node * node){
	Node * ret = nullptr;
	if( node->rptr != nullptr ){
		ret = minimum(node->rptr);
	}
	else{
		Node * current_node = node;
		while( 
			   (current_node->parent != nullptr)
			&& (current_node == current_node->parent->rptr )
		){
			current_node = current_node->parent;
		}
		ret = current_node->parent;
	}

	return ret;
}


void Statv3::display(){
	if( root != nullptr ) root->display();
	cout << endl;
	return;
}

// recursive
int Statv3::sum(){
	int ret = 0;
	if( root != nullptr ) ret = root->sum();
	return ret;
}

float Statv3::mean(){
	return sum()/static_cast<float>(ref_cnt);
}

// iterative, can be recursive using Node::min()
int Statv3::min(){
	int ret = 0;
	// if( root != nullptr ) ret = root->min();
	Node * current_node = minimum(root);
	if( current_node != nullptr ) ret = current_node->value;
	return ret;
}

Node * Statv3::minimum(Node * current_node){
	Node * ret = current_node;
	while( ret->lptr != nullptr ){
		ret = ret->lptr;
	}
	return ret;
}

// iterative, can be recursive using Node::max()
int Statv3::max(){
	int ret = 0;
	// if( root != nullptr ) ret = root->max();
	Node * current_node = maximum(root);
	if( current_node != nullptr ) ret = current_node->value;
	return ret;
}

Node * Statv3::maximum(Node * current_node){
	Node * ret = current_node;
	while( ret->rptr != nullptr ){
		ret = ret->rptr;
	}
	return ret;
}

int Statv3::median(){
	int ret = 0;
	int cnt = 0;
	if( root != nullptr ) ret = root->median(cnt,(ref_cnt/2)+1);
	return ret;
}

