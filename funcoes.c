#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IN_MEMORY 5

#define TAMANHO_VETOR 5



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

typedef struct {
    int valor;
    int posicao;
} MenorElemento;

MenorElemento Menores(int vetor[], int tamanho) {
    MenorElemento menor;
    menor.valor = vetor[0];
    menor.posicao = 0;

    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] < menor.valor) {
            menor.valor = vetor[i];
            menor.posicao = i;
        }
    }

    return menor;
}

void particionarVetor(int vetor[], int tamamnho){
    int bloco[MAX_IN_MEMORY];
    char nomesEntrada[MAX_IN_MEMORY][15];
    char nomeSaida[MAX_IN_MEMORY][15];
    FILE *arquivosEntrada[MAX_IN_MEMORY];
    FILE *arquivosSaida[MAX_IN_MEMORY];
    FILE *arquivo;
    int vetTemp[5];
    int leitor;
    int i= 0;
    int j = 0;
    int t = 1;
    int cont = 0;
    int k = 1;
    int tamVetorPrincipal = tamamnho / sizeof(vetor[0]);

    while (1){ 

        if(i == (tamVetorPrincipal/MAX_IN_MEMORY)){
            break;
        }
        if(i< MAX_IN_MEMORY){
            sprintf(nomesEntrada[i], "entrada%d.txt", i + 1);
            arquivosEntrada[i] = fopen(nomesEntrada[i], "w");
            if (arquivosEntrada[i] == NULL) {
                return 1;
            }
            
        }
        // arquivo intermediário já criado
        int inicio = MAX_IN_MEMORY * i;
        int limite = inicio + MAX_IN_MEMORY - 1;

        // preenchendo o bloco com elementos
        for (int p = inicio; p <= limite; p++) {
            bloco[p - inicio] = vetor[p];
        }

        // ordenando o bloco
        quickSort(bloco, MAX_IN_MEMORY - 1);

        // verificando se o bloco foi criado com sucesso e ordenado
        //for (int v = 0; v < MAX_IN_MEMORY; v++) {
          //  printf("%d\n", bloco[v]);
        //}

        // escrevendo o bloco ordenado no arquivo
        for (k = 0; k < MAX_IN_MEMORY; k++) {
            if(i < MAX_IN_MEMORY){
                fprintf(arquivosEntrada[i], "%d\n", bloco[k]);
            }else{
                fprintf(arquivosEntrada[i-MAX_IN_MEMORY*(i/MAX_IN_MEMORY)], "%d\n", bloco[k]);
            }
        }
        // se ainda sobra elemento no vetro principal ele é escrito na entrada final do arquivo
        if(i == (tamVetorPrincipal/MAX_IN_MEMORY)-1){
            int elementoRestante = tamVetorPrincipal -((i+1) * MAX_IN_MEMORY);
            if(elementoRestante > 0){
                int vetorRestante[elementoRestante];
                for (int p = 0; p < elementoRestante; p++) {
                    vetorRestante[p] = vetor[(i+1)*MAX_IN_MEMORY+p];
                }
                for(int r = 0;r < elementoRestante;r++){
                    fprintf(arquivosEntrada[(i/MAX_IN_MEMORY)-1],"%d\n", vetorRestante[r]);
                }
            }
        } 
        i++;  
    }
    for (i = 0; i < TAMANHO_VETOR; i++) {
        fclose(arquivosEntrada[i]);
    }

}

void ordenarMatriz(int matriz[][MAX_IN_MEMORY], int linhas, int colunas) {
    for (int k = 0; k < linhas * colunas - 1; k++) {
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                int linhaAtual = i;
                int colunaAtual = j;

                // Encontra o menor elemento a partir da posição atual
                for (int m = i; m < linhas; m++) {
                    for (int n = (m == i ? j + 1 : 0); n < colunas; n++) {
                        if (matriz[m][n] < matriz[linhaAtual][colunaAtual]) {
                            linhaAtual = m;
                            colunaAtual = n;
                        }
                    }
                }

                // Troca o elemento atual com o menor elemento encontrado
                if (linhaAtual != i || colunaAtual != j) {
                    int temp = matriz[i][j];
                    matriz[i][j] = matriz[linhaAtual][colunaAtual];
                    matriz[linhaAtual][colunaAtual] = temp;
                }
            }
        }
    }
}

void imprimirMatriz(int matriz[][MAX_IN_MEMORY], int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}


/* char* nomeArquivo(int numero) {
    char* nome_arquivo = (char*)malloc(sizeof(char) * 15); // Tamanho máximo necessário é 13: "entradaX.txt\0"
    sprintf(nome_arquivo, "entrada%d.txt", numero);
    return nome_arquivo;
} */

void salvarMatrizEmArquivo(const char* nomeArquivo, int matriz[][5], int linhas, int colunas) {
    FILE* arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            fprintf(arquivo, "%d\n", matriz[i][j]);
        }
    }

    fclose(arquivo);
}

int main() {
    int bloco[MAX_IN_MEMORY];
    char nomesEntrada[MAX_IN_MEMORY][15];
    char nomeSaida[MAX_IN_MEMORY][15];
    FILE *arquivosEntrada[MAX_IN_MEMORY];
    FILE *arquivosSaida[MAX_IN_MEMORY];
    FILE *arquivo;
    FILE *arquivos[MAX_IN_MEMORY];
    int vetTemp[5];
    int leitor;
    int i= 0;
    int j = 0;
    int t = 1;
    int cont = 0;
    int k = 1; 
    int matriz[MAX_IN_MEMORY][MAX_IN_MEMORY];
    int passagem = 1;
    int menorNumero,s;
    


    
    
     int chaves1[] = {3, 98, 61, 62,  1, 99, 57, 98, 58, 18, 59, 35, 82, 91, 52, 95, 46,
        69, 48, 82, 52,  4, 87, 38, 44, 42, 72,  2, 95, 84, 34, 40, 23, 11, 75,
        37, 62, 96, 12, 22, 56, 20, 64,  2, 30, 48,  6, 19, 34, 31};
    /* int chaves1[] = {3, 98, 61, 62,  1, 99, 57, 98, 58, 18, 59, 35, 82, 91, 52, 95, 46,
        69, 48, 82, 52,  4, 87, 38, 44, 42, 72,  2, 95, 84, 34, 40, 23, 11, 75,
        37, 62, 96, 12, 22, 56, 20, 64,  2, 30, 48,  6, 19, 34, 31, 51, 4, 9}; */
    int chaves2[] = {57, 91, 21, 89, 72, 74, 46, 61, 26, 50, 85, 76, 53, 22, 15, 40, 90, 2, 94, 54};
    int chaves3[] = {9,  2, 15, 19, 10, 14,  4, 13,  2, 19};
    int chaves4[] = {178, 231, 244, 292, 321, 356, 389, 421, 482, 488, 490, 502, 546, 641, 694, 786, 841, 890, 899, 922};
    int tamanho = sizeof(chaves1);
    int tamVetorPrincipal = tamanho / sizeof(chaves1[0]);

    //criando os arquivos de entrada intermediarios para guardar os blocos de dados
    particionarVetor(chaves1,tamanho);

     //criar  arquivos intermediarios para receber as intercalacoes 
    for(int i = 0;i<MAX_IN_MEMORY;i++){
            sprintf(nomeSaida[i], "saida%d.txt", i + MAX_IN_MEMORY+1);
            printf("%s\n",nomeSaida[i]);
        arquivosSaida[i] = fopen(nomeSaida[i], "w");
        if (arquivosSaida[i] == NULL) {
            printf("Erro ao criar o arquivo de saida %s\n",nomeSaida[i]);
            return 1;
        }
    }

    /* arquivos[0] = fopen("entrada1.txt", "r");
    arquivos[1] = fopen("entrada2.txt", "r");
    arquivos[2] = fopen("entrada3.txt", "r");
    arquivos[3] = fopen("entrada4.txt", "r");
    arquivos[4] = fopen("entrada5.txt", "r"); */
    
    
    //intercalando os blocos para colocar nos arquivos de saidas  
    for(int p = 0;p <= (tamVetorPrincipal/(MAX_IN_MEMORY*MAX_IN_MEMORY));p++){
        printf("p = %d\n",p);
        for(int i = 0;i<MAX_IN_MEMORY;i++){
            sprintf(nomesEntrada[i], "entrada%d.txt", i + 1);
            //printf("%s\n",nomesEntrada[i]);
            arquivos[i] = fopen(nomesEntrada[i], "r");
            if (arquivos[i] == NULL) {
                printf("Erro ao abrir o arquivo\n");
                return 1;
            }
        }

        int inicio = MAX_IN_MEMORY * p;
        int limite = inicio + MAX_IN_MEMORY - 1;
        int cont,leitor;
        // Lê os primeiros 5 números
       /*  for(int i = 0; i< MAX_IN_MEMORY;i++){
            printf("leitor1 = %d\n", leitor);  // Faça o processamento necessário com o número
            while (cont < 5 && fscanf(arquivos[i], "%d", leitor) == 1) {
                printf("leitor = %d\n", leitor);  // Faça o processamento necessário com o número
                cont++;
            }
        } */
        
        // preenchendo o bloco com elementos
       /*  for (int i = inicio; i <= limite; i++) {
            for (int j = 0; j < MAX_IN_MEMORY; j++) {
                fscanf(arquivos[i-inicio], "%d", &matriz[i][j]);
            }
            //bloco[p - inicio] = vetor[p];
        } */
        printf("Aqui\n");
        int passagem = 0;
        while(passagem < (p+1)){
            //printf("passagem = %d\n", passagem);
            for (int k = inicio; k <= limite; k++) {
                //printf("inicio: %d -- limite : %d\n", inicio , limite);
                //printf("elementos %d--\n3",arquivos[i]);
                for (int j = 0; j < MAX_IN_MEMORY; j++) {
                    fscanf(arquivos[k-(MAX_IN_MEMORY*p)], "%d", &matriz[k-(MAX_IN_MEMORY*p)][j]);
                }
            }
            imprimirMatriz(matriz,MAX_IN_MEMORY,MAX_IN_MEMORY);
            ordenarMatriz(matriz,MAX_IN_MEMORY,MAX_IN_MEMORY);
            salvarMatrizEmArquivo(nomeSaida[passagem], matriz, MAX_IN_MEMORY, MAX_IN_MEMORY);
            passagem++;
        }
        

   

   

    // Lê os primeiros 5 números
    /* while (contador < 5 && fscanf(arquivo, "%d", &numero) == 1) {
        printf("%d\n", numero);  // Faça o processamento necessário com o número
        contador++;
    }

    // Lê os próximos 5 números a cada iteração subsequente
    while (fscanf(arquivo, "%d", &numero) == 1) {
        printf("%d\n", numero);  // Faça o processamento necessário com o número
        contador++;

        if (contador == 10) {
            // Já leu 10 números, interrompe o loop
            break;
        }
    }

    // Fecha o arquivo
    fclose(arquivo); */

 

        
        //imprimirMatriz(matriz,MAX_IN_MEMORY,MAX_IN_MEMORY);
        //ordenarMatriz(matriz,MAX_IN_MEMORY,MAX_IN_MEMORY);

        //printf("Matriz ordenado: \n ");
        //imprimirMatriz(matriz,MAX_IN_MEMORY,MAX_IN_MEMORY);

        //colocando os dados intercalados nos arquivos de saida
        //salvarMatrizEmArquivo(nomeSaida[i], matriz, MAX_IN_MEMORY, MAX_IN_MEMORY);

    

    //const char* nomeArquivo = "matriz.txt";


    
    
    }
        
    return 0;
}



