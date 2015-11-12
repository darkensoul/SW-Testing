SoftwareTesting: fileIO.o Student.o Students.o SoftwareTesting.o
	g++ -std=c++11 -o SoftwareTesting fileIO.o Student.o Students.o SoftwareTesting.o

SoftwareTesting.o: SoftwareTesting.cpp fileIO.h Student.h Students.h
	g++ -std=c++11 -c SoftwareTesting.cpp

fileIO.o: fileIO.cpp fileIO.h
	g++ -std=c++11 -c fileIO.cpp

Student.o: Student.cpp Student.h
	g++ -std=c++11 -c Student.cpp

Students.o: Students.cpp Students.h
	g++ -std=c++11 -c Students.cpp

run:
	@MAKE && ./SoftwareTesting


clean:
	rm SoftwareTesting fileIO.o Student.o Students.o SoftwareTesting.o
