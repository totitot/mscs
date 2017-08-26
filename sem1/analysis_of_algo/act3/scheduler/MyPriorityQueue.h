///////////////////////////////
//
// author: Kenth Remon Crisolo
// email: kcrisolo07@gmail.com
//
///////////////////////////////

#include "MyQueueBase.h"
#include <queue>
#include <vector>

#ifndef MYPRIORITYQUEUE__H
#define MYPRIORITYQUEUE__H

using namespace std;

template<typename T, class Comp>
class MyPriorityQueue: public MyQueueBase<T>{
public:
	virtual void enqueue(T x){
		queue_int.push(x);
		return;
	}

	virtual void dequeue(){
		queue_int.pop();
	}

	virtual T peek() const{
		return queue_int.top();
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
	priority_queue<T,vector<T>,Comp> queue_int;
};

#endif

