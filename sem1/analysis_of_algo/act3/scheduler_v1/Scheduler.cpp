
#include "Scheduler.h"

void Scheduler::add(PrintJob pj){
	sq.enqueue(pj);

	return;
}

void Scheduler::start(){
	PrintJob pj;
	int cnt = 0;
	while(!sq.isEmpty()){
		
		pj = sq.peek();
		turn_around_time += pj.pages;
		cout
		<< "Job # "
		<< cnt
		<< " waiting time:"
		<< waiting_time
		<< " turn_around_time : "
		<< turn_around_time
		<< endl;
		waiting_time += pj.pages;

		sq.dequeue();
		cnt++;
	}

	return;
}
