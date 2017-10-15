
#include "OpenHashTable.h"

// add element to the hash table
void OpenHashTable::add(const element_type& e){
	auto index = _hash(e.first);
	ChainNode* crawler = vec[index%vec.size()];

	if(crawler == nullptr){
		vec[index] = std::move(e);
	}




	return;
}

// check whether an element has been stored
bool OpenHashTable::find(const element_type::first_type& key){
}

// remove index from tree
bool OpenHashTable::remove(const element_type& dt){
}
