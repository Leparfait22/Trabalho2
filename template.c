/**
 * @file 01OrdenacaoExterna.c
 * @author Nome_do_Aluno
 * @version 0.1
 * @date 2023-06-10
 *
 * @copyright Copyright (c) 2023
 *
 * @brief Arquivo template para Questão 02 do trabalho de Pesquisa e Ordenação T2.
 *
 *      Implemente uma ordenação externa utilizando a restrição de que somente 5
 *  elementos podem ser armazenados em memória (vetores de teste no template). A
 *  definição deste limite está na variável MAX_IN_MEMORY abaixo.
 *
 *      Utilize os vetores comentados no código para realizar seus testes.
 *
 * Atenção: Antes de entregar, conferir se dos dados de documentação no início
 * do arquivo estão preenchidos corretamente.
 *
 */



#include <stdio.h>

#define MAX_IN_MEMORY 5

int main() {

    int chaves1 = {3, 98, 61, 62,  1, 99, 57, 98, 58, 18, 59, 35, 82, 91, 52, 95, 46,
        69, 48, 82, 52,  4, 87, 38, 44, 42, 72,  2, 95, 84, 34, 40, 23, 11, 75,
        37, 62, 96, 12, 22, 56, 20, 64,  2, 30, 48,  6, 19, 34, 31};
    int chaves2 = {57, 91, 21, 89, 72, 74, 46, 61, 26, 50, 85, 76, 53, 22, 15, 40, 90, 2, 94, 54};
    int chaves3 = {9,  2, 15, 19, 10, 14,  4, 13,  2, 19};
    int chaves4 = {178, 231, 244, 292, 321, 356, 389, 421, 482, 488, 490, 502, 546, 641, 694, 786, 841, 890, 899, 922};

    /*int chaves1 = {3, 98, 61, 62,  1,/ 99, 57, 98, 58, 18/, 59, 35, 82, 91, 52/, 95, 46,
    69, 48, 82/, 52,  4, 87, 38, 44,/ 42, 72,  2, 95, 84,/ 34, 40, 23, 11, 75,/
    37, 62, 96, 12, 22,/ 56, 20, 64,  2, 30,/ 48,  6, 19, 34, 31/};
    int chaves2 = {57, 91, 21, 89, 72,/ 74, 46, 61, 26, 50,/ 85, 76, 53, 22, 15,/ 40, 90, 2, 94, 54};
    int chaves3 = {9,  2, 15, 19, 10,/ 14,  4, 13,  2, 19};
    int chaves4 = {178, 231, 244, 292, 321,/ 356, 389, 421, 482, 488,/ 490, 502, 546, 641, 694,/ 786, 841, 890, 899, 922};*/

    int tamanho = sizeof(chaves1) / sizeof(chaves1[]);
    printf("Tamanho = %d\n",tamanho);


    return 0;
}