///////////////////////////////
//
// author: Kenth Remon Crisolo
// email: kcrisolo07@gmail.com
//
///////////////////////////////

#include "PrintJob.h"
#include "MyQueue.h"
#include "PrintJob.h"
#include <random>
#include <iostream>

using namespace std;


int main( int argc, char * argv[] ){
	MyQueue<PrintJob> mq;

	random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 500);
    uniform_int_distribution<> test_cnt(10, 20);

	int tests(test_cnt(gen));
	int cnt(0), wait_time(0), turn_around_time(0), num_page(0);

	for( int i = 0; i < tests; i++ ){
		mq.enqueue(PrintJob(dis(gen)));
	}


	cout << "number of jobs: " << tests << endl;

	while(!mq.isEmpty()){
		num_page = mq.peek().pages;
		turn_around_time += num_page;
		cout << "wait time: " << wait_time << " turn around time: " << turn_around_time << endl;
		wait_time += num_page;
		mq.dequeue();
	}

	cout << "average wait time: " << (wait_time/static_cast<float>(tests)) << " turn around time: " << (turn_around_time/static_cast<float>(tests)) << endl;

	return 0;
}
