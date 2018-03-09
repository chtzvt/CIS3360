//
// Created by aleccoder on 2/22/18.
//

#ifndef CIS3360_FILEHANDLE_H
#define CIS3360_FILEHANDLE_H

#endif //CIS3360_FILEHANDLE_H

#include "def.h"
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

char * givemestring(char *filename, char *contents, int MAXSIZE){

    FILE *file;
    
    //char* plainfile = "../plainText1.txt"; //staticly defines file name for plain text
    // take command line arguments for name of plain text file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s", filename);
        contents = NULL;
    }
    // opens and catches for bad files
    // puts("the plaintext input is");
    //   while (fgets(plaintext, MAXSIZE, fp) != NULL) {
    //   printf("%s", plaintext);

    // break; //fixes weird data corruption issue
// }
    int i=0;
	int j=0;
    char x;
	int p=0;
	 x = fgetc( fp );
    while  (  x!= EOF)
    {
	j=isalpha(x);

	    if(j!=0){
		x=tolower(x);
		    //printf( "%c", x );
        text[i]=x;
        i++;
    }
	   // p++;
	    x = fgetc( fp );
	    if( i==999){
		    break;
	    }
    }
    text[i]=0;
    // adds null charecter
//printf("%s",text);
    return strdup(text);
}

char * givemecleanstring(char * file){

	FILE *fp;

	char text[MAXSIZE];
	//char* plainfile = "../plainText1.txt"; //staticly defines file name for plain text
	// take command line arguments for name of plain text file
	fp = fopen(file, "r");
	if (fp == NULL) {
		printf("Could not open file %s", file);
		return strdup("");
	}
	// opens and catches for bad files
	// puts("the plaintext input is");
	//   while (fgets(plaintext, MAXSIZE, fp) != NULL) {
	//   printf("%s", plaintext);//printf( "%c", x );

	// break; //fixes weird data corruption issue
// }
	int i=0;
	char x;
	while  ( ( x = fgetc( fp ) ) != EOF )
	{
		if((isalpha(x)==1)) {
			text[i] = x;
			i++;
		}
	}
	text[i]=0;
	// adds null charecter
//printf("%s",text);
	// fclose(file);
	return strdup(text);
}
