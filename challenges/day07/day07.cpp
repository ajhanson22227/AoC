#include "../../include/day07.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <cstdint>

std::map<char, int> cardVals = {
	{'2', 2},
	{'3', 3},
	{'4', 4},
	{'5', 5},
	{'6', 6},
	{'7', 7},
	{'8', 8},
	{'9', 9},
	{'T', 10},
	{'J', 11},
	{'Q', 12},
	{'K', 13},
	{'A', 14}};

enum HandType
{
	HIGH,
	ONEPAIR,
	TWOPAIR,
	THREEKIND,
	FULLHOUSE,
	FOURKIND,
	FIVEKIND
};

struct Hand
{
	std::string cards;
	HandType handType;
	int bid;
};


void Day07::run()
{
	std::ifstream infile("./challenges/day07/input.txt");
	partOne(infile);
	partTwo(infile);
}

void Day07::partOne(std::ifstream &infile)
{
	std::cout << "Running Day 7 - Part 1\n";
	if (infile.is_open())
	{
		infile.clear();
		infile.seekg(0, std::ios::beg);

		std::string line;
		std::vector<Hand> hands;
		std::uint64_t sum = 0;

		cardVals['J'] = 11;
		while (std::getline(infile, line)){
			std::stringstream ss(line);
			std::string cards;
			int bid;
			while (ss >> cards >> bid){
				Hand hand;
				hand.cards = cards;
				hand.bid = bid;
				hands.push_back(hand);
			}
		}

		for (Hand& hand : hands){
			std::map<char, int> cardCount;

			for (char ch : hand.cards){
				cardCount[ch]++;
			}

			std::map<int, int> countedCards;
			for (const auto& [card, count] : cardCount){
				countedCards[count]++;
			}

			if (countedCards[5] == 1){
				hand.handType = FIVEKIND;
			}
			else if (countedCards[4] == 1){
				hand.handType = FOURKIND;
			}
			else if (countedCards[3] == 1 && countedCards[2] == 1){
				hand.handType = FULLHOUSE;
			}
			else if (countedCards[3] == 1){
				hand.handType = THREEKIND;
			}
			else if (countedCards[2] == 2){
				hand.handType = TWOPAIR;
			}
			else if (countedCards[2] == 1) {
				hand.handType = ONEPAIR;
			}
			else {
				hand.handType = HIGH;
			}
		}

		std::sort(hands.begin(), hands.end(), [&](const Hand&  left, const Hand& right){
			if (left.handType == right.handType){
				for (int i = 0; i < left.cards.size(); i++){
					if (left.cards[i] == right.cards[i]) continue;
					return cardVals[left.cards[i]] < cardVals[right.cards[i]];
				}
			}
			return left.handType < right.handType;
		});

		for (int i = 0; i < hands.size(); i++){
			sum = sum + (hands[i].bid * (i + 1));

		}
		std::cout << "Sum: " << sum << "\n";
	}
	else{
		std::cout << "Could not open file\n";
	}
}


void Day07::partTwo(std::ifstream &infile)
{
	std::cout << "Running Day 7 - Part 2\n";
	if (infile.is_open())
	{
		infile.clear();
		infile.seekg(0, std::ios::beg);

		std::string line;
		std::vector<Hand> hands;
		std::uint64_t sum = 0;

		while (std::getline(infile, line)){
			std::stringstream ss(line);
			std::string cards;
			int bid;
			while (ss >> cards >> bid){
				Hand hand;
				hand.cards = cards;
				hand.bid = bid;
				hands.push_back(hand);
			}
		}

		cardVals['J'] = 1;
		for (Hand& hand : hands){
			std::map<char, int> cardCount;

			for (char ch : hand.cards){
				cardCount[ch]++;
			}

			std::map<int, int> countedCards;
			for (const auto& [card, count] : cardCount){
				if (card == 'J') continue;
				countedCards[count]++;
			}

			int jokerCount = cardCount['J'];
			if (countedCards[5] == 1){
				hand.handType = FIVEKIND;
			}
			else if (countedCards[4] == 1){
				if (jokerCount == 1) hand.handType = FIVEKIND;
				else hand.handType = FOURKIND;
			}
			else if (countedCards[3] == 1 && countedCards[2] == 1){
				hand.handType = FULLHOUSE;
			}
			else if (countedCards[3] == 1){
				if (jokerCount == 1) hand.handType = FOURKIND;
				else if (jokerCount == 2) hand.handType = FIVEKIND;
				else hand.handType = THREEKIND;
			}
			else if (countedCards[2] == 2){
				if (jokerCount == 1) hand.handType = FULLHOUSE;
				else hand.handType = TWOPAIR;
			}
			else if (countedCards[2] == 1) {
				if (jokerCount == 1) hand.handType = THREEKIND;
				else if (jokerCount == 2) hand.handType = FOURKIND;
				else if (jokerCount == 3) hand.handType = FIVEKIND;
				else hand.handType = ONEPAIR;
			}
			else if (countedCards[1] > 0){
				if (jokerCount == 1) hand.handType = ONEPAIR;
				else if (jokerCount == 2) hand.handType = THREEKIND;
				else if (jokerCount == 3) hand.handType = FOURKIND;
				else if (jokerCount == 4) hand.handType = FIVEKIND;
				else hand.handType = HIGH;
			}
			else{
				//all jokers
				hand.handType = FIVEKIND;
			}
		}

		std::sort(hands.begin(), hands.end(), [&](const Hand&  left, const Hand& right){
			if (left.handType == right.handType){
				for (int i = 0; i < left.cards.size(); i++){
					if (left.cards[i] == right.cards[i]) continue;
					return cardVals[left.cards[i]] < cardVals[right.cards[i]];
				}
			}
			return left.handType < right.handType;
		});

		for (int i = 0; i < hands.size(); i++){
			sum = sum + (hands[i].bid * (i + 1));

		}
		std::cout << "Sum: " << sum << "\n";
	}
	else{
		std::cout << "Could not open file\n";
	}
}
