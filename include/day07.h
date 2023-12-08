#pragma once
#include <fstream>
#include <vector>
#include <map>

struct Hand;

class Day07
{
public:
	Day07() {}
	void run();

private:
	void partOne(std::ifstream &infile);
	void partTwo(std::ifstream &infile);
};
