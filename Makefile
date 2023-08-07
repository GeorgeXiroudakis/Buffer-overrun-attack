#all: crash get6 get9 get10  
       	                                     #change all target to just get the data files or run test them.
all: data3 data6 data9 data10

crash: src/hello data3
	-./src/hello < data3
	@echo "\n" 

get6: src/hello data6
	./src/hello < data6
	@echo "\n" 

get9: src/hello data9
	./src/hello < data9
	@echo "\n" 

get10: src/hello data10
	./src/hello < data10
	@echo "\n" 

hello: src/hello.c
	gcc -g -static -save-temps -ansi -Wall -pedantic -fno-pie -no-pie -fno-asynchronous-unwind-tables -o hello src/hello.c	

data3: src/createdata3.c
	gcc src/createdata3.c -o src/createdata3
	./src/createdata3

data6: src/createdata6.c
	gcc src/createdata6.c -o src/createdata6
	./src/createdata6

data9: src/createdata9.c
	gcc src/createdata9.c -o src/createdata9
	./src/createdata9

data10: src/createdata10.c
	gcc src/createdata10.c -o src/createdata10
	./src/createdata10

clean: 
	-rm src/createdata3 src/createdata6 src/createdata9 src/createdata10
	-rm data3 data6 data9 data10

