#include <iostream>
#include "./include/Stopwatch.h"
#include "./include/challenges.h"

int main(){
	Day01 day01;
	Day02 day02;
	Day03 day03;
	Day04 day04;
	Day05 day05;
	Day06 day06;

	Stopwatch stopwatch;
	stopwatch.start();
	day01.run();
	stopwatch.stop();
	std::cout << "Day 01 Total Time: " << stopwatch.getElapsedTime() << "ms\n\n";

	stopwatch.reset();
	stopwatch.start();
	day02.run();
	stopwatch.stop();
	std::cout << "Day 02 Total Time: " << stopwatch.getElapsedTime() << "ms\n\n";

	stopwatch.reset();
	stopwatch.start();
	day03.run();
	stopwatch.stop();
	std::cout << "Day 03 Total Time: " << stopwatch.getElapsedTime() << "ms\n\n";

	stopwatch.reset();
	stopwatch.start();
	day04.run();
	stopwatch.stop();
	std::cout << "Day 04 Total Time: " << stopwatch.getElapsedTime() << "ms\n\n";

	stopwatch.reset();
	stopwatch.start();
	day05.run();
	stopwatch.stop();
	std::cout << "Day 05 Total Time: " << stopwatch.getElapsedTime() << "ms\n\n";

	stopwatch.reset();
	stopwatch.start();
	day06.run();
	stopwatch.stop();
	std::cout << "Day 06 Total Time: " << stopwatch.getElapsedTime() << "ms\n\n";
	return 0;
}
