EXECS= main

all: $(EXECS)

#-l lib à prendre
#-L chemin
#-I
main: main.o dico.o
	gcc -Wall -I ./include/ -L./lib/liblinux32/ -o test1 main.o dico.o -ltokenize

main.o:./src/main.c
	gcc -Wall -I ./include/ -c ./src/main.c 

dico.o:./src/dico.c
	gcc -Wall -I ./include/ -c ./src/dico.c

clean_execs:
	rm -f $(EXECS)

clean_o:
	rm -f *.o 

clean: clean_execs clean_o