all:	main
main: rsaHandler.o rsaTester.o
	g++ rsaTester.o rsaHandler.o -lcrypto -o main
rsaTester.o: rsaTester.cpp
	g++ rsaTester.cpp -c -Wall -Wextra
rsaHandler.o: rsaHandler.cpp rsaHandler.h
	g++ rsaHandler.cpp -c -Wall -Wextra
