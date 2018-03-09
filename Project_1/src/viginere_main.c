/*
	CIS3360 - Project 1
	Michael McAlpin
	By Charlton Trezevant and Alexander Cote
*/

#include <stdio.h>
#include <string.h>
#include "stringhandle.h"
#include "def.h"
#include "filehandle.h"
#include "cipher.h"

//defines max character array size
int main(int argc, char** argv) {
    // inputs files into strings
    char * temp;
    temp = givemestring(argv[2]);
	if (* temp == '1')
		return 4 ;
    char plaintext[MAXSIZE];
    strcpy(plaintext,temp);
    // copyies the returned value to a local varrible
    free(temp);

    char keytext[MAXSIZE];
    temp = givemestring(argv[1]);
	if (* temp == '1')
		return 4 ;
    strcpy(keytext,temp);
    // copyies the returned value to a local varrible
    free(temp);

 // /*
// starting to sanitize data now working
/*

    returned = cleaner(keytext);
    strcpy(cleanedkey,returned);
   free(returned); */
//	removespecial(keytext);
//	removespecial(plaintext);
    int cleantextsize = strlen(plaintext);
    int cleankeysize = strlen(keytext);
    int appendsize = cleankeysize -cleantextsize;
   // if(appendsize <0){
   //     puts("your key is smaller then your text );");
   //     return 2;
   // }

    appendchars(plaintext,appendsize,cleantextsize,'x');
=======

    char  cleanedtext[MAXSIZE];
    char  cleanedkey[MAXSIZE];
    removespecial(plaintext, cleanedtext, MAXSIZE);
    removespecial(keytext, cleanedkey, MAXSIZE);

    int cleantextsize = strlen(cleanedtext);
    int cleankeysize = strlen(cleanedkey);
    int appendsize = cleankeysize -cleantextsize;
    
    if(appendsize <0){
        puts("your key is smaller then your text );");
        return 2;
    }
    appendchars(cleanedtext,appendsize,cleantextsize,'x');

    puts("the sanitized keytext is");

    lprintf(keytext);

    puts("the sanitized plaintext is");

    lprintf(plaintext);
    
    puts("the ciphertext is");
    char ciphertext[MAXSIZE];
  
    encipher(&plaintext, strlen(&plaintext), &keytext, strlen(&keytext), ciphertext);
    
    lprintf(ciphertext);
// */
    return 0;
}
