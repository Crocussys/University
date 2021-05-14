all: main.o menu.o data.o teacher.o student.o
	g++ main.o menu.o data.o teacher.o student.o -o University
	
main.o: main.cpp
	g++ -c main.cpp
	
menu.o: menu.cpp
        g++ -c menu.cpp
 
data.o: data.cpp
        g++ -c data.cpp
 
teacher.o: teacher.cpp
        g++ -c teacher.cpp
 
student.o: student.cpp
        g++ -c student.cpp

clean:
	rm -rf *~ *.o