
ejecutable: libclient.a
	    gcc -o UCHAT main.c  `pkg-config --cflags opencv` `pkg-config --libs opencv` -lclient -L. -lpthread

libclient.a: libclient.o
	    ar rcs libclient.a libclient.o

libclient.o:
	    gcc -c libclient.c -o libclient.o -Wall
clean:
	    rm libclient.o
	    rm libclient.a
	    rm UCHAT
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
