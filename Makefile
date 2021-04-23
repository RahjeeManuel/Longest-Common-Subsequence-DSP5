#builds dsp5.exe
all: dsp5.exe

dsp5.exe: main.o LcsAlg.o
	g++ -o dsp5.exe main.o LcsAlg.o
main.o: main.cpp
	g++ -c main.cpp
LcsAlg.o: LcsAlg.cpp
	g++ -c LcsAlg.cpp

clean:
	rm *.o dsp5.exe