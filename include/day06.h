#pragma once
#include <fstream>

class Day06{
	public:
		Day06() {}
		void run();

	private:
		void partOne(std::ifstream &infile);
		void partTwo(std::ifstream &infile);
};
