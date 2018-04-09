
#include "stdio.h"
#include "filehandle.h"
#include "stringhandle.h"
#include <stdbool.h>
#define MAXSIZE 10000
int binary(int i);
int main(int argc, char** argv){
char string[MAXSIZE];
int  intchunk;
char chunk18[8];
char chunk28[8];
char sum[32];

char chunk116[16];
char chunk216[16];

char chunk132[32];
char chunk232[32];

	switch(argv[1][0]){

		case '8':
		strcpy(string ,givemestring(argv[2]));
		intchunk = string[0];
		printf("%i", binary(intchunk));
			//bool x;
			//x= true + true;
			//printf("%i",x);






		break;

		case '1':
		if(argv[1][1]!=8){
			fprintf( stderr, "Valid checksum sizes are 8, 16, or 32\n");
			return 1;

		}


		break;

		case '3':

			if(argv[1][1]!=2){
				fprintf( stderr, "Valid checksum sizes are 8, 16, or 32\n");
				return 1;

			}

		break;


		default:
			fprintf( stderr, "Valid checksum sizes are 8, 16, or 32\n");

	}




}



int binary(int i){

if(i==0){

	return 0;
}
else
{
	return (i % 2 + 10 * binary(i / 2));
}

}