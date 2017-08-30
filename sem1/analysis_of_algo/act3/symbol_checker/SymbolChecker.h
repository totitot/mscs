///////////////////////////////
//
// author: Kenth Remon Crisolo
// email: kcrisolo07@gmail.com
//
///////////////////////////////

#include "MyStack.h"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>

#ifndef SYMBOLCHECKER__H
#define SYMBOLCHECKER__H

using namespace std;

class SymbolChecker{
public:
	int operator()(ifstream& f);
	int operator()(string& str);
private:
	MyStack<char> char_stack;
};

#endif
