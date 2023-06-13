#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IN_MEMORY 5

//funcao swap
void swap(int *A,int i,int j){
    int aux = A[i];
    A[i] = A[j];
    A[j]  = aux;
}

//particionar Quick
int particona(int *A, int inicio, int fim){
        printf("QUick comecou3\n");

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
        printf("QUick comecou2\n");

    if (inicio >= fim)
        return;
    
    int pos = particona(A, inicio, fim);
    primeiroQuick(A, inicio, pos - 1);
    primeiroQuick(A, pos + 1, fim);
}

//Funcao QuickSort
void quickSort(int *A, int size){
    printf("QUick comecou\n");
  primeiroQuick(A, 0, size);
}

//tamanho de vetor 
/* int calcTamanho(int vetor[]){
    int tamanho =  (int)sizeof(vetor)/sizeof(int);
    return tamanho;
  }  */
//criacao de 10 arquivos 



int main()
{

    FILE *arquivos[MAX_IN_MEMORY *2];
    char nomes[MAX_IN_MEMORY * 2][20];
    int leitor;
    int bloco[MAX_IN_MEMORY];
    int ordenado = 1;  // Variável para indicar se o bloco está ordenado
    
    int chaves1[] = {3, 98, 61, 62,  1, 99, 57, 98, 58, 18, 59, 35, 82, 91, 52, 95, 46,
        69, 48, 82, 52,  4, 87, 38, 44, 42, 72,  2, 95, 84, 34, 40, 23, 11, 75,
        37, 62, 96, 12, 22, 56, 20, 64,  2, 30, 48,  6, 19, 34, 31};
    int chaves2[] = {57, 91, 21, 89, 72, 74, 46, 61, 26, 50, 85, 76, 53, 22, 15, 40, 90, 2, 94, 54};
    int chaves3[] = {9,  2, 15, 19, 10, 14,  4, 13,  2, 19};
    int chaves4[] = {178, 231, 244, 292, 321, 356, 389, 421, 482, 488, 490, 502, 546, 641, 694, 786, 841, 890, 899, 922};

    for(int i = 0;i<(MAX_IN_MEMORY *2);i++){
        sprintf(nomes[i],"arquivos%d.txt",i+1);
        printf("%s\n",nomes[i]);
        arquivos[i] = fopen(nomes[i],"w");
        if(arquivos[i] == NULL) {
            printf("Não foi possível criar o arquivo %s.\n", nomes[i]);
            return 1;
        }
        //arquivo intermediario ja criado

        
        /* int inicio = MAX_IN_MEMORY * i;
        int limite = ((1+i)*5)-1;

        //prenchendo os blocos com 5 elementos no maximo 
        for(int j = inicio;j <= limite;j++){
            //leitor = chaves1[j];
            bloco[j] = chaves1[j];
        } */
        //ordenando o bloco de 5 elementos 
//        int tamanho = (int)sizeof(bloco)/sizeof(int);
        //int tamanho = calcTamanho(bloco);
        //printf("TAmanho = %d\n",tamanho);


        int inicio = MAX_IN_MEMORY * i;
        int limite = inicio + MAX_IN_MEMORY - 1;

        for (int j = inicio; j <= limite; j++) {
            bloco[j - inicio] = chaves1[j];
        }

        quickSort(bloco, MAX_IN_MEMORY -1);
        for (int k = inicio; k <= limite - 1; k++) {
            if (bloco[k] > bloco[k + 1]) {
                ordenado = 0;
                break;
            }
        }

        if (ordenado) {
            printf("O bloco foi corretamente ordenado.\n");
        } else {
            printf("O bloco não foi corretamente ordenado.\n");
        }

        //verificar se o bloco foi criado com sucesso
        for(int k = inicio;k<= limite;k++){
            printf("%d\n",bloco[k]);
         }
    }















    /* for(int i = 0; i< tamanho;i++){
        printf("%d\n",chaves1[i]);
    } */
    /* int tamanho = (int)sizeof(chaves2)/sizeof(int);
    quickSort(chaves2,tamanho-1);
    printf("\nQuick sort: ");
    for (int i = 0 ; i < tamanho ; i++)
        printf("%d ", chaves2[i]);
    printf("\n");
  */

    return 0;
}
