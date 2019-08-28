//
// Created by valik on 28.08.2019.
//
#include <stdio.h>
#include <string.h>

int main(){
    char string[256];

    scanf("%s", &string);

    for(int i = strlen(string); i > 0; i--){
        printf("%c", string[i-1]);
    }
    return 0;
}