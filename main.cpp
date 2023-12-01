#include <iostream>
#include "./include/Stopwatch.h"
#include "include/day01.h"

int main(){

	Stopwatch stopwatch;
	stopwatch.start();
	Day01 day01;
	day01.run();
	stopwatch.stop();
	std::cout << "Total Time: " << stopwatch.getElapsedTime() << std::endl;
	return 0;
}
