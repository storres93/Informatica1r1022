MAIN = 		Main
FN0 =		ImagesAndLines
FN1 =		Filtro_Lineas
FN2 =		AnalisisFilas
FN3 =		Analisis1Linea
FN4 =		Corroborar_Linea
FN5 =		Lineas_Xvalues
FN6 =		CropImage

SRC = $(wildcard *.c)
EXEC = 		exe
FILE = 		Video2.avi


# Solo compila
all: $(SRC:.c=.o)
	gcc -g -o $(EXEC) $(SRC:.c=.o) -g `pkg-config --cflags --libs opencv` -lm -Wall

%.o:%.c
	gcc -c $< -o $@



# Borra
clean:
	rm -f $(EXEC) *.bin *.o *.lst *.out *~ 


# Crea el doxyfile
doxy:
	doxygen Doxyfile

