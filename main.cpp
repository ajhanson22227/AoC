#include <iostream>
#include "./include/Stopwatch.h"

int main(){
	Stopwatch stopwatch;
	stopwatch.start();
	std::cout << "Hello World" << std::endl;
	stopwatch.stop();
	std::cout << "Total Time: " << stopwatch.getElapsedTime() << std::endl;
	return 0;
}
