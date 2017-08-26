///////////////////////////////
//
// author: Kenth Remon Crisolo
// email: kcrisolo07@gmail.com
//
///////////////////////////////

#ifndef MYQUEUEBASE__H
#define MYQUEUEBASE__H

template<typename T>
class MyQueueBase{
public:
	virtual void enqueue(T x) = 0;
	virtual void dequeue() = 0;
	virtual T peek() const = 0;
	virtual bool isEmpty() = 0;
	virtual void clear() = 0;
};

#endif
