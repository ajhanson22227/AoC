#pragma once
#include <string>

class Day02{
	public:
		Day02() {}
		void run();

	private:
		void removeBeginning(std::string &line);
		void partOne(std::ifstream &infile);
		void partTwo(std::ifstream &infile);
};
