#ifndef FDM_CORE
#define FDM_CORE

#include <map>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>

#include "parser.h"

class function
{
private:
	std::vector<block> blocks;
public:
	function();

	void add_block(block b);
	float eval(float t);
};

class core
{
private:
	float T0, T;
	int N;
	std::vector<float> X, V;

	function F;
public:
	core();
	
	void set_function(function F);
	void set_range(float T0, float T, int N);
	void approximate(float initial_condition);

	std::vector<float> get_nodes();
	std::vector<float> get_values();
};

#endif//FDM_CORE
