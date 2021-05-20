all: p5-0

p5-0: p5-0.o
	g++ p5-0.o -o p5-0

p5-0.o: grade median studentinfo p5-0.cpp
	g++ -Wall -c p5-0.cpp

grade: grade.cpp
	g++ -Wall -c grade.cpp

median: median.cpp
	g++ -Wall -c median.cpp

studentinfo: Student_info.cpp
	g++ -Wall -c Student_info.cpp

clean:
	rm -f *.o *~ p5-0
