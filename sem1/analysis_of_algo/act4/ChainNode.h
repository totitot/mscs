
#ifndef CHAINNODE__H
#define CHAINNODE__H

#include <utility>
#include <string>

class ChainNode{
public:
	using element_type = std::pair<std::string,int>;
	ChainNode(const element_type& other):_e(other),_prev(nullptr),_next(nullptr){}
	ChainNode(ChainNode&& C):_e(std::move(C._e)),_prev(nullptr),_next(nullptr){}

public:
	element_type _e;
	ChainNode * _prev;
	ChainNode * _next;
	
};

#endif
