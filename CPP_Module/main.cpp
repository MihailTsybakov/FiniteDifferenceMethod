#include "reader.h"
#include "core.h"

int main()
{
	reader Reader;
	parser Parser;
	core Core;

	std::string expr = Reader.get_expression();
	std::cout << " Expression: " << expr << std::endl;

	function F;
	block B1, B2;

	B1.update_block("sin", 2);
	B2.update_block("sqrt", 1);

	F.add_block(B1);
	F.add_block(B2);

	Core.set_function(F);
	Core.set_range(0.0, 10.0, 1'000);
	Core.approximate(0.0);

	std::vector<float> X, V;

	X = Core.get_nodes();
	V = Core.get_values();

	Reader.save_data(X, V, "FDM_2.txt");
}