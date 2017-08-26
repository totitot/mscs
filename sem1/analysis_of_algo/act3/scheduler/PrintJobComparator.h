///////////////////////////////
//
// author: Kenth Remon Crisolo
// email: kcrisolo07@gmail.com
//
///////////////////////////////

#ifndef PRINTJOBCOMPARATOR__H
#define PRINTJOBCOMPARATOR__H

#include "PrintJob.h"

struct PrintJobComparator{
	bool operator ()(const PrintJob& p1, const PrintJob& p2 ){
		return( p1.pages > p2.pages );
	}
};

#endif
