///////////////////////////////
//
// author: Kenth Remon Crisolo
// email: kcrisolo07@gmail.com
//
///////////////////////////////

#include "OpenHashTable.h"

// add element to the hash table
void OpenHashTable::add(const element_type& e){
	auto index = _hash(e.first)%vec.size();
	ChainNode* crawler = vec[index];

	if(crawler == nullptr){
		vec[index] = new ChainNode(e);
	}
	else{
		while(crawler->_next != nullptr){
			crawler = crawler->_next;
		}
		crawler->_next = new ChainNode(e);
		crawler->_next->_prev = crawler;
	}

	return;
}

// check whether an element has been stored
bool OpenHashTable::find(const element_type::first_type& key){
	bool ret = false;
	auto index = _hash(key)%vec.size();
	ChainNode* crawler = vec[index];

	if(crawler != nullptr){
		if( crawler->_e.first == key) ret = true;
		else while(crawler->_next != nullptr){
			crawler = crawler->_next;
			if(crawler->_e.first == key){
				ret = true;
				break;
			}
		}
	}

	return ret;
}

// remove index from tree
bool OpenHashTable::remove(const element_type::first_type& key){
	bool ret = false;
	auto index = _hash(key)%vec.size();
	ChainNode* crawler = vec[index];

	if(crawler != nullptr){
		if(crawler->_e.first == key){
			vec[index] = crawler->_next;
			if(crawler->_next != nullptr){
				crawler->_next->_prev = nullptr;
			}
			delete crawler;
			ret = true;
		}
		else while(crawler->_next != nullptr){
			crawler = crawler->_next;
			if(crawler->_e.first == key){
				if(crawler->_prev != nullptr){
					crawler->_prev->_next = crawler->_next;
				}
				if(crawler->_next != nullptr){
					crawler->_next->_prev = crawler->_prev;
				}
				delete crawler;
				ret = true;
				break;
			}
		}
	}

	return ret;
}
