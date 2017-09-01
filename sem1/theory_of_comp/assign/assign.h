///////////////////////////////
//
// author: Kenth Remon Crisolo
// email: kcrisolo07@gmail.com
//
///////////////////////////////

#include <array>
#include <string>

#ifndef ASSIGN__H
#define ASSIGN__H

using namespace std;

class Assign{
public:
	Assign():
		main_table{
			//	variable, literal, operator, semicolon, equals, others
			  {		 	1,		5, 		5, 		5, 		5,		5} // 0 lside
			, {			5,		5, 		5, 		5, 		2,		5} // 1 equals
			, {			3,		3, 		5, 		5, 		5,		5} // 2 rside - var or lit
			, {			5,		5, 		2, 		4, 		5,		5} // 3 rside - op
			, {			5,		5, 		5, 		5, 		5,		5} // 4 end
			, {			5,		5, 		5, 		5, 		5,		5} // 5 error
		}
		, var_table{
			//	alpha, underscore, number, others
			  {		1,		1, 		2, 		2} // start
			, {		1,		1, 		1, 		2} // accept
			, {		2,		2, 		2, 		2} // error
		}
		, eq_table{
			//	equal others
			  {		1,		2} // start
			, {		2,		2} // accept
			, {		2,		2} // error
		}
		, lit_table{
			//	period, number, others
			  {		4,		2, 		3} // 0 start
			, {		3,		2, 		3} // 1 wait for number
			, {		1,		2, 		3} // 2 accept
			, {		3,		3, 		3} // 3 error
			, {		3,		5, 		3} // 4 wait for number
			, {		3,		5, 		3} // 5 accept
		}
		, op_table{
			//	operators others
			  {		1,		2} // start
			, {		2,		2} // accept
			, {		2,		2} // error
		}
		, sem_table{
			//	semicolon others
			  {		1,		2} // start
			, {		2,		2} // accept
			, {		2,		2} // error
		}
	{}

	bool operator()(string line);

private:
	enum state{ idle = 0, lside = 1, eq = 2, rside = 3, sem = 4, end = 5, error = 6  };
	bool isVar(string& str);
	bool isLit(string& str);
	bool isOp(string& str);
	bool isEq(string& str);
	bool isSem(string& str);

	int main_table[6][6];
	int var_table[3][4];
	int lit_table[6][3];
	int op_table[3][2];
	int eq_table[3][2];
	int sem_table[3][2];

	// array<array<int,5>,6>main_table;
	// array<array<int,4>,3>var_table;
	// array<array<int,4>,3>lit_table;
	// array<array<int,2>,3>op_table;
	// array<array<int,2>,3>eq_table;
	// array<array<int,2>,3>sem_table;


	int state;
};


#endif 
