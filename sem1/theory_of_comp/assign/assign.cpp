///////////////////////////////
//
// author: Kenth Remon Crisolo
// email: kcrisolo07@gmail.com
//
///////////////////////////////

#include "Assign.h"
#include <cctype>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

bool Assign::operator()(string line){
	string::size_type pos = line.find(';');

	if(pos != string::npos){
		line = line.substr(0,pos) + " " + ";";
	}

	istringstream iss(line);
	string str;

	int state(0);
	int input(-1);

	while( iss >> str ){
		if( isVar(str) ) input = 0;
		else if( isLit(str) ) input = 1;
		else if( isOp(str) ) input = 2;
		else if( isSem(str) ) input = 3;
		else if( isEq(str) ) input = 4;
		else input = 5;
		state = main_table[state][input];
	}

	return (state == 4);
}

bool Assign::isVar(string& str){
	int state(0);
	int input(-1);


	for( int i = 0; i < str.length(); i++ ){
		if( isalpha(str[i]) ) input = 0;
		else if ( str[i] == '_' ) input = 1;
		else if ( isdigit(str[i]) ) input = 2;
		else input = 3;

		state = var_table[state][input];
	}

	return (state == 1);
}

bool Assign::isLit(string& str){
	int state(0);
	int input(-1);

	for( int i = 0; i < str.length(); i++ ){
		if( str[i] == '.' ) input = 0;
		else if ( isdigit(str[i]) ) input = 1;
		else input = 2;

		state = lit_table[state][input];
	}

	return (state == 2||state == 5);
}

bool Assign::isOp(string& str){
	int state(0);
	int input(-1);

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

bool Assign::isEq(string& str){
	int state(0);
	int input(-1);

	for( int i = 0; i < str.length(); i++ ){
		if(str[i] == '=') input = 0;
		else input = 1;

		state = eq_table[state][input];
	}

	return (state == 1);
}

bool Assign::isSem(string& str){
	int state(0);
	int input(-1);

	for( int i = 0; i < str.length(); i++ ){
		if(str[i] == ';') input = 0;
		else input = 1;

		state = sem_table[state][input];
	}

	return (state == 1);
}
