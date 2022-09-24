main:
	g++ -c *.cpp
	g++ -o main *.o
	mkdir "build"
	mv *.o build/

run: main
	./main

clean:
	rm main
	rm -d -r build

reset:
	make clean
	make
	make run

debug:
	g++ -g -c *.cpp
	g++ -g -o main *.o
	mkdir "build"
	mv *.o build/
	gdb main