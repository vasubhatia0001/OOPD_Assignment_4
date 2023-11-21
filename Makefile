all: compile link

compile: Ques1.cpp Ques2.cpp Ques3.cpp Ques4.cpp
	g++ -c Ques1.cpp
	g++ -c Ques2.cpp
	g++ -c Ques3.cpp
	g++ -c Ques4.cpp

link: 
	g++ -o Ques1 Ques1.o
	g++ -o Ques2 Ques2.o
	g++ -o Ques3 Ques3.o
	g++ -o Ques4 Ques4.o

run:
	./Ques1
	./Ques2
	./Ques3
	./Ques4

clean: 
	rm -f Ques1.o
	rm -f Ques2.o
	rm -f Ques3.o
	rm -f Ques4.o
