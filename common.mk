INCLUDE=-I../include

all: run
main:main.cpp
	g++ -O0 -g $(INCLUDE) -o main main.cpp
run:main
	./main
clean:
	rm -rf main
