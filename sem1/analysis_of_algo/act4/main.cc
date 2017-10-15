
#include "OpenHashTable.h"
#include "CloseHashTable.h"
#include <typeinfo>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
	OpenHashTable oht;
	CloseHashTable cht;

	cout << typeid(oht.hf).name() << endl;
	cout << typeid(cht.hf).name() << endl;

	return 0;
}
