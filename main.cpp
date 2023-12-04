#include <iostream>
#include "./include/Stopwatch.h"
#include "include/day02.h"

int main(){

	Stopwatch stopwatch;
	stopwatch.start();
	Day02 challenge;
	challenge.run();
	stopwatch.stop();
	std::cout << "Total Time: " << stopwatch.getElapsedTime() << std::endl;
	return 0;
}
