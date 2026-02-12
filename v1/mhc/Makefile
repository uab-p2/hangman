.PHONY: all build clean

all: build
	cd build && make -f Makefile && cd ..
	cp ./build/hangman .

build:
	cmake -S . -B build

clean:
	rm -rf build hangman cmake-build-debug