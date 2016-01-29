# makefile

all: main

main: main.o achieve.o player.o game.o 
	g++-4.7 -g -o main main.o achieve.o player.o game.o
	
player.o: player.h player.cpp
	g++-4.7 -c -g player.cpp
	
game.o: game.h game.cpp
	g++-4.7 -c -g game.cpp
	
achieve.o: achieve.h achieve.cpp
	g++-4.7 -c -g achieve.cpp
	
main.o: main.h main.cpp
	g++-4.7 -c -g main.cpp
	
clean:  
	rm main
	rm *.o
run: 
	./main
test:
	./main < test_input.txt