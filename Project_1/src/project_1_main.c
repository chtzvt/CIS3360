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
    while (fgets(plaintext, MAXSIZE, fp) != NULL) {
    printf("%s", plaintext);
        // break; //fixes weird data corruption issue
}
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
        while (fgets(keytext, MAXSIZE, key) != NULL)
            printf("%s", keytext);
    // prints out what was inputed by user into io stream
        fclose(key);

 // /*
// starting to sanitize data not woriking yet
    removespecial(plaintext);
    removespecial(keytext);

    removeszeros(plaintext);
    removeszeros(keytext);

    stringtolower(plaintext);

    stringtolower(keytext);

    puts("the sanitized plaintext is");
    printf("%s \n", plaintext);
    puts("the sanitized keytext is");
    printf("%s \n", keytext);
// */
    return 0;
}
