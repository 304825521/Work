objects = Node.o MinMax.o executive.o main.o 
CFLAG = -std=c++11 -g -Wall
CC = g++
memorys = valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./main Input.txt

all:  main
	./main Input.txt

main: $(objects)
	$(CC) $(CFLAG) $(objects) -o main
test: main
	$(memorys)
    
.PHONY:     clean
clean:
	rm *.o main