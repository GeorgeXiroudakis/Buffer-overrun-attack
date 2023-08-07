#include <stdio.h>
#include <stdlib.h>

int main(void){
	int i;
	FILE *file = fopen("data3", "w");
	
	if (file == NULL){
		fprintf(stderr, "couldnt crete the file: data3");
		exit(-1);
	}

	for(i = 0; i < 10000; i++){
		fputs(" oops:( ", file);
	}
	
	fclose(file);

	return 0;
}
