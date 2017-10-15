///////////////////////////////
//
// author: Kenth Remon Crisolo
// email: kcrisolo07@gmail.com
//
///////////////////////////////

#include "CloseHashTable.h"
#include <string>
#include <cmath>
#include <cstdint>
#include <iostream>

using namespace std;

void CloseHashTable::add(const element_type& e){
	bool succeed = false;
	auto& key = e.first;
	
	auto index = _hash(key)%val_vec.size();
	for(decltype(val_vec.size()) i = 0; i < val_vec.size(); i++){
		// if slot is not yet occupied
		if( flg_vec[index] == false ){
			val_vec[index] = e;
			flg_vec[index] = true;
			succeed = true;
			break;
		}
		else{
			// instead of using a hash function which accepts
			// the key and number of tries (i) to iterate through
			// all the values in the range 0 to val_vec.size()-1,
			// use a linear feedback shift register (lfsr)
			// with the hash value (index) as the start state;
			// lfsr cannot handle 0 so start with 1 or check 0 first
			if( index != 0 ) index = 0;
			else index = lfsr(index+(index==0),val_vec.size());
		}
	}

	// all slots have been occupied
	// resize val_vec and flg_vec
	// will create temporary containers
	if(succeed == false){
		flg_vec_type temp_flg_vec(flg_vec);
		val_vec_type temp_val_vec(val_vec);

		flg_vec.clear();
		flg_vec.resize(temp_flg_vec.size()*2,false);

		val_vec.clear();
		val_vec.resize(temp_val_vec.size()*2);

		for(size_t i = 0; i < temp_val_vec.size(); i++){
			if( temp_flg_vec[i] ) add(temp_val_vec[i]);	
		}

		add(e);
	}

	return;
}

// check whether an element has been stored
bool CloseHashTable::find(const element_type::first_type& key){
	bool ret = false;
	
	auto index = _hash(key)%val_vec.size();
	for(decltype(val_vec.size()) i = 0; i < val_vec.size(); i++){
		// if slot is not yet occupied
		if( (flg_vec[index] == true) && (val_vec[index].first == key) ){
			ret = true;
			break;
		}
		else{
			// instead of using a hash function which accepts
			// the key and number of tries (i) to iterate through
			// all the values in the range 0 to val_vec.size()-1,
			// use a linear feedback shift register (lfsr)
			// with the hash value (index) as the start state;
			// lfsr cannot handle 0 so start with 1 or check 0 first
			if( index != 0 ) index = 0;
			else index = lfsr(index+(index==0),val_vec.size());
		}
	}

	return ret;
}

// remove index from tree
bool CloseHashTable::remove(const element_type::first_type& key){
	bool ret = false;
	
	auto index = _hash(key)%val_vec.size();
	for(decltype(val_vec.size()) i = 0; i < val_vec.size(); i++){
		// if slot is not yet occupied
		if( (flg_vec[index] == true) && (val_vec[index].first == key) ){
			flg_vec[index] = false;
			ret = true;
			break;
		}
		else{
			// instead of using a hash function which accepts
			// the key and number of tries (i) to iterate through
			// all the values in the range 0 to val_vec.size()-1,
			// use a linear feedback shift register (lfsr)
			// with the hash value (index) as the start state;
			// lfsr cannot handle 0 so start with 1 or check 0 first
			if( index != 0 ) index = 0;
			else index = lfsr(index+(index==0),val_vec.size());
		}
	}

	return ret;
}

size_t CloseHashTable::lfsr(size_t index, size_t period){
	size_t ret = 0;
	
	// number of bits for the given bits
	std::uint8_t num_bits = ceil(log2(period));
	size_t bit = 0;

	// support for period 2^2 up to 2^12
	switch(num_bits){
		case 2: bit = (index >> 1) ^ index; break;
		case 3: bit = (index >> 2) ^ index; break;
		case 4: bit = (index >> 1) ^ index; break;
		case 5: bit = (index >> 1) ^ index; break;
		case 6: bit = (index >> 1) ^ index; break;
		case 7: bit = (index >> 1) ^ index; break;
		case 8: bit = (index >> 4) ^ (index >> 3) ^ (index >> 2) ^ index; break;
		case 9: bit = (index >> 4) ^ index; break;
		case 10: bit = (index >> 3) ^ index; break;
		case 11: bit = (index >> 2) ^ index; break;
		case 12: bit = (index >> 8) ^ (index >> 2) ^ (index >> 1) ^ index; break;
	}
	bit &= 1;
	ret = (bit << (num_bits-1)) | index >> 1;

	return ret;
}

