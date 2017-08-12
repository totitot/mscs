
#include "PrintJob.h"
#include "Scheduler.h"
#include <random>


int main( int argc, char * argv[] ){
	Scheduler sc;

	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 500);

	for( int i = 0; i < 10; i++ ){
		sc.add(PrintJob(dis(gen)));
	}

	sc.start();

	return 0;
}
