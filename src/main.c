#include "../include/cargas.h"
#include "../include/algoritmos.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

//falta:
//implementar pra gerar txt 
//corrigir makefile - OK
//função que confere se ta ordenando mesmo - OK

int esta_ordenado(int *v, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            return 0;  // O vetor não está ordenado
        }
    }
    return 1;  // O vetor está ordenado
}

//double tempo(int* v, int n){
    //clock_t inicio = clock(); //salvando o segundo de inicio da ordenação
    //insertion_sort(v, n);
    //bubble_sort(v,n);
    //selection_sort(v, n);
    //counting_sort(v, n);
    //merge_aux(v, n); 
    //clock_t fim = clock();
    //if (!esta_ordenado(v, n)) {
    //    fprintf(stderr, "Erro: o vetor não está ordenado!\n");
    //}
    //return ((double)(fim-inicio))/CLOCKS_PER_SEC; //converte clock para segundo 
//}

double tempo (int* v, int n){
    struct timeval inicio, fim; 
    gettimeofday(&inicio, NULL);
    //insertion_sort(v, n);
    //bubble_sort(v,n);
    //selection_sort(v, n);
    //counting_sort(v, n);
    //merge_aux(v, n); 
    //quick_aux(v, n);
    //shell_sort(v,n);
    radix_aux(v,n); 
    gettimeofday(&fim, NULL);
    double tempo_inicio = inicio.tv_sec + (inicio.tv_usec/1000000.0);
    double tempo_fim = fim.tv_sec + (fim.tv_usec/1000000.0);
    if (!esta_ordenado(v, n)) {
        fprintf(stderr, "Erro: o vetor não está ordenado!\n");
    }
    return (tempo_fim - tempo_inicio);
}

int main(int argc, char* argv[]){
    int tamanho_max = atoi(argv[1]); //passando um valor de fora da main - coloca na hora de executar .\main.exe tamanho intervalo 
    int intervalo = atoi(argv[2]);
    for(int tamanho = 500; tamanho<=tamanho_max; tamanho+=50){
        int* v = vet_al(tamanho, intervalo);
        double tempo_total = tempo(v, tamanho); 
        printf("(%d,%lf)", tamanho, tempo_total); 
        free(v); 
    }
    return 0; 
}