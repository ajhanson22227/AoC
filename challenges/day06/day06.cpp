#include "../../include/day06.h"
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <cstdint>

struct Race {
	int maxTime;
	int recordDistance;
};

void Day06::run()
{
	std::ifstream infile("./challenges/day06/input.txt");
	partOne(infile);
	partTwo(infile);
}

void Day06::partOne(std::ifstream &infile)
{
	std::cout << "Running Day 6 - Part 1\n";
	if (infile.is_open())
	{
		int winsProduct = 1;

		std::string line;
		std::map<int,int> raceTimeMap;
		std::map<int,int> raceDistanceMap;
		std::vector<Race> raceVect;
		while (std::getline(infile, line)){
			if (line.rfind("Time:", 0) == 0){
				int pos = line.find(':');
				line.erase(0, pos + 2);

				std::stringstream ss(line);
				int id = 0;
				int time = 0;
				while (ss >> time){
					raceTimeMap[++id] = time;
				}
			}
			else{
				int pos = line.find(':');
				line.erase(0, pos + 2);

				std::stringstream ss(line);
				int id = 0;
				int distance = 0;
				while (ss >> distance){
					raceDistanceMap[++id] = distance;
				}
			}
		}

		for (int i = 1; i <= raceTimeMap.size(); i++){
			Race race;
			race.maxTime = raceTimeMap[i];
			race.recordDistance = raceDistanceMap[i];
			raceVect.push_back(race);
		}

		for (auto race : raceVect){
			int possibleWins = 0;
			for (int i = 1; i <= race.maxTime; i++){
				int distance = (race.maxTime - i) * i;
				if (distance > race.recordDistance){
					possibleWins++;
				}
			}
			winsProduct *= possibleWins;
		}
		std::cout << "Sum: " << winsProduct << "\n";
	}
	else{
		std::cout << "Could not open file\n";
	}
}

void Day06::partTwo(std::ifstream &infile)
{
	std::cout << "Running Day 6 - Part 2\n";
	if (infile.is_open())
	{
		infile.clear();
		infile.seekg(0, std::ios::beg);

		std::uint64_t raceMaxTime = 0;
		std::uint64_t raceMaxDistance = 0;

		std::string line;
		while (std::getline(infile, line)){
			if (line.rfind("Time:", 0) == 0){
				int pos = line.find(':');
				line.erase(0, pos + 2);

				std::stringstream ss(line);
				std::string time;
				while (ss >> time){
					raceMaxTime = std::stoull(std::to_string(raceMaxTime) + time);
				}
			}
			else{
				int pos = line.find(':');
				line.erase(0, pos + 2);

				std::stringstream ss(line);
				std::string distance;
				while (ss >> distance){
					raceMaxDistance = std::stoull(std::to_string(raceMaxDistance) + distance);
				}
			}
		}

		bool isWinning = false;
		std::uint64_t possibleWins = 0;
		for (int i = 1; i <= raceMaxTime; i++){
			std::uint64_t distance = (raceMaxTime - i) * i;
			if (distance > raceMaxDistance){
				isWinning = true;
				possibleWins++;
			}
			else if (isWinning){
				break; //only gonna go downhill from here
			}
		}
		std::cout << "Sum: " << possibleWins << "\n";
	}
	else{
		std::cout << "Could not open file\n";
	}
}
