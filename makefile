main:    main.cpp Administador.o Cliente.o 
	g++ main.cpp Administador.o Cliente.o -o main
main.o:	main.cpp Administador.h Cliente.h 
	g++ -c main.cpp
Administador:	Administador.cpp Administador.h
	g++ -c Administador.cppCliente:	Cliente.cpp Cliente.h
	g++ -c Cliente.cpp
clean:
	rm  *.o main 