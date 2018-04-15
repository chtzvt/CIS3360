
#include "stdio.h"
#include "filehandle.h"
#include "stringhandle.h"
#include <stdbool.h>
#define MAXSIZE 10000
int binary(int i);
char* binadd(char *v1, char *v2 , int carrysize);
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
int b;
int counter2 = 0;
int characterCnt;
	char *pointer2;
	switch(argv[2][0]) {

		case '8':
			strcpy(string, givemestring(argv[1]));
			lprintf(string);
			//printf("%i \n",string[0]);
			for (int j = 0; string[j] != 0; j++) {
				intchunk = string[j];

				sprintf(chunk18, "%i", binary(intchunk));
				//printf("%s ",chunk18);

				if (j == 0) {
					intchunk = string[1];


					sprintf(chunk28, "%i", binary(intchunk));
					j++;

				}
				/* int p=strlen(chunk28);
				//printf("%i",p);
				if(p<8){
					chunk28[8]=0;
					p--;
					int o=7;
					for(o=7;p!=0;p--) {
						chunk28[o]=chunk28[p];
						o--;

					}
					o--;
					while(o>1) {

						chunk28[o] = '0';
						o--;
						//puts("i ran");
					}


				}
			*/
				/*
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
				while(o>1) {

					chunk18[o] = '0';
					o--;
					//puts("i ran");
				}


				} */





				//printf("%s \n", chunk18);
				char *temp = binadd(chunk18, chunk28, 9);
				strcpy(chunk28, temp);


			}

			//bool x;
			//x= true + true;
			//printf("%i",x);

			pointer2 = chunk28;

			do {
				b = *pointer2 == '1' ? 1 : 0;
				counter2 = (counter2 << 1) | b;
				pointer2++;
			} while (*pointer2);
			characterCnt=strlen(string);
			printf("%s bit checksum is %8lx for all %4d chars\n", argv[2], counter2, characterCnt);





		break;

		case '1':
		if(argv[2][1]!=8){
			fprintf( stderr, "Valid checksum sizes are 8, 16, or 32\n");
			return 1;

		}


		break;

		case '3':

			if(argv[2][1]!=2){
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

char* binadd(char v1[], char v2[],int resultsize){
	//printf("the input is v1= %s v2 = %s \n",v1,v2);
	int vl1 = strlen(v1);
	int vl2 = strlen(v2);
	char result[resultsize]={0};
	resultsize--;
	
	int carry=0;
	int x =vl1-1;
	int c =vl2-1;
	char value1 , value2;
	while( resultsize>=0) {
		if (x < 0) {
			value1 = '0';
		} else {
			value1 = v1[x];
		}
		if (c < 0) {
			value2 = '0';
		} else {
			value2 = v2[c];
		}

		if ((value1 == '0') && (value2 == '0') && (carry == 0)) {
			result[resultsize - 1] = '0';
		} else if ((value1 == '0') && (value2 == '0') && (carry == 1)) {
			result[resultsize - 1] = '1';
			carry--;
		} else if ((value1 == '1') && (value2 == '0') && (carry == 0)) {
			result[resultsize - 1] = '1';
		} else if ((value1 == '1') && (value2 == '1') && (carry == 0)) {
			result[resultsize - 1] = '0';
			carry = 1;
		} else if ((value1 == '1') && (value2 == '1') && (carry == 1)) {
			result[resultsize - 1] = '1';
			carry = 1;
		} else if ((value1 == '0') && (value2 == '1') && (carry == 1)) {
			result[resultsize - 1] = '0';
			carry = 1;
		} else if ((value1 == '1') && (value2 == '0') && (carry == 1)) {
			result[resultsize - 1] = '0';
			carry = 1;
		} else if ((value1 == '0') && (value2 == '1') && (carry == 0)) {
			result[resultsize - 1] = '1';
			carry = 0;
		} else printf("missed me with v1=%c v2=%c and carry =%i", value1, value2, carry);
		x--;
		c--;
		resultsize--;
		if (x > -1){
			if (c > -1){
				goto jump;

			if (resultsize >= 1) {
				if (carry == 1) {
					result[resultsize - 1] = '1';
					resultsize--;
				}
				while (resultsize >= 1) {
					result[resultsize - 1] = '0';
					resultsize--;

				}
			}

		jump:;
	}}}

	//printf("the result is %s \n",result);
	return strdup(result);
}
