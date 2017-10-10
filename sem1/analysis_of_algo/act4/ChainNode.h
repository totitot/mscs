
#include <utility>
#include <string>

class ChainNode{
public:
	ChainNode():_prev(nullptr),_next(nullptr){}
	using element_type = std::pair<std::string,int>;

private:
	element_type _e;
	element_type * _prev;
	element_type * _next;
	
};
