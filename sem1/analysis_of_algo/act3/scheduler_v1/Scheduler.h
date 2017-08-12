#include "MyQueue.h"
#include "PrintJob.h"
#include <iostream>

#ifndef SCHEDULE__H
#define SCHEDULE__H

class Scheduler{
public:
	Scheduler():
		  waiting_time(0)
		, turn_around_time(0)
	{}

	void add(PrintJob pj);
	void start();
private:
	MyQueue<PrintJob> sq;
	int waiting_time;
	int turn_around_time;;
};

#endif
