#pragma once
#include <fstream>
#include <vector>

class Day04{
	public:
		Day04() {}
		void run();

	private:
		void bothParts(std::ifstream &infile);
		void getNumbersFromString(std::string &line, int startPos, int endPos, std::vector<int> &vects);
};
