all:
	gcc -w  -g program6.c bst.c -o program6

run:program6
	gcc -w -g program6.c bst.c -o program6
	./program6

checkmem:program6
	gcc -w -g program6.c bst.c -o program6
	valgrind ./program6

clean:
	rm  program6

