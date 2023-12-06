#pragma once
#include <fstream>

class Day05{
	public:
		Day05() {}
		void run();

	private:
		void partOne(std::ifstream &infile);
		void partTwo(std::ifstream &infile);
};
