#include "reader.h"

reader::reader()
{
	// <...>
}

std::string reader::get_expression()
{
	std::string expr;
	std::cout << " Enter right-hand side, F(t): ";
	getline(std::cin, expr);

	return expr;
}

void reader::save_data(std::vector<float> X, std::vector<float> V, std::string filename)
{
	std::ofstream outfile;
	outfile.open(filename, 'r');

	if (filename.find(".txt") == std::string::npos)
	{
		std::cout << " [Error] Wrong file format. " << std::endl;
		return;
	}

	if (!outfile.is_open())
	{
		std::cout << " [Error] Failed to open " << filename << std::endl;
		return;
	}

	if (X.size() != V.size())
	{
		std::cout << " [Error] Length of X is not equal to length of V." << std::endl;
		return;
	}
	
	size_t i = 0;
	for (i = 0; i < X.size() - 1; ++i)
	{
		outfile << X[i] << " " << V[i] << std::endl;
	}
	outfile << X[i] << " " << V[i];

	std::cout << " [Logs] Output to " << filename << " done." << std::endl;
	outfile.close();
}