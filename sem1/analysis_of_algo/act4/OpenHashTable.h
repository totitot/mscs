
#ifndef OPENHASHTABLEBASE__H
#define OPENHASHTABLEBASE__H

#include "HashTableBase.h"
#include "ChainNode.h"
#include <vector>

class OpenHashTable: public HashTableBase{
public:
	OpenHashTable(size_t size = 32):vec(size,nullptr){}

	// add element to the hash table
	virtual void add(const element_type& e) override;

	// check whether an element has been stored
	virtual bool find(const element_type::first_type& key) override;

	// remove index from tree
	virtual bool remove(const element_type& dt) override;

private:
	using vec_type = std::vector<ChainNode*>;
	vec_type vec;
	
};

#endif

