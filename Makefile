all: main

main: main.cpp movement.hpp
	g++ main.cpp -o justwindow -lcurses 