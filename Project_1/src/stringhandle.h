//
// Created by aleccoder on 2/21/18.
//

#ifndef CIS3360_STRINGHANDLE_H
#define CIS3360_STRINGHANDLE_H
#include <ctype.h>
#endif //CIS3360_STRINGHANDLE_H
#define MAXSIZE 1000

// replaces all special charecter  with '0'
void removespecial(char special[]) {
    int i = 0;
    while (i != MAXSIZE) {
        if(  special[i]==0)
            break; // i know its bad practice but it pervents the null termninating string from being deleted
        if ((isalpha(special[i]) == 0)&&special[i]!=0) {
            special[i] = '0';
        }


        i++;
    }
}
// goes through and changes all upper case letters to the lower case version
void stringtolower(char upper[]){
    int i=0 ;
    while(i != MAXSIZE){
        upper[i]=tolower(upper[i]);

        i++;
    }

}
// goes through the input string and prints it to the output string however it ignores any zeros when copying
char * removeszeros(char zeroed[]) {
    char fixed[MAXSIZE];
    int i = 0;
    int j= 0;
    while (i != MAXSIZE) {
        if ( zeroed[i] != '0') {

            fixed[j]=zeroed[i] ;
            j++;
        }


        i++;
    }

// returns the fixed string but allocates the memory so it does not get freed when function ends note this does not work in windows
    return strdup(fixed);
}


char * cleaner( char dirty[MAXSIZE]){
    removespecial(dirty);

    char  cleaned[MAXSIZE];
    // allocates string for no special charecter version of string
    char * returned;
    //allocates string for the returned value
    returned = removeszeros(dirty)  ;
    strcpy(cleaned,returned);
    // copyies the returned value to a local varrible
    free(returned);

    return strdup(cleaned);

}