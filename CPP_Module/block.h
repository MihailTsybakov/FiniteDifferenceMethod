#ifndef FUNCTION_BLOCK
#define FUNCTION_BLOCK

#include <string>
#include <map>

// Block is an expression of look sin(t) * cos(t) * ...
class block
{
private:
	// Powers of block members
	std::map<std::string, int> powers;
public:
	block();

	void update_block(std::string ID, int power);
	float eval_block(float t);
};

#endif//FUNCTION_BLOCK
