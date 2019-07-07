#include <stdio.h>
#include <stdlib.h>
#include "defines.h"

int justString(char str[]){
    if(str == NULL)
        return ERROR_PARAMETRO_INVALIDO;

    int i = 0;
    while(str[i] != '\0'){
        if((str[i] < 'a' || str[i] > 'z') && str[i] != ' ' && (str[i] < 'A' || str[i] > 'Z')){
            return ERROR_CARACTER_INVALIDO;
        }
        i++;
    }
    return OK;
}

int justNumeric(char numero[]){
    if(numero == NULL)
        return ERROR_PARAMETRO_INVALIDO;

    int i = 0;
    while(numero[i] != '\0'){
        if(numero[i] < '0' || numero[i]> '9'){
            return ERROR_DIGITO_INVALIDO;
        }
        i++;
    }
    return OK;
}
