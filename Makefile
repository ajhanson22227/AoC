DAYS = compiles/day01.exe compiles/day02.exe compiles/day03.exe compiles/day04.exe compiles/day05.exe compiles/day06.exe
SW = lib/Stopwatch.cpp

aoc: day06
	g++ main.cpp -o aoc $(SW) $(DAYS)

day01:
	g++ -c challenges/day01/day01.cpp -o compiles/day01.exe

day02: day01
	g++ -c challenges/day02/day02.cpp -o compiles/day02.exe

day03: day02
	g++ -c challenges/day03/day03.cpp -o compiles/day03.exe

day04: day03
	g++ -c challenges/day04/day04.cpp -o compiles/day04.exe

day05: day04
	g++ -c challenges/day05/day05.cpp -o compiles/day05.exe

day06: day05
	g++ -c challenges/day06/day06.cpp -o compiles/day06.exe

clean:
	rm *.exe compiles/*.exe
