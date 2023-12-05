#include "../../include/day03.h"
#include <iostream>
#include <sstream>

void Day03::run()
{

	std::ifstream infile("./challenges/day03/input.txt");
	partOne(infile);
	partTwo(infile);
}

void Day03::partOne(std::ifstream &infile)
{
	std::cout << "\nRunning Day 3 - Part 1\n";
	std::vector<std::vector<char>> grid;
	int partNumberSum = 0;
	char currentChar;
	std::string line;

	if (infile.is_open())
	{
		std::cout << "Opened file\n";

		while (std::getline(infile, line))
		{
			std::stringstream ss(line);
			std::vector<char> currentLineChars;
			while (ss >> currentChar)
			{
				currentLineChars.push_back(currentChar);
			}
			grid.push_back(currentLineChars);
		}

		bool isAdjacentToSymbol;
		int completeNumber = 0;
		for (int y = 0; y < grid.size(); y++)
		{
			for (int x = 0; x < grid[y].size(); x++)
			{
				char ch = grid[y][x];
				if (std::isdigit(ch))
				{
					int numberfiedChar = ch - '0';
					completeNumber = completeNumber * 10 + numberfiedChar;
					isAdjacentToSymbol = isAdjacentToSymbol || isSymbolAdjacent(grid, x, y);
				}
				else if (completeNumber > 0)
				{
					if (isAdjacentToSymbol)
					{
						partNumberSum += completeNumber;
						isAdjacentToSymbol = false;
					}
					completeNumber = 0;
				}

				if (x == grid[y].size() - 1 && completeNumber > 0)
				{
					if (isAdjacentToSymbol)
					{
						partNumberSum += completeNumber;
						isAdjacentToSymbol = false;
					}
					completeNumber = 0;
				}
			}
		}

		std::cout << "Sum: " << partNumberSum << "\n";
	}
	else
	{
		std::cout << "Could not open file\n";
	}
}

void Day03::partTwo(std::ifstream &infile)
{
	std::cout << "\nRunning Day 3 - Part 2\n";
	std::vector<std::vector<char>> grid;
	int partNumberSum = 0;
	char currentChar;
	std::string line;

	if (infile.is_open())
	{
		infile.clear();
		infile.seekg(0, std::ios::beg);
		std::cout << "Opened file\n";

		while (std::getline(infile, line))
		{
			std::stringstream ss(line);
			std::vector<char> currentLineChars;
			while (ss >> currentChar)
			{
				currentLineChars.push_back(currentChar);
			}
			grid.push_back(currentLineChars);
		}

		int ratioSum = 0;
		int completeNumber = 0;
		for (int y = 0; y < grid.size(); y++)
		{
			for (int x = 0; x < grid[y].size(); x++)
			{
				char ch = grid[y][x];
				if (ch == '*'){
					ratioSum += getSurroundingNumbers(grid, x, y);
				}
			}
		}

		std::cout << "Sum: " << ratioSum << "\n";
	}
	else
	{
		std::cout << "Could not open file\n";
	}
}

bool Day03::isSymbolAdjacent(std::vector<std::vector<char>> &grid, int x, int y)
{
	int minX = x == 0 ? x : x - 1;
	int maxX = x < grid[y].size() - 1 ? x + 1 : x;
	int minY = y == 0 ? y : y - 1;
	int maxY = y < grid.size() - 1 ? y + 1 : y;

	for (int i = minY; i <= maxY; i++)
	{
		for (int j = minX; j <= maxX; j++)
		{
			if (i == y && j == x)
				continue;
			if (!std::isdigit(grid[i][j]) && grid[i][j] != '.')
			{
				return true;
			}
		}
	}
	return false;
}

int Day03::getSurroundingNumbers(std::vector<std::vector<char>> &grid, int x, int y){
	int minX = x == 0 ? x : x - 1;
	int maxX = x < grid[y].size() - 1 ? x + 1 : x;
	int minY = y == 0 ? y : y - 1;
	int maxY = y < grid.size() - 1 ? y + 1 : y;

	int numberCnt = 0;
	int currNumber = 0;
	int ratio = 0;
	bool gettingNumber;
	for (int i = minY; i <= maxY; i++)
	{
		gettingNumber = false;
		for (int j = minX; j <= maxX; j++)
		{
			if (i == y && j == x){
				if (gettingNumber){
					gettingNumber = false;
				}
				continue;
			}

			if (std::isdigit(grid[i][j]) && !gettingNumber){
				gettingNumber = true;
				int startIndex = j;
				while (std::isdigit(grid[i][startIndex])){
					startIndex++;
				}

				currNumber = getAdjacentNumber(grid, startIndex - 1, i, -1);
				numberCnt++;
				if ( ratio == 0){
					ratio = currNumber;
				}
				else{
					ratio *= currNumber;
				}
			}
			else if (!std::isdigit(grid[i][j]) && gettingNumber){
				gettingNumber = false;
			 	currNumber = 0;
			}
		}
	}
	return numberCnt == 2 ? ratio : 0;
}

int Day03::getAdjacentNumber(std::vector<std::vector<char>> &grid, int x, int y, int increment){
	int number = grid[y][x] - '0';
	if (x < 0 || x >= grid[y].size() || !std::isdigit(grid[y][x])) return 0;
	return  getAdjacentNumber(grid, x + increment, y, increment) * 10 + number;
}
