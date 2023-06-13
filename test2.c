#include <stdio.h>
#include <stdlib.h>

char* nomeArquivo(int numero) {
    char* nome_arquivo = (char*)malloc(sizeof(char) * 15); // Tamanho máximo necessário é 13: "entradaX.txt\0"
    sprintf(nome_arquivo, "entrada%d.txt", numero);
    return nome_arquivo;
}

int main() {
    int numero = 5;
    char* nome_arquivo = nomeArquivo(numero);
    printf("%s\n", nome_arquivo);
    free(nome_arquivo);

    return 0;
}
