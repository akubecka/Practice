#I pledge my honor that I have abided by the Stevens Honor System.
#Alex Kubecka
#April 3, 2019
#CS 392 Assignment 3
#Makefile to compile, link and run the assignment


CC = gcc
OBJS = cs392_exec.o cs392_log.o cs392_signal.o cs392_shell.o 

cs392_shell: $(OBJS)
	$(CC) -o cs392_shell $(OBJS)

cs392_shell.o: cs392_shell.c 
	$(CC) -o cs392_shell.o -c cs392_shell.c

cs392_exec.o: cs392_exec.c 
	$(CC) -o cs392_exec.o -c cs392_exec.c 

cs392_log.o: cs392_log.c 
	$(CC) -o cs392_log.o -c cs392_log.c 

cs392_signal.o: cs392_signal.c 
	$(CC) -o cs392_signal.o -c cs392_signal.c 


clean:
	rm -f *.o cs392_shell *.log
