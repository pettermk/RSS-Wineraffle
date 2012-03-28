#PROJ = wineraffle
#OBJS = main.o contest.o contestant.o

#CC = g++

#$(PROJ) : $(OBJS)

all:
	/usr/local/bin/g++ -g -std=c++11 main.cpp contest.cpp contestant.cpp -o wineraffle 