DAYS = compiles/day01.exe compiles/day02.exe compiles/day03.exe compiles/day04.exe
SW = lib/Stopwatch.cpp

aoc: day04
	g++ main.cpp -o aoc $(SW) $(DAYS)

day01:
	g++ -c challenges/day01/day01.cpp -o compiles/day01.exe

day02: day01
	g++ -c challenges/day02/day02.cpp -o compiles/day02.exe

day03: day02
	g++ -c challenges/day03/day03.cpp -o compiles/day03.exe

day04: day03
	g++ -c challenges/day04/day04.cpp -o compiles/day04.exe

clean:
	rm *.exe compiles/*.exe
