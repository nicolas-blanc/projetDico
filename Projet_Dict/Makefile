EXECS=test1

all: $(EXECS)

#-l lib à prendre
#-L chemin
#-I
test1: main.o dico.o maillon.o lettres.o mot.o emplacement.o
	gcc -Wall -I ./include/ -L./lib/liblinux32/ -o test1 main.o dico.o maillon.o lettres.o mot.o emplacement.o -ltokenize

main.o:./src/main.c
	gcc -Wall -I ./include/ -c ./src/main.c 

dico.o:./src/dico.c
	gcc -Wall -I ./include/ -c ./src/dico.c

maillon.o:./src/maillon.c
	gcc -Wall -I ./include/ -c ./src/maillon.c

lettres.o:./src/lettres.c
	gcc -Wall -I ./include/ -c ./src/lettres.c

mot.o:./src/mot.c
	gcc -Wall -I ./include/ -c ./src/mot.c

emplacement.o:./src/emplacement.c
	gcc -Wall -I ./include/ -c ./src/emplacement.c

clean_execs:
	rm -f $(EXECS)

clean_o:
	rm -f *.o 

clean: clean_execs clean_o