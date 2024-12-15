.PHONY: build run
build:
	gcc main.cpp -lm

run: build
	./a.out 10