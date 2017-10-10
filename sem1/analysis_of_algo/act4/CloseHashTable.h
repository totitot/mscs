
#ifndef CLOSEHASHTABLEBASE__H
#define CLOSEHASHTABLEBASE__H

#include "HashTableBase.h"

class CloseHashTable: public HashTableBase{
public:

	// add element to the hash table
	virtual void add(const element_type& e) override;

	// return index where element can be found
	virtual bool find(const element_type::first_type& key) override;

	// remove index from tree
	virtual bool remove(const element_type& dt) override;

private:

};

#endif

