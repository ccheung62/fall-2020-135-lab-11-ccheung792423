main: main.o profile.o network.o
	g++ --std=c++11 -o main main.o profile.o network.o

tests: tests.o profile.o network.o
	g++ -std=c++11 -o tests tests.o profile.o network.o

profile.o: profile.cpp profile.h

network.o: network.cpp network.h
	g++ --std=c++11 -c network.cpp

tests.o:
	g++ -std=c++11 -c tests.cpp

clean:
	rm -f main.o profile.o network.o tests.o
