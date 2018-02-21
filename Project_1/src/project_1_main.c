/*
	CIS3360 - Project 1
	Michael McAlpin
	By Charlton Trezevant and Alexander Cote
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stringhandle.h"


//defines max character array size
int main(int argc, char** argv) {
    // takes arguments from command line
    FILE *fp;

    char plaintext[MAXSIZE];
    //char* plainfile = "../plainText1.txt"; //staticly defines file name for plain text
    char *plainfile = argv[1];
    // take command line arguments for name of plain text file
    fp = fopen(plainfile, "r");
    if (fp == NULL) {
        printf("Could not open file %s", plainfile);
        return 1;
    }
    // opens and catches for bad files
    puts("the plaintext input is");
 //   while (fgets(plaintext, MAXSIZE, fp) != NULL) {
 //   printf("%s", plaintext);

        // break; //fixes weird data corruption issue
// }
    int i=0;
    char x;
    while  ( ( x = fgetc( fp ) ) != EOF )
    {
        //printf( "%c", x );
        plaintext[i]=x;
        i++;
    }
    printf("%s", plaintext);
    // prints out file to io stream
    fclose(fp);


        FILE *key;
        char keytext[MAXSIZE];
      //  char* keyfile = "../viginere key1.txt"; //staticly defines file name for key text
    char* keyfile = argv[2];
    // takes name of keyfile argument and stores as string
        key = fopen(keyfile, "r");
        if (key == NULL){
            printf("Could not open file %s",keyfile);
            return 1;
        }
    // opens and catches for bad files
        puts("the key input is");
       // while (fgets(keytext, MAXSIZE, key) != NULL)
         //   printf("%s", keytext);

     i=0;

    while  ( ( x = fgetc( key) ) != EOF )
    {
        printf( "%c", x );
        keytext[i]=x;
        i++;
    }
    // prints out what was inputed by user into io stream
        fclose(key);

 // /*
// starting to sanitize data now working
    removespecial(plaintext);
    removespecial(keytext);

    char  nospecialtext[MAXSIZE];
    char  nospecialkey[MAXSIZE];
    // allocates string for no special charecter version of string
    char * returned;
    //allocates string for the returned value
     returned = removeszeros(plaintext)  ;
    strcpy(nospecialtext,returned);
    // copyies the returned value to a local varrible
    free(returned);
// frees the returned value so we can use it again
    returned = removeszeros(keytext);
    strcpy(nospecialkey,returned);



    stringtolower(nospecialtext);

    stringtolower(nospecialkey);

    puts("the sanitized plaintext is");
    printf("%s \n", nospecialtext);
    puts("the sanitized keytext is");
    printf("%s \n", nospecialkey);
// */
    return 0;
}
