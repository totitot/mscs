
#ifndef HASHTABLEBASE__H
#define HASHTABLEBASE__H

#include <utility>
#include <string>
#include <functional>

using namespace std;

class HashTableBase{
public:
	using element_type = std::pair<string,int>;
	using hash_type = std::hash<element_type::first_type>;

	// add element to the hash table
	virtual void add(const element_type& e) = 0;

	// return index where element can be found
	virtual bool find(const element_type::first_type& key) = 0;

	// remove index from tree
	virtual bool remove(const element_type& dt) = 0;

// protected:
	hash_type hf;

	size_t hash(const element_type::first_type& key){
		return hf(key);
	}

};

#endif
