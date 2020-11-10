main: main.o profile.o network.o
	g++ --std=c++11 -o main main.o profile.o network.o

profile.o: profile.cpp profile.h

network.o: network.cpp network.h
	g++ --std=c++11 -c network.cpp

clean:
	rm -f main.o profile.o network.o
