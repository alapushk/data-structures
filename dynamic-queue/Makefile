all: QT1

QT1: queue.o QT1.o
	g++ -o QT1 QT1.o queue.o 

QT1.o: QT1.cpp queue.o queue.h 
	g++ -c QT1.cpp 

queue.o: queue.cpp queue.h
	g++ -c queue.cpp

clean:
	rm -f QT1 *.o

