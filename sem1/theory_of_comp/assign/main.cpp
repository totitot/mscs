///////////////////////////////
//
// author: Kenth Remon Crisolo
// email: kcrisolo07@gmail.com
//
///////////////////////////////

#include "assign.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
	ifstream input_file(argv[1]);
	string line;

	Assign as;
	int lcnt(1);

	while( getline( input_file, line ) ){
		cout << "Line " << lcnt << " : \"" << line << "\" is " << (as(line)? "accepted." : "rejected.") << endl;
		lcnt++;
	}

	return 0;
}
