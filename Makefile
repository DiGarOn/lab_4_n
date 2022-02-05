all: lab_4

lab_4: main.o Zoo.o func.o
	g++ main.o Zoo.o func.o -o lab_4 

main.o: main.cpp
	g++ -c main.cpp

Zoo.o: Zoo.cpp
	g++ -c Zoo.cpp

hello.o: func.cpp
	g++ -c func.cpp

clean:
	rm -rf *.o hello