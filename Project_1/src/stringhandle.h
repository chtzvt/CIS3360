//
// Created by aleccoder on 2/21/18.
//

#ifndef CIS3360_STRINGHANDLE_H
#define CIS3360_STRINGHANDLE_H
#include <ctype.h>
#endif //CIS3360_STRINGHANDLE_H
#define MAXSIZE 1000
void removespecial(char special[]) {
    int i = 0;
    while (i != MAXSIZE) {
        if (isalpha(special[i]) == 0) {
            special[i] = 0;
        }


        i++;
    }
}
void stringtolower(char upper[]){
    int i=0 ;
    while(i != MAXSIZE){
        upper[i]=tolower(upper[i]);

        i++;
    }

}

void removeszeros(char zeroed[]) {
    char fixed[MAXSIZE];
    int i = 0;
    int j= 0;
    while (i != MAXSIZE) {
        if ( zeroed[j] != 0) {

            fixed[j]=zeroed[j] ;
            j++;
        }


        i++;
    }
}
