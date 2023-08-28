# Buffer-overrun-attack
fourth semester assignment

## Disclaimer
This project was of course made for educational purposes.

## Use 
The attack only works in Linux/x87 systems and for the given hello executionable,
that is the hello.c compied with:
gcc -g -static -save-temps -ansi -Wall -pedantic -fno-pie -no-pie -fno-asynchronous-unwind-tables -o hello hello.c

the createdata#.c files when compiled and run create a text file 
that when given as the std input to the hello excecutable creates the desired result.

## Intro

### Hello.c

hello.c is the program that the atack is based on.
basically it askes your name and based on that it printes a personalised message
with that name and the grade it recomments you get.

it recomments 3 for everyone exept for the input Angelos Bilas(name of the proffesor)
where it recommets you get 6.

### Treces
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

## Execution

### changing the values in the stack frame
after the name you want to display you put a \0 character so the printf stops there. After you fill the remaining 
of the buffer with characters and after that you are writing in the stack frame, as we can see form the traces we found 
after the buffer there is the verieble c so fill that with 4 characters as well to move to the i.By being able to change the 
variable i (intex of the buffer) we can treat the whole stack frame as array where we can intex it by writing in the variable i.
so we withe the intex we want in i and then then the next thing in the input will be writtern there.

### data3.c
by giving a input bigger by the buffer size the extra input is writen in the stack frame of the function.
so given a big enough input the cretical values of the stack frame are destroyed so the programm can't continue.
A more sophisticated way whould be to spesificly replace the return address on the stack frame with 
an known illegal address (for excample 0x0000).

### data6
to make the program recoment a grade of 6 is easier as the program allready has the line of code 
that changes the value of the grade to 6 (when your name is Aggelos Billas). So we just have to 
bypass the check (the if statement), so by finding the address of the asseply instaction that chages the value of the grade
we can change the return address in the functions stack frame to return in that instaction and then continue normally.

### data9
Making the program recoment a grade of 10 is more complex as there is no code present that changes the value of the grade to 9.
So we have to pash and run the code in the memory, in the inst9.c file we have the instractions we want to run.
We compile that and we can extract the hex values for those instractions. we has those hex values in the buff (in little endiant),
and set the return address to the clobal veriable name where those bites will move because there we can excecute them and then continiue normally.

Also we dont forget to reajust the s to point at the Name+offset or the name we gave will not print.

### data10
Here we have an entirely new problem not only we dont have the instaction to change the grade, but also the printf that prints it doesn't suit as 
anymore as it prints a single character ( printf("I recommend that you get a grade of %c on this assignment.\n",grade); ) so it's not possible to 
print a two digit number. So we have to run instactions that pass the arguments and call the printf (instactions are in the inst10.c file).
We pass them and run them in the same way we did with data9.
