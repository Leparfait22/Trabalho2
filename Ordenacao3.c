#include <stdio.h>

#define MAX_IN_MEMORY 5

void swap(int *A,int i,int j){
    int aux = A[i];
    A[i] = A[j];
    A[j]  = aux;
}
int particona(int *A, int inicio, int fim){
    int pivo = A[fim];
    int i = inicio - 1;
    
    for (int j = inicio; j <= fim; j++){
        if (A[j] < pivo){
            i++;
            swap(A, i, j);
        }
    }
    
    swap(A, fim, i + 1);
    return (i + 1);
}

// Primeiro Quick
void primeiroQuick(int *A, int inicio, int fim){
    if (inicio >= fim)
        return;
    
    int pos = particona(A, inicio, fim);
    primeiroQuick(A, inicio, pos - 1);
    primeiroQuick(A, pos + 1, fim);
}

//Funcao QuickSort
void quickSort(int *A, int size){
  primeiroQuick(A, 0, size);
}

//Intercala merge
void intercala(int *A, int inicio, int meio, int fim){

     // merge interpolation
      int i = inicio;
      int j = meio + 1;
      int k = 0;
    
      int aux[fim - inicio + 1];
    
      while (i <= meio && j <= fim)
      {
        if (A[i] < A[j])
        {
          aux[k] = A[i];
          i++;
        }
        else
        {
          aux[k] = A[j];
          j++;
        }
        k++;
      }
    
      while (i <= meio)
      {
        aux[k] = A[i];
        i++;
        k++;
      }
    
      while (j <= fim)
      {
        aux[k] = A[j];
        j++;
        k++;
      }
    
      for (i = inicio; i <= fim; i++)
      {
        A[i] = aux[i - inicio];
      }
    }
    
//Primeiro merge
void primeiroMerge(int *A, int inicio, int fim){
    if (inicio >= fim)
        return;
        int meio = (inicio + fim) / 2;
    
        primeiroMerge(A, inicio, meio);
        primeiroMerge(A, meio + 1, fim);
        
        intercala(A, inicio, meio, fim);

    
    
}

//mergeSort
void mergeSort(int *A, int size){
    primeiroMerge(A,0,size);
}


int main() {
    int bloco[MAX_IN_MEMORY];
    char nomes[MAX_IN_MEMORY * 2][20];
    FILE *arquivosEntrada[MAX_IN_MEMORY];
    FILE *arquivosSaida[MAX_IN_MEMORY];
    
    
    int chaves1[] = {3, 98, 61, 62,  1, 99, 57, 98, 58, 18, 59, 35, 82, 91, 52, 95, 46,
        69, 48, 82, 52,  4, 87, 38, 44, 42, 72,  2, 95, 84, 34, 40, 23, 11, 75,
        37, 62, 96, 12, 22, 56, 20, 64,  2, 30, 48,  6, 19, 34, 31};
    int chaves2[] = {57, 91, 21, 89, 72, 74, 46, 61, 26, 50, 85, 76, 53, 22, 15, 40, 90, 2, 94, 54};
    int chaves3[] = {9,  2, 15, 19, 10, 14,  4, 13,  2, 19};
    int chaves4[] = {178, 231, 244, 292, 321, 356, 389, 421, 482, 488, 490, 502, 546, 641, 694, 786, 841, 890, 899, 922};
    
    while (1){
        for (int i = 0; i < (MAX_IN_MEMORY*2); i++) {
            if(i< MAX_IN_MEMORY){
                sprintf(nomes[i], "arquivo%d.txt", i + 1);
                printf("%s\n", nomes[i]);

                arquivosEntrada[i] = fopen(nomes[i], "w");
                if (arquivosEntrada[i] == NULL) {
                    printf("Não foi possível criar o arquivo %s.\n", nomes[i]);
                    return 1;
            }
            }
            // arquivo intermediário já criado
            int inicio = MAX_IN_MEMORY * i;
            int limite = inicio + MAX_IN_MEMORY - 1;

            // preenchendo o bloco com elementos
            for (int j = inicio; j <= limite; j++) {
                bloco[j - inicio] = chaves1[j];
            }

            // ordenando o bloco
            quickSort(bloco, MAX_IN_MEMORY - 1);

            // verificando se o bloco foi criado com sucesso e ordenado
            for (int k = 0; k < MAX_IN_MEMORY; k++) {
                printf("%d\n", bloco[k]);
            }

            // escrevendo o bloco ordenado no arquivo
            for (int k = 0; k < MAX_IN_MEMORY; k++) {
                if(i<MAX_IN_MEMORY){
                    fprintf(arquivosEntrada[i], "%d\n", bloco[k]);
                }else{
                    printf("i = %d\n",i);
                    fprintf(arquivosEntrada[i-MAX_IN_MEMORY], "%d\n", bloco[k]);
                }
            }

        //fclose(arquivosEntrada[i]);
        } 
   }
    
    for(int i = 0;i< (MAX_IN_MEMORY*2);i++){
        if(i< MAX_IN_MEMORY){
            sprintf(nomes[i], "saida%d.txt", i + 1);
            printf("%s\n", nomes[i]);

            arquivosSaida[i] = fopen(nomes[i], "w");
            if (arquivosEntrada[i] == NULL) {
                printf("Não foi possível criar o arquivo %s.\n", nomes[i]);
                return 1;
           }
        }
    }



    int tamanhoVetor = (int)sizeof(chaves1)/sizeof(int);
    mergeSort(chaves1,tamanhoVetor-1);
        printf("\nMerge sort: ");
        for (int i = 0 ; i < tamanhoVetor ; i++)
            printf("%d ", chaves1[i]);
        printf("\n");


    return 0;
}