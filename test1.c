#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IN_MEMORY 5


char nomeArquivo(int num){
    return ("entrada%d",num);
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

int main()
{
    FILE *arquivo;
    char linha[100];
    char nome[40];
    char cod[7];
    int cr;
    int bloco[MAX_IN_MEMORY];
    char nomes[MAX_IN_MEMORY * 2][20];
    FILE *arquivosEntrada[MAX_IN_MEMORY];
    FILE *arquivosSaida[MAX_IN_MEMORY];
    FILE *arquivo;
    

    arquivo  = fopen("text1.txt","r");
    if(arquivo == NULL){
        printf("Erro ao criar o arquivo\n");
        return 1;
    }
    int leitor;
    printf("Conteúdo do arquivo:\n");

    /* fscanf(arquivo, "%s - %s (%d créditos)\n", cod, nome, &cr);
    printf("Leu: %s\n%s\n%d\n", cod, nome, cr);  */

    /* while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    } */

    /* fscanf(arquivo, "%d", &leitor);
    printf("%d \n", leitor); */

    while (fscanf(arquivo, "%[^\n]%*c", linha) == 1) {
        printf("%s\n", linha);
    }
    
    for(int i = 0;i<MAX_IN_MEMORY;i++){

    }

    /*while(!feof(arquivo)) {
        leitor = fgets(arquivo);
    printf("%d", leitor);
    }*/ 

    return 0;
}


/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* nomeArquivo(char entrada[20],int numero) {
    char txt[] = ".txt";
    char numeroString[10];
    sprintf(numeroString, "%d", numero);
    strcat(nome, numeroString);
    strcat(nome, txt);

    char* resultado = (char*)malloc(strlen(nome) + 1); // Aloca memória para a string resultante
    strcpy(resultado, nome);

    return resultado;
}

int main() {
    int numero = 2;
    char* nome = nomeArquivo("entrada",numero);
    printf("Nome do arquivo: %s\n", nome);

    free(nome); // Libera a memória alocada para a string

    return 0;
} */
