///////////////////////////////
//
// author: Kenth Remon Crisolo
// email: kcrisolo07@gmail.com
//
///////////////////////////////

#include "PrintJob.h"
#include "MyQueue.h"
#include "MyPriorityQueue.h"
#include "PrintJob.h"
#include "PrintJobComparator.h"
#include <random>
#include <iostream>

using namespace std;
using test_queue1 = MyQueue<PrintJob>;
using test_queue2 = MyPriorityQueue<PrintJob,PrintJobComparator>;

int main( int argc, char * argv[] ){
	test_queue1 tq1;
	test_queue2 tq2;

	random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 500);
    uniform_int_distribution<> test_cnt(10, 20);

	int tests(test_cnt(gen));
	int wait_time(0), turn_around_time(0), num_page(0);

	cout << "Number of jobs: " << tests << endl;

	for( int i = 0; i < tests; i++ ){
		PrintJob pj(dis(gen));
		cout << "Generated page: "<< pj.pages << endl;
		tq1.enqueue(pj);
		tq2.enqueue(pj);
	}


	cout << "\nQueue jobs: " << endl;
	while(!tq1.isEmpty()){
		num_page = tq1.peek().pages;
		turn_around_time += num_page;
		cout << "pages: "<< num_page << " wait time: " << wait_time << " turn around time: " << turn_around_time << endl;
		wait_time += num_page;
		tq1.dequeue();
	}

	cout << "average wait time: " << (wait_time/static_cast<float>(tests)) << " turn around time: " << (turn_around_time/static_cast<float>(tests)) << endl;

	wait_time = turn_around_time = 0;

	cout << "\nPriority Queue jobs: " << endl;
	while(!tq2.isEmpty()){
		num_page = tq2.peek().pages;
		turn_around_time += num_page;
		cout << "pages: "<< num_page << " wait time: " << wait_time << " turn around time: " << turn_around_time << endl;
		wait_time += num_page;
		tq2.dequeue();
	}

	cout << "average wait time: " << (wait_time/static_cast<float>(tests)) << " turn around time: " << (turn_around_time/static_cast<float>(tests)) << endl;


	return 0;
}
