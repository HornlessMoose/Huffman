#include <stdio.h>
#include <stdlib.h>
#include "CUnit/Basic.h"

typedef unsigned char Byte;

typedef struct HuffmanArvore {
    void* byteArvore;
    size_t tipoDado;
    int frequencia;
    struct HuffmanArvore* esquerda;
    struct HuffmanArvore* direita;
    struct HuffmanArvore* proximo;
} HuffmanArvore;

typedef struct filaPrioridade{
    HuffmanArvore* cabeca;
}filaPrioridade;


HuffmanArvore* criarNo(void* byte, size_t tipoDado,int frequencia);

filaPrioridade* criarFila();

int filaVazia(filaPrioridade* fila);

void enfileirar(filaPrioridade* fila, HuffmanArvore* novoNo);

HuffmanArvore* desenfileirar(filaPrioridade* fila);

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

HuffmanArvore* criarNo(void* byte, size_t tipoDado,int frequencia){
    HuffmanArvore* novoNo = (HuffmanArvore*) malloc(sizeof(HuffmanArvore));

    novoNo->tipoDado = tipoDado;
    novoNo->byteArvore = malloc(tipoDado);
    novoNo->frequencia = frequencia;

    novoNo->esquerda = novoNo->direita = novoNo->proximo = NULL;

    unsigned i;
    for(i = 0; i < tipoDado; i++)
        *(Byte*)(novoNo->byteArvore + i) = *(Byte*)(byte + i);

    return novoNo;

}


filaPrioridade* criarFila(){
    filaPrioridade* novaFila = (filaPrioridade*) malloc(sizeof(filaPrioridade));

    novaFila->cabeca = NULL;

    return novaFila;
}


int filaVazia(filaPrioridade* fila){
    return (fila->cabeca == NULL);

}

void enfileirar(filaPrioridade* fila, HuffmanArvore* novoNo){


    if(filaVazia(fila) || fila->cabeca->frequencia >= novoNo->frequencia){
        novoNo->proximo = fila->cabeca;
        fila->cabeca = novoNo;
    }
    else{
        HuffmanArvore* temp = fila->cabeca;
        while(temp->proximo != NULL && temp->proximo->frequencia < novoNo->frequencia){
            temp = temp->proximo;
        }
        novoNo->proximo = temp->proximo;
        temp->proximo = novoNo;

    }
}

HuffmanArvore* desenfileirar(filaPrioridade* fila){
    if(!filaVazia(fila)){
        HuffmanArvore* No = fila->cabeca;
        fila->cabeca = fila->cabeca->proximo;
        No->proximo = NULL;
        return No;
    }
    return NULL;
}


void testeCriarNo() {
    size_t tipoDado = sizeof(Byte);
    Byte byte = '*';
    int frequencia = 13;
    HuffmanArvore* novoNo = criarNo(&byte, tipoDado, frequencia);
    if (novoNo != NULL) {
        CU_ASSERT(*(Byte*)(novoNo->byteArvore) == byte);
    }
}



void testeCriarFila() {
    filaPrioridade* fila = criarFila();
    if (fila != NULL) {
        CU_ASSERT(fila->cabeca == NULL);
    }
}

void testeFilaVazia() {
    filaPrioridade* fila = criarFila();

    if (!filaVazia(fila)) {
        CU_ASSERT(1);
    }
}



void testEnfileirar() {
    Byte byte = 'T';
    int frequencia = 42;
    filaPrioridade* fila = criarFila();
    HuffmanArvore* arvore = criarNo(&byte, sizeof(Byte), frequencia);
    enfileirar(fila, arvore);


    if (!filaVazia(fila)) {
        CU_ASSERT( *(Byte*)(fila->cabeca->byteArvore) == byte && fila->cabeca->frequencia == frequencia);
    }
}

void testDesenfileirar() {
	  Byte byte = 'G';
	    int frequencia = 11;
	    filaPrioridade* fila = criarFila();
	    HuffmanArvore* arvore = criarNo(&byte, sizeof(Byte), frequencia);
	    enfileirar(fila, arvore);
	    HuffmanArvore* validador = desenfileirar(fila);

	    if (!filaVazia(fila)) {
	        CU_ASSERT( validador->frequencia == 101 && *(Byte*)(validador->byteArvore) == byte);
	    }
}

int main() {
    CU_pSuite pSuite = NULL;


    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();


    pSuite = CU_add_suite("CUnit-Huffman", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }


    if ((NULL == CU_add_test(pSuite, "testeCriarNo", testeCriarNo)) ||
            (NULL == CU_add_test(pSuite, "testeCriarFila", testeCriarFila)) ||
            (NULL == CU_add_test(pSuite, "testeFilaVazia", testeFilaVazia)) ||
            (NULL == CU_add_test(pSuite, "testeEnfileirar", testEnfileirar)) ||
            (NULL == CU_add_test(pSuite, "testeDesenfileirar", testDesenfileirar))) {
        CU_cleanup_registry();
        return CU_get_error();
    }


    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    getchar();
    return CU_get_error();
}
