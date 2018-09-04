all: defusebomb checkmem clean

defusebomb: bomb.o defuseMe.o hidden.o
	gcc -g -c bomb.o defuseMe.o hidden.o -o defusebomb

bomb.o:bomb.c
	gcc -g -c bomb.c -o bomb.o

defuseMe.o:defuseMe.c
	gcc -g -c defuseMe.c -o defuseMe.o

checkmem.o: program3B.c
	gcc -g program3B.c -o checkmem.o

checkmem:checkmem.o	
	valgrind ./checkmem.o
	
clean: 
	sh trash.sh bomb.o checkmem.o defuseMe.o defusebomb checkmem
