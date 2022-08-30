main:
	g++ -c *.cpp
	g++ -o main *.o

run: main
	./main

clean:
	rm *.o main

reset: 
	make clean
	make
	make run
