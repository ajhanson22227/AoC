#include "../../include/day05.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <cstdint>

struct Map
{
	std::uint64_t source;
	std::uint64_t destination;
	std::uint64_t range;
};

void Day05::run()
{
	std::ifstream infile("./challenges/day05/input.txt");
	partOne(infile);
	//partTwo(infile); //Not running this
}

void Day05::partOne(std::ifstream &infile)
{
	std::cout << "Running Day 5 - Part 1\n";
	std::vector<std::uint64_t> seeds;
	std::vector<Map> destToSource;
	if (infile.is_open())
	{
		std::string line;
		bool calculatePos, readingNumbers = false;
		while (std::getline(infile, line))
		{
			if (line.rfind("seeds:", 0) == 0)
			{
				int pos = line.find(':');
				line.erase(0, pos + 2);

				std::uint64_t seedNumber = 0;
				std::stringstream ss(line);
				while (ss >> seedNumber)
				{
					seeds.push_back(seedNumber);
				}
				continue;
			}

			if (!std::isdigit(line[0]) && !line.empty())
			{
				destToSource.clear();
				readingNumbers = true;
				continue;
			}
			else if (line.empty())
			{
				readingNumbers = false;
				calculatePos = true;
			}

			if (readingNumbers)
			{
				std::uint64_t source, destination, range = 0;
				std::stringstream ss(line);
				while (ss >> destination >> source >> range)
				{
					Map map;
					map.destination = destination;
					map.source = source;
					map.range = range;
					destToSource.push_back(map);
				}
			}

			if (calculatePos)
			{
				for (std::uint64_t &seed : seeds)
				{
					for (Map map : destToSource)
					{
						if (seed >= map.source && seed <= map.source + map.range)
						{
							std::uint64_t diff = seed - map.source;
							seed = map.destination + diff;
							break;
						}
					}
				}
				calculatePos = false;
			}
		}

		for (std::uint64_t &seed : seeds)
		{
			for (Map map : destToSource)
			{
				if (seed >= map.source && seed < map.source + map.range)
				{
					std::uint64_t diff = seed - map.source;
					seed = map.destination + diff;
					break;
				}
			}
		}

		std::uint64_t min = -1;
		for (std::uint64_t i : seeds)
		{
			if (min == -1)
			{
				min = i;
				continue;
			}
			if (i < min)
			{
				min = i;
			}
		}
		std::cout << std::fixed << "\nPart 1 Min location " << min << "\n";
	}
	else
	{
		std::cout << "File not opened\n";
	}
}

void Day05::partTwo(std::ifstream &infile)
{
	std::cout << "Running Day 5 - Part 2\n";
	std::vector<std::uint64_t> seeds;
	std::vector<Map> destToSource;
	std::uint64_t min = -1;
	if (infile.is_open())
	{
		infile.clear();
		infile.seekg(0, std::ios::beg);

		std::string line;
		bool calculatePos, readingNumbers = false;
		while (std::getline(infile, line))
		{
			if (line.rfind("seeds:", 0) == 0)
			{
				int pos = line.find(':');
				line.erase(0, pos + 2);

				std::uint64_t seedStart, seedRange = 0;
				std::stringstream ss(line);
				while (ss >> seedStart >> seedRange)
				{
					for (std::uint64_t i = seedStart; i < seedStart + seedRange; i++)
					{
						seeds.push_back(i);
					}
				}
				continue;
			}

			if (!std::isdigit(line[0]) && !line.empty())
			{
				destToSource.clear();
				readingNumbers = true;
				continue;
			}
			else if (line.empty())
			{
				readingNumbers = false;
				calculatePos = true;
			}

			if (readingNumbers)
			{
				std::uint64_t source, destination, range = 0;
				std::stringstream ss(line);
				while (ss >> destination >> source >> range)
				{
					Map map;
					map.destination = destination;
					map.source = source;
					map.range = range;
					destToSource.push_back(map);
				}
			}

			if (calculatePos)
			{
				for (std::uint64_t &seed : seeds)
				{
					for (Map map : destToSource)
					{
						if (seed >= map.source && seed < map.source + map.range)
						{
							std::uint64_t diff = seed - map.source;
							seed = map.destination + diff;
							break;
						}
					}
				}
				calculatePos = false;
			}
		}

		for (std::uint64_t &seed : seeds)
		{
			for (Map map : destToSource)
			{
				if (seed >= map.source && seed <= map.source + map.range)
				{
					std::uint64_t diff = seed - map.source;
					seed = map.destination + diff;
					break;
				}
			}
		}

		for (std::uint64_t i : seeds)
		{
			if (min == -1)
			{
				min = i;
				continue;
			}
			if (i < min)
			{
				min = i;
			}
		}
		std::cout << std::fixed << "\nPart 2 Min location " << min << "\n";
	}
	else
	{
		std::cout << "File not opened\n";
	}
}
