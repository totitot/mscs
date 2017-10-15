///////////////////////////////
//
// author: Kenth Remon Crisolo
// email: kcrisolo07@gmail.com
//
///////////////////////////////

#ifndef CLOSEHASHTABLEBASE__H
#define CLOSEHASHTABLEBASE__H

#include "HashTableBase.h"
#include <vector>


class CloseHashTable: public HashTableBase{
public:
	CloseHashTable(size_t size = 64):val_vec(size),flg_vec(size,false){}

	// add element to the hash table
	virtual void add(const element_type& e) override;

	// check whether an element has been stored
	virtual bool find(const element_type::first_type& key) override;

	// remove index from tree
	virtual bool remove(const element_type::first_type& key) override;

protected:
	using val_vec_type = std::vector<element_type>;
	using flg_vec_type = std::vector<bool>;
	val_vec_type val_vec;
	flg_vec_type flg_vec;

private:
	size_t lfsr( size_t num, size_t period );

};

#endif

