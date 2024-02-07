#include <stdio.h>
#include <stdlib.h>

typedef struct NoLista
{
    int chave;
    struct NoLista *proximo;
    struct NoLista *anterior;
} NoLista;

typedef struct
{
    NoLista *inicio;
    int qtdeElementos;
} ListaDupla;

void iniciaListaDupla(ListaDupla *lista)
{
    lista->inicio = NULL;
    lista->qtdeElementos = 0;
}

void inserirListaDupla(ListaDupla *lista, int valor)
{
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
    novo->chave = valor;
    novo->proximo = NULL;
    novo->anterior = NULL;

    // Caso a lista esteja vazia
    if (lista->inicio == NULL)
    {
        lista->inicio = novo;
    }
    else
    {
        NoLista *atual = lista->inicio;

        // Encontrar o ponto de inserção
        while (atual->proximo != NULL && valor > atual->chave)
        {
            atual = atual->proximo;
        }

        // Inserir antes de atual
        if (valor <= atual->chave)
        {
            novo->proximo = atual;
            novo->anterior = atual->anterior;
            if (atual->anterior != NULL)
            {
                atual->anterior->proximo = novo;
            }
            atual->anterior = novo;

            // Se o novo elemento foi inserido no início, atualizar o início
            if (atual == lista->inicio)
            {
                lista->inicio = novo;
            }
        }
        // Inserir depois de atual
        else
        {
            novo->proximo = NULL;
            novo->anterior = atual;
            atual->proximo = novo;
        }
    }

    lista->qtdeElementos++;
}

// Função para imprimir a lista na ordem crescente
void imprimeListaDuplaCres(ListaDupla *lista)
{
    NoLista *atual = lista->inicio;

    printf("Lista Crescente = [");
    while (atual != NULL)
    {
        printf("%d ", atual->chave);
        atual = atual->proximo;
    }
    printf("]\n");
}
// Função para imprimir a lista na ordem decrescente
void imprimeListaDuplaDecres(ListaDupla *lista)
{
    NoLista *atual = lista->inicio;

    // Avançar até o final da lista
    while (atual != NULL && atual->proximo != NULL)
    {
        atual = atual->proximo;
    }

    printf("Lista Decrescente = [");
    while (atual != NULL)
    {
        printf("%d ", atual->chave);
        atual = atual->anterior;
    }
    printf("]\n");
}

// Função para remover um elemento específico da lista
void removerElementoListaDupla(ListaDupla *lista, int chave)
{
    NoLista *atual = lista->inicio;

    // Encontrar o elemento a ser removido
    while (atual != NULL && atual->chave != chave)
    {
        atual = atual->proximo;
    }

    // Se o elemento foi encontrado
    if (atual != NULL)
    {
        // Atualizar os ponteiros do elemento anterior e posterior
        if (atual->anterior != NULL)
        {
            atual->anterior->proximo = atual->proximo;
        }
        else
        {
            lista->inicio = atual->proximo; // Se for o primeiro elemento
        }

        if (atual->proximo != NULL)
        {
            atual->proximo->anterior = atual->anterior;
        }

        // Liberar a memória do elemento removido
        free(atual);

        lista->qtdeElementos--;
    }
}

// Função para liberar a memória alocada para a lista
void liberarListaDupla(ListaDupla *lista)
{
    NoLista *atual = lista->inicio;
    NoLista *proximo;

    while (atual != NULL)
    {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    lista->inicio = NULL; // Atualizar o ponteiro de início para refletir a lista vazia
    lista->qtdeElementos = 0;
}

int main()
{
    ListaDupla lista;
    iniciaListaDupla(&lista);

    // Inserção de elementos
    inserirListaDupla(&lista, 10);
    inserirListaDupla(&lista, 3);
    inserirListaDupla(&lista, 9);
    inserirListaDupla(&lista, 15);
    inserirListaDupla(&lista, 1);

    // Impressão na ordem crescente
    imprimeListaDuplaDecres(&lista);
    // Remover o elemento com chave 9
    removerElementoListaDupla(&lista, 9);
    // Impressão na ordem decrescente
    imprimeListaDuplaCres(&lista);
    // Liberação de memória
    liberarListaDupla(&lista);

    return 0;
}