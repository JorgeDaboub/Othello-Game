# Makefile

runothello: othellomain.o othello.o
	g++ othellomain.o othello.o -o runothello

othellomain.o: othellomain.cpp othello.h
	g++ -c -std=c++11 othellomain.cpp -o othellomain.o

othello.o: othello.cpp othello.h
	g++ -c -std=c++11 othello.cpp -o othello.o

clean:
	rm *.o runothello

