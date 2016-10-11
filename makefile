test: main.o Entity.o Player.o
	g++ main.o Entity.o Player.o -o test.exe -lsfml-graphics -lsfml-window -lsfml-system -lsfml-system -lsfml-audio
main.o: main.cpp
	g++ -c main.cpp
Entity.o: Entity.cpp
	g++ -c Entity.cpp
Player.o: Player.cpp
	g++ -c Player.cpp
clean:
	 rm *.o *.exe
