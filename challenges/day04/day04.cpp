#include "../../include/day04.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>

void Day04::run()
{
	std::ifstream infile("./challenges/day04/input.txt");
	bothParts(infile);
}

void Day04::bothParts(std::ifstream &infile){
	std::cout << "Running Day 4 - Part 1 & 2\n";
	if (infile.is_open())
	{
		int p1Sum = 0;
		std::string line;

		int lineNum = 0;
		int p2Sum = 0;
		std::map<int,int> map;

		while (std::getline(infile, line)){
			int startPos = line.find(':') + 2;
			int winningNumbersEnd = line.find('|') - 1;
			int ticketNumbersStart = winningNumbersEnd + 3;
			int ticketSum = 0;

			map[++lineNum]++;

			std::vector<int> winningNumbers;
			std::vector<int> ticketNumbers;

			getNumbersFromString(line, startPos, winningNumbersEnd, winningNumbers);
			getNumbersFromString(line, ticketNumbersStart, line.size(), ticketNumbers);

			int copyOfLine = lineNum;
			std::sort(winningNumbers.begin(), winningNumbers.end());
			for (auto i : ticketNumbers){
				if (std::binary_search(winningNumbers.begin(), winningNumbers.end(), i)){
					ticketSum++;
					map[++copyOfLine] += map[lineNum];
				}
			}
			int pow = std::pow(2, ticketSum-1);
			p1Sum += pow;
		}

		for (auto const& [key, val] :  map){
			p2Sum += val;
		}

		std::cout << "Part 1 Sum " << p1Sum << "\n";
		std::cout << "Part 2 Sum " << p2Sum << "\n";
	}
	else{
		std::cout << "File not opened\n";
	}
}

void Day04::getNumbersFromString(std::string &line, int startPos, int endPos, std::vector<int> &vects){
	int num = 0;
	for (int i = startPos; i < endPos; i++){
		if (std::isdigit(line[i])){
			int digit = line[i]  - '0';
			num = num * 10 + digit;
		}
		else{
			if (num > 0){
				vects.push_back(num);
				num = 0;
			}
		}
	}
	if (num > 0){
		vects.push_back(num);
	}
}
