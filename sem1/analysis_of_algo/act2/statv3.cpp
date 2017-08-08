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
	bool ret = false;
	if( root != nullptr ) ret = root->contains(data);
	return ret;
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

