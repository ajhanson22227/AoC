#pragma once
#include <string>

class Day01{
	public:
		Day01() {}
		void run();

	private:
		int getNumber(std::string &line);
		void replaceWords(std::string &line);
		void replaceAll(std::string &line, std::string wordToFind, int numToReplaceAs);
};
