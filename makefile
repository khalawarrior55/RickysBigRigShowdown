test: main.o Entity.o Player.o Banjo.o
	g++ main.o Entity.o Player.o Banjo.o -o test.exe -lsfml-graphics -lsfml-window -lsfml-system -lsfml-system -lsfml-audio
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
Entity.o: Entity.cpp
	g++ -std=c++11 -c Entity.cpp
Player.o: Player.cpp
	g++ -std=c++11 -c Player.cpp
Banjo.o: Banjo.cpp
	g++ -std=c++11 -c Banjo.cpp
clean:
	 rm *.o *.exe
