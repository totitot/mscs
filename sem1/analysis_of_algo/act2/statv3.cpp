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
	
}


void Statv3::display(){
	if( root != nullptr ) root->display();
	cout << endl;
	return;
}

int Statv3::sum(){
	int ret = 0;
	if( root != nullptr ) ret = root->sum();
	return ret;
}

float Statv3::mean(){
	return sum()/static_cast<float>(ref_cnt);
}

int Statv3::min(){
	int ret = 0;
	if( root != nullptr ) ret = root->min();
	return ret;
}

int Statv3::max(){
	int ret = 0;
	if( root != nullptr ) ret = root->max();
	return ret;
}

int Statv3::median(){
	int ret = 0;
	int cnt = 0;
	if( root != nullptr ) ret = root->median(cnt,(ref_cnt/2)+1);
	return ret;
}

