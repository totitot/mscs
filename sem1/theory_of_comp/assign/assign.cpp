
#include "assign.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

using namespace std;

bool Assign::operator()(string& line){
	int state = idle;
	while(state!=error||state!=end){
		switch(state){
		}
	}

	return (next_state == end);
}

bool isVar(string& str){
	int state = 0;
	int input = 0;

	for( int i = 0; i < str.length(); i++ ){
		if( isalpha(str[i]) ) input = 0;
		else if ( str[i] == '_' ) input = 1;
		else if ( isdigit(str[i]) ) input = 2;
		else input = 3;

		state = var_table[state][input];
	}

	return (state == 1);
}

bool isLit(string& str){
	int state = 0;
	int input = 0;

	for( int i = 0; i < str.length(); i++ ){
		if( str[i] == '.' ) input = 0;
		else if ( str[i] == '_' ) input = 1;
		else if ( isdigit(str[i]) ) input = 2;
		else input = 3;

		state = op_table[state][input];
	}

	return (state == 1);
}

bool isOp(string& str){
	int state = 0;
	int input = 0;

	for( int i = 0; i < str.length(); i++ ){
		if(
			   str[i] == '+'
			|| str[i] == '-'
			|| str[i] == '/'
			|| str[i] == '*'
			|| str[i] == '%'
		) input = 0;
		else input = 1;

		state = op_table[state][input];
	}

	return (state == 1);
}
