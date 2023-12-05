#pragma once
#include <string>
#include <fstream>
#include <vector>

class Day03{
	public:
		Day03() {}
		void run();

	private:
		void partOne(std::ifstream &infile);
		void partTwo(std::ifstream &infile);
		bool isSymbolAdjacent(std::vector<std::vector<char>> &grid, int x, int y);
		int getAdjacentNumber(std::vector<std::vector<char>> &grid, int x, int y, int increment);
		int getSurroundingNumbers(std::vector<std::vector<char>> &grid, int x, int y);
};
