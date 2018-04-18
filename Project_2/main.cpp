
#include "stdio.h"
#include "filehandle.h"
#include "stringhandle.h"
#include <stdbool.h>


#define MAXSIZE 10000
int binary(int i);
char* binadd(char *v1, char *v2 , int carrysize);
int main(int argc, char** argv){
char string[MAXSIZE] {0};
int  intchunk;
char chunk18[9];
char chunk28[9];
char sum[33];
char temp116[33];
char temp216[33];
char temp316[33];
char temp416[33];
char chunk116[100];
char chunk216[100];

char chunk132[33];
char chunk232[33];
int b, k;
int counter2 = 0;
unsigned long characterCnt;
int counter3;
int	intchunk2;
int y;
	int donechar;
	int digits = 1;
	char *pointer2;
	switch(argv[2][0]) {

		case '8':
			strcpy(string, givemestring(argv[1]));
			puts("");
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
			printf("%2s bit checksum is %8lx for all %4d chars\n", argv[2], counter2, characterCnt);





		break;

		case '1':
		if(argv[2][1]!='6'){
			fprintf( stderr, "Valid checksum sizes are 8, 16, or 32\n");
			return 1;

		}
			strcpy(string, givemestring(argv[1]));

			characterCnt=strlen(string);
			if(characterCnt%2==1){
				string[characterCnt]='X';
				characterCnt++;
			}
			puts("");
			lprintf(string);
			 donechar=characterCnt;
			//printf("%i \n",string[0]);

			for (int j = 0; string[j] != 0; j=j+2) {

				intchunk = binary(string[j]);
				int number =intchunk;
				digits = 1;

				while (number > 9) {
					number /= 10;
					digits++;
				}


				if( digits ==1){
					sprintf(temp116,"0000000%i",intchunk);

				}
				else if( digits ==2){
						sprintf(temp116,"000000%i",intchunk);

					}
					else if( digits==3){
					sprintf(temp116,"00000%i",intchunk);

				}
				else if( digits== 4){
					sprintf(temp116,"0000%i",intchunk);

				}
				else if( digits==5){
					sprintf(temp116,"000%i",intchunk);

				}
				else if( digits==6){
					sprintf(temp116,"00%i",intchunk);

				}
				else if( digits==7){
					sprintf(temp116,"0%i",intchunk);

				}
				else{
					sprintf(temp116,"%i",intchunk);
				}
				int k= strlen(temp116);


				y=j+1;

				if(j<=donechar || characterCnt %2 ==0) {

					intchunk2 = binary(string[y]);
					donechar--;
					int number2 =intchunk2;
					digits = 1;

					while (number2 > 9) {
						number2 /= 10;
						digits++;
					}


					if( digits ==1){
						sprintf(temp216,"0000000%i",intchunk2);

					}

					else if( digits ==2){
						sprintf(temp216,"000000%i",intchunk2);

					}
					else if( digits==3){
						sprintf(temp216,"00000%i",intchunk2);

					}
					else if( digits== 4){
						sprintf(temp216,"0000%i",intchunk2);

					}
					else if( digits==5){
						sprintf(temp216,"000%i",intchunk2);

					}
					else if( digits==6){
						sprintf(temp216,"00%i",intchunk2);

					}
					else if( digits==7){
						sprintf(temp216,"0%i",intchunk2);

					}
					else{
						sprintf(temp216,"%i",intchunk2);
					}
				}
				else {
					strcpy(temp216,"01011000");
					characterCnt++;
				}

				sprintf(chunk116, "%s%s", temp116,temp216);
				//printf("%s ",chunk18);

				if (j == 0) {
					intchunk = binary(string[2]);
					intchunk2 = binary(string[3]);
					int number =intchunk;
					digits = 1;

					while (number > 9) {
						number /= 10;
						digits++;
					}


					if( digits ==1){
						sprintf(temp116,"0000000%i",intchunk);

					}
					else if( digits ==2){
						sprintf(temp116,"000000%i",intchunk);

					}
					else if( digits==3){
						sprintf(temp116,"00000%i",intchunk);

					}
					else if( digits== 4){
						sprintf(temp116,"0000%i",intchunk);

					}
					else if( digits==5){
						sprintf(temp116,"000%i",intchunk);

					}
					else if( digits==6){
						sprintf(temp116,"00%i",intchunk);

					}
					else if( digits==7){
						sprintf(temp116,"0%i",intchunk);

					}
					else{
						sprintf(temp116,"%i",intchunk);
					}


					int number2 =intchunk2;
					digits = 1;

					while (number2 > 9) {
						number2 /= 10;
						digits++;
					}


					if( digits ==1){
						sprintf(temp216,"0000000%i",intchunk2);

					}

					else if( digits ==2){
						sprintf(temp216,"000000%i",intchunk2);

					}
					else if( digits==3){
						sprintf(temp216,"00000%i",intchunk2);

					}
					else if( digits== 4){
						sprintf(temp216,"0000%i",intchunk2);

					}
					else if( digits==5){
						sprintf(temp216,"000%i",intchunk2);

					}
					else if( digits==6){
						sprintf(temp216,"00%i",intchunk2);

					}
					else if( digits==7){
						sprintf(temp216,"0%i",intchunk2);

					}
					else{
						sprintf(temp216,"%i",intchunk2);
					}
					sprintf(chunk216, "%s%s", temp116,temp216);
					j++;
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
				char *temp = binadd(chunk116, chunk216, 17);
				strcpy(chunk216, temp);


			}

			//bool x;
			//x= true + true;
			//printf("%i",x);

			pointer2 = chunk216;
		//	printf("final binary is  %s \n",chunk216);
			do {
				b = *pointer2 == '1' ? 1 : 0;
				counter2 = (counter2 << 1) | b;
				pointer2++;
			} while (*pointer2);

			printf("%2s bit checksum is %8lx for all %4d chars\n", argv[2], counter2, characterCnt);


		break;

		case '3':

			if(argv[2][1]!='2'){
				fprintf( stderr, "Valid checksum sizes are 8, 16, or 32\n");
				return 1;

			}
			strcpy(string, givemestring(argv[1]));

			characterCnt=strlen(string);
			k=1;
			while(k!=0){
				k=characterCnt%4;
				if(k==0)
					break;
				string[characterCnt]='X';
				characterCnt++;
			}
			puts("");
			lprintf(string);

			donechar=characterCnt;
			//printf("%i \n",string[0]);

			for (int j = 0; string[j] != 0; j=j+4) {

				intchunk = binary(string[j]);
				int number =intchunk;
				digits = 1;

				while (number > 9) {
					number /= 10;
					digits++;
				}


				if( digits ==1){
					sprintf(temp116,"0000000%i",intchunk);

				}
				else if( digits ==2){
					sprintf(temp116,"000000%i",intchunk);

				}
				else if( digits==3){
					sprintf(temp116,"00000%i",intchunk);

				}
				else if( digits== 4){
					sprintf(temp116,"0000%i",intchunk);

				}
				else if( digits==5){
					sprintf(temp116,"000%i",intchunk);

				}
				else if( digits==6){
					sprintf(temp116,"00%i",intchunk);

				}
				else if( digits==7){
					sprintf(temp116,"0%i",intchunk);

				}
				else{
					sprintf(temp116,"%i",intchunk);
				}
				int k= strlen(temp116);




					intchunk2 = binary(string[j+1]);
					donechar--;
					int number2 =intchunk2;
					digits = 1;

					while (number2 > 9) {
						number2 /= 10;
						digits++;
					}


					if( digits ==1){
						sprintf(temp216,"0000000%i",intchunk2);

					}

					else if( digits ==2){
						sprintf(temp216,"000000%i",intchunk2);

					}
					else if( digits==3){
						sprintf(temp216,"00000%i",intchunk2);

					}
					else if( digits== 4){
						sprintf(temp216,"0000%i",intchunk2);

					}
					else if( digits==5){
						sprintf(temp216,"000%i",intchunk2);

					}
					else if( digits==6){
						sprintf(temp216,"00%i",intchunk2);

					}
					else if( digits==7){
						sprintf(temp216,"0%i",intchunk2);

					}

					else{
						sprintf(temp216,"%i",intchunk2);
					}


				intchunk = binary(string[j+2]);
				number =intchunk;
				digits = 1;

				while (number > 9) {
					number /= 10;
					digits++;
				}
				if( digits ==1){
					sprintf(temp316,"0000000%i",intchunk);

				}
				else if( digits ==2){
					sprintf(temp316,"000000%i",intchunk);

				}
				else if( digits==3){
					sprintf(temp316,"00000%i",intchunk);

				}
				else if( digits== 4){
					sprintf(temp316,"0000%i",intchunk);

				}
				else if( digits==5){
					sprintf(temp316,"000%i",intchunk);

				}
				else if( digits==6){
					sprintf(temp316,"00%i",intchunk);

				}
				else if( digits==7){
					sprintf(temp316,"0%i",intchunk);

				}
				else{
					sprintf(temp316,"%i",intchunk);
				}







					intchunk2 = binary(string[j+3]);
					donechar--;
					 number2 =intchunk2;
					digits = 1;

					while (number2 > 9) {
						number2 /= 10;
						digits++;
					}


					if( digits ==1){
						sprintf(temp416,"0000000%i",intchunk2);

					}

					else if( digits ==2){
						sprintf(temp416,"000000%i",intchunk2);

					}
					else if( digits==3){
						sprintf(temp416,"00000%i",intchunk2);

					}
					else if( digits== 4){
						sprintf(temp416,"0000%i",intchunk2);

					}
					else if( digits==5){
						sprintf(temp416,"000%i",intchunk2);

					}
					else if( digits==6){
						sprintf(temp416,"00%i",intchunk2);

					}
					else if( digits==7){
						sprintf(temp416,"0%i",intchunk2);

					}
					else{
						sprintf(temp416,"%i",intchunk2);
					}

				sprintf(chunk116, "%s%s%s%s", temp116,temp216,temp316,temp416);
				//printf("%s ",chunk18);

				if (j == 0) {
					intchunk = binary(string[4]);
					intchunk2 = binary(string[5]);
					int intchunk3 = binary(string[6]);
					int intchunk4 = binary(string[7]);

					int number =intchunk;
					digits = 1;

					while (number > 9) {
						number /= 10;
						digits++;
					}


					if( digits ==1){
						sprintf(temp116,"0000000%i",intchunk);

					}
					else if( digits ==2){
						sprintf(temp116,"000000%i",intchunk);

					}
					else if( digits==3){
						sprintf(temp116,"00000%i",intchunk);

					}
					else if( digits== 4){
						sprintf(temp116,"0000%i",intchunk);

					}
					else if( digits==5){
						sprintf(temp116,"000%i",intchunk);

					}
					else if( digits==6){
						sprintf(temp116,"00%i",intchunk);

					}
					else if( digits==7){
						sprintf(temp116,"0%i",intchunk);

					}
					else{
						sprintf(temp116,"%i",intchunk);
					}


					int number2 =intchunk3;
					digits = 1;

					while (number2 > 9) {
						number2 /= 10;
						digits++;
					}


					if( digits ==1){
						sprintf(temp316,"0000000%i",intchunk3);

					}

					else if( digits ==2){
						sprintf(temp316,"000000%i",intchunk3);

					}
					else if( digits==3){
						sprintf(temp316,"00000%i",intchunk3);

					}
					else if( digits== 4){
						sprintf(temp316,"0000%i",intchunk3);

					}
					else if( digits==5){
						sprintf(temp316,"000%i",intchunk3);

					}
					else if( digits==6){
						sprintf(temp316,"00%i",intchunk3);

					}
					else if( digits==7){
						sprintf(temp316,"0%i",intchunk3);

					}
					else{
						sprintf(temp316,"%i",intchunk3);
					}
					number=intchunk4;
					digits =1;
					while (number > 9) {
						number /= 10;
						digits++;
					}


					if( digits ==1){
						sprintf(temp416,"0000000%i",intchunk4);

					}
					else if( digits ==2){
						sprintf(temp416,"000000%i",intchunk4);

					}
					else if( digits==3){
						sprintf(temp416,"00000%i",intchunk4);

					}
					else if( digits== 4){
						sprintf(temp416,"0000%i",intchunk4);

					}
					else if( digits==5){
						sprintf(temp416,"000%i",intchunk4);

					}
					else if( digits==6){
						sprintf(temp416,"00%i",intchunk4);

					}
					else if( digits==7){
						sprintf(temp416,"0%i",intchunk4);

					}
					else{
						sprintf(temp416,"%i",intchunk4);
					}


					number2 =intchunk2;
					digits = 1;

					while (number2 > 9) {
						number2 /= 10;
						digits++;
					}


					if( digits ==1){
						sprintf(temp216,"0000000%i",intchunk2);

					}

					else if( digits ==2){
						sprintf(temp216,"000000%i",intchunk2);

					}
					else if( digits==3){
						sprintf(temp216,"00000%i",intchunk2);

					}
					else if( digits== 4){
						sprintf(temp216,"0000%i",intchunk2);

					}
					else if( digits==5){
						sprintf(temp216,"000%i",intchunk2);

					}
					else if( digits==6){
						sprintf(temp216,"00%i",intchunk2);

					}
					else if( digits==7){
						sprintf(temp216,"0%i",intchunk2);

					}
					else{
						sprintf(temp216,"%i",intchunk2);
					}
					sprintf(chunk216, "%s%s%s%s", temp116,temp216,temp316,temp416);
					j++;
					j++;
					j++;
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
				char *temp = binadd(chunk116, chunk216, 33);
				strcpy(chunk216, temp);


			}

			//bool x;
			//x= true + true;
			//printf("%i",x);

			pointer2 = chunk216;
		//	printf("final binary is  %s \n",chunk216);
			do {
				b = *pointer2 == '1' ? 1 : 0;
				counter2 = (counter2 << 1) | b;
				pointer2++;
			} while (*pointer2);

			printf("%2s bit checksum is %8lx for all %4d chars\n", argv[2], counter2, characterCnt);


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
