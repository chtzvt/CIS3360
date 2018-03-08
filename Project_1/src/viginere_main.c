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
    temp = givemecleanstring(argv[2]);
	if (* temp == '1')
		return 4 ;
    char plaintext[MAXSIZE];
    strcpy(plaintext,temp);
    // copyies the returned value to a local varrible
    free(temp);

    char keytext[MAXSIZE];
    temp = givemecleanstring(argv[1]);
	if (* temp == '1')
		return 4 ;
    strcpy(keytext,temp);
    // copyies the returned value to a local varrible
    free(temp);

 // /*
// starting to sanitize data now working
/*

//    char  cleanedtext[MAXSIZE];
  //  char  keytext[MAXSIZE];
    // allocates string for no special charecter version of string
   // char * returned;
    //allocates string for the returned value
    // returned = cleaner(plaintext) ;
   // strcpy(cleanedtext,returned);
    // copyies the returned value to a local varrible
   // free(returned);
// frees the returned value so we can use it again
<<<<<<< HEAD
   // returned = cleaner(keytext);
   // strcpy(keytext,returned);
   // free(returned);
//	stringtolower(keytext);
//	stringtolower(plaintext);

    int cleantextsize = strlen(plaintext);
    int cleankeysize = strlen(keytext);
    int appendsize = cleankeysize -cleantextsize;
   // if(appendsize <0){
    //    puts("your key is smaller then your text );");
    //    return 2;
  //  }
=======
    returned = cleaner(keytext);
    strcpy(cleanedkey,returned);
   free(returned); */
	removespecial(keytext);
	removespecial(plaintext);
    int cleantextsize = strlen(plaintext);
    int cleankeysize = strlen(keytext);
    int appendsize = cleankeysize -cleantextsize;
    if(appendsize <0){
        puts("your key is smaller then your text );");
        return 2;
    }
>>>>>>> broken
    appendchars(plaintext,appendsize,cleantextsize,'x');

    puts("the sanitized keytext is");

    lprintf(keytext);

    puts("the sanitized plaintext is");

    lprintf(plaintext);
    
    puts("the ciphertext is");
    char ciphertext[MAXSIZE];
  
    encipher(&plaintext, ciphertext, &keytext, strlen(&plaintext));
    
    lprintf(ciphertext);
// */
    return 0;
}
