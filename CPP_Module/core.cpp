#include "core.h"

function::function()
{
	// Constructor
}

void function::add_block(block b)
{
	blocks.push_back(b);
}

float function::eval(float t)
{
	float value = 0;
	
	for (auto b : blocks)
	{
		value += b.eval_block(t);
	}

	return value;
}

core::core()
{
	// Constructor
}

void core::set_range(float T0, float T, int N)
{
	this->T0 = T0;
	this->T = T;
	this->N = N;
}

void core::set_function(function F)
{
	this->F = F;
}

void core::approximate(float initial_condition)
{
	X.resize(N + 1);
	V.resize(N + 1);

	float delta_t = (T - T0) / N;

	V[0] = initial_condition;
	X[0] = T0;
	for (size_t i = 1; i < N + 1; ++i)
	{
		X[i] = T0 + i * delta_t;
		V[i] = V[i - 1] + delta_t*(F.eval(T0 + delta_t*(i-1)));
	}
}

std::vector<float> core::get_nodes()
{
	return X;
}

std::vector<float> core::get_values()
{
	return V;
}