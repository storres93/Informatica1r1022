ejecutable :  libsock.a libusuario.a
	gcc -o servers server.c -Wall -g -lsock -lusuarios -L. -lpthread

libsock.a : libusuario.a
	gcc -c -o sock-lib.o sock-lib.c -g -Wall -lusuarios -L.
	ar rcs libsock.a sock-lib.o
libusuario.a : 
	gcc -c -o usuarios.o usuarios.c -g -Wall
	ar rcs libusuarios.a usuarios.o
clean :
	rm libusuarios.a
	rm usuarios.o
	rm libsock.a
	rm sock-lib.o
	rm servers
	rm doxy -r
	rm servidor.tar.gz
documentacion :
	doxygen doxyfile
entrega : 
	tar -cf servidor.tar.gz sock-lib.h usuarios.h libsock.a libusuarios.a server.c Makefile doxyfile