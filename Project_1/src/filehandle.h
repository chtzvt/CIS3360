//
// Created by aleccoder on 2/22/18.
//

#ifndef CIS3360_FILEHANDLE_H
#define CIS3360_FILEHANDLE_H

#endif //CIS3360_FILEHANDLE_H

#include "def.h"
#include <stdio.h>
#include <string.h>

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
    char x;
    while  ( ( x = fgetc( fp ) ) != EOF )
    {
        //printf( "%c", x );
        text[i]=x;
        i++;
    }
    
    for(int i = 0; i < MAXSIZE; i++)
    
    text[i]=0;
    // adds null charecter
//printf("%s",text);
    return strdup(text);
}
