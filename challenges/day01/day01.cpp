#include "../../include/day01.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <ctype.h>
#include <map>

void Day01::run()
{
	std::cout << "\nRunning Day 1\n";
	int sum = 0;
	std::ifstream infile("./challenges/day01/input.txt");
	std::string line;
	if (infile.is_open())
	{
		std::cout << "reading file\n";

		while (std::getline(infile, line))
		{

			int lineNumber = getNumber(line);
			sum += lineNumber;
		}
	}
	else
	{
		std::cout << "could not open file\n";
	}
	std::cout << "Sum: " << sum << "\n";
}

int Day01::getNumber(std::string &line)
{
	int firstNum, lastNum = 0;
	bool firstNumFound = false;
	replaceWords(line);
	for (char &ch : line)
	{
		if (std::isdigit(ch))
		{
			if (!firstNumFound)
			{
				lastNum = firstNum = ch - '0';
				firstNumFound = true;
			}
			else
			{
				lastNum = ch - '0';
			}
		}
	}
	return (firstNum * 10 + lastNum);
}

void Day01::replaceWords(std::string &line)
{
	std::map<std::string, int> wordToInt;

	wordToInt["one"] = 1;
	wordToInt["two"] = 2;
	wordToInt["three"] = 3;
	wordToInt["four"] = 4;
	wordToInt["five"] = 5;
	wordToInt["six"] = 6;
	wordToInt["seven"] = 7;
	wordToInt["eight"] = 8;
	wordToInt["nine"] = 9;

	for (auto const &[key, val] : wordToInt)
	{
		replaceAll(line, key, val);
	}
}

void Day01::replaceAll(std::string &line, std::string wordToFind, int numToReplaceAs)
{
	std::size_t pos = 0;
	while ((pos = line.find(wordToFind, pos)) != std::string::npos)
	{
		std::string replacement = wordToFind + std::to_string(numToReplaceAs) + wordToFind;
		line.erase(pos, wordToFind.length());
		line.insert(pos, replacement);
		pos += (wordToFind.length() + 2);
	}
}
