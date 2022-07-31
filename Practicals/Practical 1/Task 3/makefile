output: calculator.o main.o
	g++ main.o calculator.o

calculator.o: calculator.cpp calculator.h
	g++ -c calculator.cpp

main.o: main.cpp calculator.h calculator.cpp
	g++ -c main.cpp

run:
	./output

clean:
	rm *.o output