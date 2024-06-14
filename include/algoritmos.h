#ifndef ALGORITMOS_H
#define ALGORITMOS_H

//tentar implementar bubble, selection, counting - OK
//quick sort, shell sort, radix sort - OK
//bucket sort

void bubble_sort(int* v, int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
               temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
      }
   }
}

void selection_sort(int* v, int n) {
    int min_idx, temp;
    for (int i = 0; i < n - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            temp = v[i];
            v[i] = v[min_idx];
            v[min_idx] = temp;
        }
    }
}

void counting_sort(int* v, int n) {
    int i, max = v[0], min = v[0];
    for (i = 1; i < n; i++) {
        if (v[i] > max) max = v[i];
        if (v[i] < min) min = v[i];
    }

    int range = max - min + 1;
    int* count = calloc(range, sizeof(int));
    int* output = malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        count[v[i] - min]++;
    }

    for (i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        output[count[v[i] - min] - 1] = v[i];
        count[v[i] - min]--;
    }

    for (i = 0; i < n; i++) {
        v[i] = output[i];
    }

    free(count);
    free(output);
}


void insertion_sort(int* v, int n){
    for(int i=1; i<n; i++){
        int j = i-1;
        int aux = v[i];
        while (aux< v[j] && j>=0){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=aux;
    }
}

void merge(int* v, int esquerda, int meio, int direita){
    int* copia = malloc((direita+1)*sizeof(int));
    int i =  esquerda;
    int j = meio+1;
    int k = 0; 
    while(i<=meio && j<=direita){
        if(v[i]<v[j]){
            copia[k++] = v[i++]; //passa o v[i] p copia[k] e depois incrementa as duas variaveis
        }
        else{
            copia[k++] = v[j++];
        }
    }
    while(i<=meio){
        copia[k++] = v[i++]; 
    }
    while(j<=direita){
        copia[k++] = v[j++];
    }
    k = 0; 
    for(int n = esquerda; n<=direita; n++){
        v[n]=copia[k];
        k++;
    }
    free(copia); 
}

void merge_sort(int* v, int esquerda, int direita){
    int meio = (direita+esquerda)/2;
    if(direita>esquerda){
        merge_sort(v, esquerda, meio); 
        merge_sort(v, meio+1, direita); 
        merge(v, esquerda, meio, direita); 
    }
}

void merge_aux(int* v, int tamanho){
    merge_sort(v, 0, tamanho-1); //função feita para passar vetor e tamanho e padronizar
}

int mediana(int x, int y, int z){
    if((x<=y)&&(y<=z)) return y;
    if((x<=z)&&(z<=y)) return z;
    if((y<=x)&&(x<=z)) return x;
    if((y<=z)&&(z<=x)) return z;
    if((z<=y)&&(y<=x)) return y;
    return x;
}
void partition(int* v, int esquerda, int direita, int* e, int* d){
    e = esquerda;
    d = direita;
    int pivo = mediana(v[esquerda], v[direita], v[(direita+esquerda)/2]); 
    do{
        while(*e<=direita && v[*e]<pivo){
            (*e)++; 
        }
        while(esquerda<=*d && v[*d]>pivo){
            (*d)--;
        }
        if(*e<=*d){
            int aux = v[*e]; 
            v[*e] = v[*d];
            v[*d] = aux; 
            (*e)++; 
            (*d)--;
        }
    } while(*e <= *d);
}

void quick_sort(int* v, int esquerda, int direita){
    if(esquerda<direita){
        int e, d; //apontadores para as posições
        partition(v, esquerda, direita, &e, &d);
        if(esquerda<d){
            quick_sort(v, esquerda, d);
        }
        if (e<direita){
            quick_sort(v, e, direita);
        }
    }
}

void quick_aux(int*v, int tamanho){
    quick_sort(v, 0, tamanho-1); //função feita para passar vetor e tamanho e padronizar
}

void shell_sort(int* v, int tamanho){
    for(int k = tamanho/2; k>0; tamanho=tamanho/2){
        for(int i=k; i<tamanho; i++){
            int j = i;
            int aux = v[i];
            while (aux<v[j-k] && j>=k){
                v[j]=v[j-k];
                j = j-k;
            }
            v[j] = aux;
        }
    }
}

int bit(int n, int base){ 
    return ((n>>base)&1);
}

void radix_sort(int* v, int esquerda, int direita, int base){
    if(direita<=esquerda || base<0){
        return;
    }
    int e = esquerda; 
    int d = direita; 
    while(d >= e){
        while(e<=d && bit(v[e], base)==0){
            e++;
        }
        while(d>=e && bit(v[d], base)==1){
            d--;
        }
        if(d>=e){
            int aux = v[e];
            v[e]=v[d];
            v[d] = aux;
            e++;
            d--; 
        }
    }
    radix_sort(v, esquerda, d, base-1);
    radix_sort(v, e, direita, base-1);
}

void radix_aux(int*v, int tamanho){
    radix_sort(v, 0, tamanho-1, 31); 
}
#endif 