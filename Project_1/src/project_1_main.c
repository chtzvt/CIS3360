/*
	CIS3360 - Project 1
	Michael McAlpin
	By Charlton Trezevant and Alexander Cote
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000
int main() {
    FILE *fp;
    char plaintext[MAXSIZE];
    char* plainfile = "../plainText1.txt";

    fp = fopen(plainfile, "r");
    if (fp == NULL){
        printf("Could not open file %s",plainfile);
        return 1;
    }
    puts("the plaintext input is");
    while (fgets(plaintext, MAXSIZE, fp) != NULL)
        printf("%s", plaintext);
    fclose(fp);


        FILE *key;
        char keytext[MAXSIZE];
        char* keyfile = "../viginere key1.txt";

        key = fopen(keyfile, "r");
        if (key == NULL){
            printf("Could not open file %s",keyfile);
            return 1;
        }
        puts("the key input is");
        while (fgets(keytext, MAXSIZE, key) != NULL)
            printf("%s", keytext);
        fclose(key);
    
    return 0;
}