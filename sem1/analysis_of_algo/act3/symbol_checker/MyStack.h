///////////////////////////////
//
// author: Kenth Remon Crisolo
// email: kcrisolo07@gmail.com
//
///////////////////////////////

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

	virtual void push(T x) override{
		int_stack.push(x);
	}

	virtual void pop() override{
		int_stack.pop();
	}

	virtual T peek() const override{
		return int_stack.top();
	}

	virtual bool isEmpty() override{
		return int_stack.empty();
	}

	virtual void clear() override{
		while( int_stack.empty() ){
			int_stack.pop();
		}
	}

private:
	std::stack<T> int_stack;
};



#endif

