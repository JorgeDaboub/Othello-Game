# Makefile for othello
# By: Jorge Daboub

project: project.o othello.o
	g++ -std=c++11 project.o othello.o gfx.o -lX11 -o project

project.o: project.cpp othello.h gfx.h
	g++ -std=c++11 -c project.cpp -o project.o

othello.o: othello.cpp othello.h
	g++ -std=c++11 -c othello.cpp -o othello.o

clean:
	mv gfx.o gfx.oo
	rm *.o project
	mv gfx.oo gfx.o
