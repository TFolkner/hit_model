

build:
	g++ src/dispatcher.cpp src/main.cpp -o main

run:
	clear
	./main

rm:
	rm main