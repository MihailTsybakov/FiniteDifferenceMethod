#include "block.h"

block::block()
{
	powers["t"] = 0;
	powers["sin"] = 0;
	powers["cos"] = 0;
	powers["exp"] = 0;
	powers["sqrt"] = 0;
}

void block::update_block(std::string ID, int power)
{
	powers[ID] = power;
}

float block::eval_block(float t)
{
	float value = 1;
	value *= pow(t, powers["t"]);
	value *= pow(sin(t), powers["sin"]);
	value *= pow(cos(t), powers["cos"]);
	value *= pow(exp(t), powers["exp"]);
	value *= pow(sqrt(t), powers["sqrt"]);

	if (value == 1) value = 0;
	return value;
}