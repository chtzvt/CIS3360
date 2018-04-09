
#include "stdio.h"

int main(int argc, char** argv){

	switch(argv[1][0]){

		case '8':
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