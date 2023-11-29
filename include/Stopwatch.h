#pragma once
#include <chrono>

class Stopwatch{
	public:
		Stopwatch();
		void start();
		void stop();
		void reset();
		double getElapsedTime();

	private:
		std::chrono::steady_clock::time_point startTime;
		std::chrono::steady_clock::time_point endTime;
		bool isRunning;
};
