#ifndef CARGAS_H
#define CARGAS_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* vet_al(int n, int r){
    int* v = malloc(n*sizeof(int)); 
    srand(time(NULL)); //faz o rand virar realmente aleatorio
    for (int i = 0; i<n; i++){
        v[i]=rand()%r; 
    }
    return v;
};

void print_vet(int* v, int n){
    for (int i = 0; i<n; i++){
        printf("%d\t", v[i]);
    }
    printf("\n");
}

#endif 