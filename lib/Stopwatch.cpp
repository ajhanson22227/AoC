#include "../include/Stopwatch.h"

Stopwatch::Stopwatch() : isRunning(false) {}

void Stopwatch::start(){
	if (!isRunning){
		startTime = std::chrono::steady_clock::now();
		isRunning = true;
	}
}

void Stopwatch::stop(){
	if (isRunning){
		endTime = std::chrono::steady_clock::now();
		isRunning = false;
	}
}

void Stopwatch::reset(){
	startTime = std::chrono::steady_clock::time_point();
	endTime = std::chrono::steady_clock::time_point();
	isRunning = false;
}

double Stopwatch::getElapsedTime(){
	std::chrono::steady_clock::time_point endTimeCopy = endTime;
	if (isRunning){
		endTimeCopy = std::chrono::steady_clock::now();
	}
	std::chrono::duration<double, std::milli> elapsedTime = endTimeCopy - startTime;
	return elapsedTime.count();
}
