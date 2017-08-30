#include <iostream>
#include <fstream>
#include "SymbolChecker.h"

void display_error(int ercode);

int main(int argc, char* argv[]){
	ifstream ifs(argv[1]);

	SymbolChecker sc;
	int ret = 0;
	ret = sc(ifs);

	display_error(ret);

	string str("(({{[[[]]]{))");
	ret = sc( str );

	display_error(ret);

	return 0;
}

void display_error(int ercode){
	switch( ercode ){
		case 1 : cout << "Unmatched } symbol!" << endl; break;
		case 2 : cout << "Unmatched ] symbol!" << endl; break;
		case 3 : cout << "Unmatched ) symbol!" << endl; break;
		default: cout << "All symbols are properly closed!" << endl;
	}

	return;
}
