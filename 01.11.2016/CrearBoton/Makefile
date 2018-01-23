TARGET = crearBoton
LIBS = -lopencv_core -lopencv_highgui
CC = gcc
CFLAGS = -g -Wall

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)

opencv:
	wget http://www.cmake.org/files/v2.8/cmake-2.8.8.tar.gz
	tar xfvz cmake-2.8.8.tar.gz
	cd cmake-2.8.8
	cmake .
	make
	sudo make install
	wget -O OpenCV-2.4.13.tar.bz2 http://sourceforge.net/projects/opencvlibrary/files/opencv-unix/2.4.13/OpenCV-2.4.13.tar.bz2/download
	tar -xvf OpenCV-2.4.13.tar.bz2
	mkdir build
	cd build
	/usr/local/bin/cmake -D CMAKE_BUILD_TYPE=RELEASE ..
	make
	sudo make install
	sudo echo “/usr/local/lib” >> sudo /etc/ld.so.conf
	sudo ldconfig