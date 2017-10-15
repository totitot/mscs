
#ifndef CHAINNODE__H
#define CHAINNODE__H

#include <utility>
#include <string>

class ChainNode{
public:
	ChainNode():_prev(nullptr),_next(nullptr){}
	ChainNode(ChainNode&& C):e(std::move(C.e)),_prev(nullptr),_next(nullptr){}
	using element_type = std::pair<std::string,int>;

private:
	element_type _e;
	element_type * _prev;
	element_type * _next;
	
};

#endif
