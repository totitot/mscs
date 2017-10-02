

#ifndef HASHTABLEBASE__H
#define HASHTABLEBASE__H

#include <utility>
#include <string>
#include <random>

using namespace std;
using element_type = std::pair<string,int>;

class HashTableBase{
public:
	virtual void add(const element_type& e) = 0;
	virtual size_t find(const element_type::first_type& key) = 0;
	virtual bool remove(const element_type& dt) = 0;
protected:
	size_t hash(const element_type::first_type& key){
		size_t sum = 0;

		// iterate through all values of the key
		for( auto c: std::as_const(key) ){
			sum += std::mt19937 gen(c);
		}

		return sum;
	}
}

#endif
