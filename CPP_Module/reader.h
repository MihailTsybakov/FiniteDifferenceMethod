#ifndef FDM_READER
#define FDM_READER

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class reader
{
private:

public:
	reader();
	
	std::string get_expression();
	void save_data(std::vector<float> X, std::vector<float> V, std::string filename);

};

#endif//FDM_READER
