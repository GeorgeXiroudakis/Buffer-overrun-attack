# Buffer-overrun-attack
fourth semester assignment

## disclaimer
This project was of course made for educational purposes.

## use 
The attack only works in Linux/x87 systems and for the given hello executionable,
that is the hello.c compied with:
gcc -g -static -save-temps -ansi -Wall -pedantic -fno-pie -no-pie -fno-asynchronous-unwind-tables -o hello hello.c

the createdata#.c files when compiled and run create a text file 
that when given as the std input to the hello excecutable creates the desired result.

## intro

### hello.c

hello.c is the program that the atack is based on.
basically it askes your name and based on that it printes a personalised message
with that name and the grade it recomments you get.

it recomments 3 for everyone exept for the input Angelos Bilas(name of the proffesor)
where it recommets you get 6.

### treces
in the traces file there are the assebly instractions for the readString function of hello.c
with comments, bellow there are the addresses of some key values in from runtime.

both were extracted from the hello file using a debuger like gdb, and they are necessary to adderstant the 
stacture of the progeam in runtime and how to maniputate it with the input.

### createdata
The aim was to create 4 different stages of atack with increasing difficulty

### data3.c
should create an imput that just crash the program.

### data6, data9, data10
should create inputs wich with your name whould recomments a grade of 6, 9 and 10 accordingly

