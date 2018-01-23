all:
	gcc $(wildcard *.c) -o ejecutable `pkg-config --libs opencv`

clean:
	rm ejecutable --force

doxygen:
	doxygen doxygen