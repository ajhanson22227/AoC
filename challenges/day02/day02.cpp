#include "../../include/day02.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <ctype.h>
#include <map>
#include <algorithm>

struct Cube{
		int red = 0;
		int green = 0;
		int blue = 0;
};

void Day02::run()
{
	std::ifstream infile("./challenges/day02/input.txt");
	partOne(infile);
	infile.clear();
	infile.seekg(0, std::ios::beg);
	partTwo(infile);
}

void Day02::partOne(std::ifstream &infile){
	std::cout << "\nRunning Day 2 - Part 1\n";
	std::string line;

	Cube bag;
	bag.red = 12;
	bag.green = 13;
	bag.blue = 14;

	if (infile.is_open())
	{
		std::cout << "reading file\n";
		int lineNumber = 0;
		int sum = 0;

		while (std::getline(infile, line))
		{
			bool possible = true;
			++lineNumber;
			removeBeginning(line);

			std::stringstream ss(line);
			std::string drawn;
			while (std::getline(ss, drawn, ';') && possible){
				std::stringstream st(drawn);
				int number;
				std::string color;
				while (st >> number >> color){
					if (color == "red" && bag.red < number) {
						possible = false;
					}
					else if (color == "green" && bag.green < number){
						possible = false;
					}
					else if (color == "blue" && bag.blue < number){
						possible = false;
					}
					if (!possible) break;
				}
			}

			if (possible){
				sum += lineNumber;
			}
		}
		std::cout << "Sum: " << sum << "\n";
	}
	else
	{
		std::cout << "could not open file\n";
	}
}

void Day02::partTwo(std::ifstream &infile){
	std::cout << "\nRunning Day 2 - Part 2\n";
	std::string line;

	if (infile.is_open())
	{
		infile.clear();
		infile.seekg(0, std::ios::beg);
		std::cout << "reading file\n";
		int sum = 0;

		while (std::getline(infile, line))
		{
			Cube *maxCubes = new Cube;
			maxCubes->red = 0;
			maxCubes->green = 0;
			maxCubes->blue = 0;
			removeBeginning(line);

			std::stringstream ss(line);
			std::string drawn;
			while (std::getline(ss, drawn, ';')){
				std::stringstream st(drawn);
				int number;
				std::string color;
				while (st >> number >> color){
					if (color == "red" && number > maxCubes->red) {
						maxCubes->red = number;
					}
					if (color == "green" && number > maxCubes->green) {
						maxCubes->green = number;
					}
					if (color == "blue" && number > maxCubes->blue) {
						maxCubes->blue = number;
					}
				}
			}
			size_t power = maxCubes->red * maxCubes->green * maxCubes->blue;
			sum += power;

			delete maxCubes;
		}
		std::cout << "Sum: " << sum << "\n";
	}
	else
	{
		std::cout << "could not open file\n";
	}
}

void Day02::removeBeginning(std::string &line){
	std::size_t pos = 0;
	while ((pos = line.find(":", pos)) != std::string::npos)
	{
		line.erase(0, pos+1);
	}
	line.erase(std::remove(line.begin(), line.end(), ','), line.end());
}
