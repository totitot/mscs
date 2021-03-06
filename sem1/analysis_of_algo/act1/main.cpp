// ////////////////////////////
// author: Kenth Remon Crisolo
// email: kcrisolo07@gmail.com
// ////////////////////////////

#include "statistician_unsorted.h"
#include "statistician_sorted.h"
#include "statv3.h"

int main(int argc, char* argv[]){
	StatisticianUnsorted su;
	StatisticianSorted ss;
	Statv3 s3;

	s3.add(3);
	s3.add(2);
	s3.add(1);
	s3.add(4);
	s3.add(7);
	s3.add(3);
	s3.display();
	cout << (s3.contains(0)?"true":"false") << endl;
	cout << s3.sum() << endl;
	cout << s3.mean() << endl;
	cout << s3.min() << endl;
	cout << s3.max() << endl;
	cout << s3.median() << endl;

//	su.add(2);
//	su.add(1);
//	su.add(3);
//	su.add(4);
//	su.add(7);
//	su.display();
//	cout << su.median() << endl;
//	cout << su.mean() << endl;
//	cout << su.sum() << endl;
//	su.add(2);
//	su.add(1);
//	su.add(3);
//	su.add(4);
//	su.add(7);
//	su.display();
//	cout << su.sum() << endl;
//	su.add(2);
//	su.add(1);
//	su.add(3);
//	su.add(4);
//	su.add(7);
//	su.display();
//	cout << su.sum() << endl;
//	su.remove(1);
//	su.display();
//
//	ss.add(2);
//	ss.add(1);
//	ss.add(3);
//	ss.add(4);
//	ss.add(7);
//	ss.remove(2);
//	ss.display();
//	cout << ss.median() << endl;
//	cout << ss.mean() << endl;
//	cout << ss.sum() << endl;
//	ss.add(2);
//	ss.add(1);
//	ss.add(3);
//	ss.add(4);
//	ss.add(7);
//	ss.display();
//	cout << ss.sum() << endl;
//	ss.add(2);
//	ss.add(1);
//	ss.add(3);
//	ss.add(4);
//	ss.add(7);
//	ss.display();
//	cout << ss.sum() << endl;
	
	return 0;
}
