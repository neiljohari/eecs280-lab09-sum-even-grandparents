sum_even_grandparents.exe: problem.cpp
	g++ -g -std=c++14 solution.cpp -o sum_even_grandparents.exe

clean:
	rm -f sum_even_grandparents.exe
	rm -rf sum_even_grandparents.exe.dSYM
