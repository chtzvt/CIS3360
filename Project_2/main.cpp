
#include "stdio.h"
#include "filehandle.h"
#include "stringhandle.h"
#include <stdbool.h>
#define MAXSIZE 10000
int binary(int i);
int binadd(char *v1, char *v2);
int main(int argc, char** argv){
char string[MAXSIZE];
int  intchunk;
char chunk18[9];
char chunk28[9];
char sum[33];

char chunk116[17];
char chunk216[17];

char chunk132[33];
char chunk232[33];

	switch(argv[1][0]){

		case '8':
		strcpy(string ,givemestring(argv[2]));
	lprintf(string);
		//printf("%i \n",string[0]);
			for(int j=0 ; string[j]!=0;j++) {
				intchunk = string[j];

				sprintf(chunk18,"%i", binary(intchunk));
				//printf("%s ",chunk18);

				if( j==0){
					intchunk = string[1];


					sprintf(chunk28,"%i\0", binary(intchunk));
					j++;
				}
				int p=strlen(chunk18);
				//printf("%i",p);
				if(p<8){
				chunk18[8]=0;
				p--;
				int o=7;
				for(o=7;p!=0;p--) {
				chunk18[o]=chunk18[p];
				o--;

				}
					o--;
				while(o!=-1) {

					chunk18[o] = '0';
					o--;
					//puts("i ran");
				}


				}
				printf("%s \n",chunk18);
				binadd(chunk18,chunk28);
			}
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

int binadd(char *v1, char *v2){

	int vl = strlen(v1);


	for(int x =0; x<vl;x++){
		//printf("%s\n+\n %s \n ",v1,v2);



	}

}