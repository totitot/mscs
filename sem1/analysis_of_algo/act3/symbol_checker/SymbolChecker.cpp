///////////////////////////////
//
// author: Kenth Remon Crisolo
// email: kcrisolo07@gmail.com
//
///////////////////////////////

#include "SymbolChecker.h"

int SymbolChecker::operator()(ifstream& f){
	int ret = 0;
	char sym;
	if( f.is_open() && f.good() ){
		while( f >> sym ){
			cout << sym << endl;;
			if( sym == '{' || sym == '[' || sym == '(' ){
				char_stack.push(sym);
			}

			char top = 0;
			if( !char_stack.isEmpty() ) top = char_stack.peek();
			if( sym == '}' ){
				if( top == '{' && !char_stack.isEmpty() ){
					char_stack.pop();
				}
				else{
					ret = 1;
					break;
				}
			}
			else if( sym == ']' && !char_stack.isEmpty() ){
				if( top == '[' ){
					char_stack.pop();
				}
				else{
					ret = 2;
					break;
				}
			}
			else if( sym == ')' && !char_stack.isEmpty() ){
				if( top == '(' ){
					char_stack.pop();
				}
				else{
					ret = 3;
					break;
				}
			}
		}
	}
	return ret;
}

int SymbolChecker::operator()(string& str){
	int ret = 0;
	char sym;
	for( size_t i = 0; i < str.length(); i++ ){
		sym = str[i];
		cout << sym << endl;
		if( sym == '{' || sym == '[' || sym == '(' ){
			char_stack.push(sym);
		}

		char top = char_stack.peek();
		if( sym == '}' && top != '{' ){
			ret = 1;
		}
		else if( sym == ']' && top != '[' ){
			ret = 2;
		}
		else if( sym == ')' && top != '(' ){
			ret = 3;
		}
	}
	return ret;
}
