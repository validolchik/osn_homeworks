//
// Created by valik on 28.08.2019.
//

#include <stdio.h>
#include <string.h>

void ladder(int n){
    for(int i = 0; i < n; i++){
        for(int y = 0; y < i+1; y++){
            printf("*");
        }
        printf("\n");
    }
}

void valley(int n){
    ladder(n);
    for(int i = 0; i < n-1; i++){
        for(int y = n-i-1; y > 0; y--){
            printf("*");
        }
        printf("\n");
    }
}

void bar(int n){
    for(int i = 0; i < n; i++){
        for(int y = 0; y < n; y++){
            printf("*");
        }
        printf("\n");
    }
}

void wave(int n){
    for(int i = 0; i < n; i++){
        valley(n);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int num_of_stars = 1;
    for(int i = 0; i < n; i++){
        for(int y = 0; y < (2*n-1 - num_of_stars)/2; y++){
            printf(" ");
        }
        for(int y = 0; y < num_of_stars; y++){
            printf("*");
        }
        for(int y = 0; y < (2*n-1 - num_of_stars)/2; y++){
            printf(" ");
        }
        printf("\n");
        num_of_stars += 2;
    }
    printf("\n");

    ladder(n);
    printf("\n");

    valley(n);
    printf("\n");

    bar(n);
    printf("\n");

    // wave(n);
    printf("\n");

    return 0;
}