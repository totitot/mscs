#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

#ifndef ASSIGN__H
#define ASSIGN__H


class Assign{
public:
	Assign():
		main_table{
			//	variable, operator, semicolon, equals
			  {		 	1,		6, 		6, 		6} // lvalue
			, {			5,		6, 		6, 		2} // equals
			, {			3,		6, 		6, 		6} // variable
			, {			6,		2, 		5, 		1} // operator
			, {			1,		1, 		1, 		1} // semicolon
			, {			1,		6, 		6, 		6} // end
			, {			6,		6, 		6, 		6} // error
		}
		, var_table{
			//	alpha, underscore, number, others
			  {		1,		1, 		3, 		2} // start
			, {		1,		1, 		1, 		2} // accept
			, {		2,		2, 		2, 		2} // error
		}
		, lit_table{
			//	period, underscore, number, others
			  {		1,		1, 		1, 		2} // start
			, {		2,		2, 		1, 		2} // equals
			, {		2,		2, 		2, 		2} // variable
		}
		, op_table{
			//	operators others
			  {		1,		2} // start
			, {		2,		2} // equals
			, {		2,		2} // variable
		}
		, eq_table{
			//	equal others
			  {		1,		2} // start
			, {		2,		2} // equals
			, {		2,		2} // variable
		}
		, sem_table{
			//	semicolon others
			  {		1,		2} // start
			, {		2,		2} // equals
			, {		2,		2} // variable
		}
	{}

	bool operator()(string str);

private:
	bool isVar(string str);
	bool isLit(string str);
	bool isOp(string str);
	bool isEq(string str);
	bool isSem(string str);

	int main_table[6][5];
	int var_table[6][5];
	int lit_table[6][5];
	int op_table[6][5];
	int eq_table[6][5];
	int sem_table[6][5];


	int state;
};


#endif 
