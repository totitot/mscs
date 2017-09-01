///////////////////////////////
//
// author: Kenth Remon Crisolo
// email: kcrisolo07@gmail.com
//
///////////////////////////////

#include "Assign_regex.h"
#include <iostream>
#include <regex>


using namespace std;

bool Assign_regex::operator()(string line){

	string var_re("([a-zA-Z_]\\w*)");
	string lit_re("(\\d*\\.?\\d+)");
	string op_re("([\\*\\+-/%])");
	string var_or_lit = "(" + var_re + "|" + lit_re + ")";
	string op_var_lit = "(" + op_re + "\\s*" + var_or_lit + ")";
	string str("ab = 3;");
	string assign_re = var_re + "\\s*=\\s*" + var_or_lit + "(\\s*" + op_var_lit + ")*\\s*;";
	regex re(assign_re);
	smatch sm;
	regex_match(line, sm, re);
		

	return (!sm.empty());
}
