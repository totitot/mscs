#include <stack>
#include "MyStackBase.h"

#ifndef MYSTACK__H
#define MYSTACK__H

template<typename T>
class MyStack : public MyStackBase<T>{
public:
	typedef T data_type;

	MyStack(){
	}

	virtual void push(T x){
		int_stack.push(x);
	}

	virtual void pop(){
		int_stack.pop();
	}

	virtual T peek() const{
		return int_stack.top();
	}

	virtual bool isEmpty(){
		return int_stack.empty();
	}

	virtual void clear(){
		while( int_stack.empty() ){
			int_stack.pop();
		}
	}

private:
	std::stack<T> int_stack;
};



#endif

