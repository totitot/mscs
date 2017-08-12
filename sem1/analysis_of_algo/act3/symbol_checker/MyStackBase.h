
#ifndef MYSTACKBASE__H
#define MYSTACKBASE__H

template<typename T>
class MyStackBase{
public:

	virtual void push(T x) = 0;
	virtual void pop() = 0;
	virtual T peek() const = 0;
	virtual bool isEmpty() = 0;
	virtual void clear() = 0;
};

#endif
