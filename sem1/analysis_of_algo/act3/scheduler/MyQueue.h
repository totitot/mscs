///////////////////////////////
//
// author: Kenth Remon Crisolo
// email: kcrisolo07@gmail.com
//
///////////////////////////////

#include "MyQueueBase.h"
#include <queue>

#ifndef MYQUEUE__H
#define MYQUEUE__H

using namespace std;

template<typename T>
class MyQueue: public MyQueueBase<T>{
public:
	virtual void enqueue(T x){
		queue_int.push(x);
		return;
	}

	virtual void dequeue(){
		queue_int.pop();
	}

	virtual T peek() const{
		return queue_int.front();
	}

	virtual bool isEmpty(){
		return queue_int.empty();
	}

	virtual void clear(){
		while( !queue_int.empty() ){
			queue_int.pop();
		}

		return;
	}

private:
	queue<T> queue_int;
};

#endif

