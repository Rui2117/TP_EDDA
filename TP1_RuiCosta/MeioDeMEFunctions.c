#include "MeioDeME.h"

//Adiciona clientes inseridos 
ListaME* AdicionarMeios(ListaME* head, MeioDeME novo)
{
    //Cria lista auxiliar
    ListaME* aux = (ListaME*)malloc(sizeof(ListaME));
    if (aux == NULL)
    {
        free(aux);
        return head;
    }
    aux->proximo = NULL;
    aux->meioDeME = novo;

    //Caso a lista esteja vazia
    if (head == NULL)
    {
        return aux;
    }
    else
    {
        ListaME* posicaoAtual = head;

        //Procurar o ultimo elemento na lista
        while (posicaoAtual->proximo != NULL)
        {
            posicaoAtual = posicaoAtual->proximo;
        }
        posicaoAtual->proximo = aux;
    }

    return head;
}

ListaME* LerListaM(ListaME* h)
{
    //abrir o ficheiro
    FILE* fp;
    fp = fopen(binFileM, "rb");

    //verificar o ficheiro
    if (fp == NULL)
    {
        return h;
    }

    MeioDeME aux;
    //inserir os dados dentro do ficheiro na lista
    while (fread(&aux, sizeof(MeioDeME), 1, fp) != NULL)
    {
        h = AdicionarMeios(h, aux);
    }
    fclose(fp);
    return h;
}

ListaME* EliminarMeio(ListaME* h, char x)
{
    return h;
}

//Mostra a lista 
void MostraListaM(ListaME* head)
{
    ListaME* aux = head;

    while (aux != NULL)
    {
        //enquanto que a lista tiver membros escreve os parametros
        printf("%s\n", aux->meioDeME.nome);
        printf("%s\n", aux->meioDeME.matricula);
        printf("%d\n", aux->meioDeME.localizacao);
        printf("%d\n", aux->meioDeME.carga);
        printf("%d\n", aux->meioDeME.autonomia);
        printf("%d\n", aux->meioDeME.custo);
        aux = aux->proximo;
    }
}

ListaME* ordenarMPorAutonomia(ListaME* head) 
{
    if (head == NULL)
    {
        return NULL;
    }
    ListaME* aux = head;
    while (aux != NULL) 
    {
        ListaME* atual = head;
        while (atual->proximo != NULL) 
        {
            if (atual->meioDeME.autonomia < atual->proximo->meioDeME.autonomia) 
            {
                TrocaM(atual, atual->proximo);
            }
            atual = atual->proximo;
        }
        aux = aux->proximo;
    }
    return head;
}


ListaME* TrocaM(ListaME* x, ListaME* y)
{
    MeioDeME aux = x->meioDeME;
    x->meioDeME = y->meioDeME;
    y->meioDeME = aux;
}

int GravaListaM(ListaME* h)
{
    //testa se a lista é vazia
    if (h == NULL)
    {
        return (-1);
    }

    ListaME* aux = h;

    //abrir o ficheiro
    FILE* fp;
    fp = fopen(binFileM, "wb");

    if (fp == NULL)
    {
        return (-2);
    }

    while (aux != NULL)
    {
        fwrite(&aux->meioDeME, sizeof(MeioDeME), 1, fp);
        aux = aux->proximo;
    }
    fclose(fp);

    return 1;
}

bool EliminaListaM(ListaME** h)
{
    ListaME* aux;
    ListaME* aux2 = *h;

    *h = NULL;
    //corre a lista de clientes 
    while (aux2 != NULL)
    {
        aux = aux2;
        aux2 = aux->proximo;
        free(aux);
    }
    return true;
}

bool ExisteMeio(ListaME* h, char x[])
{
    ListaME* aux = (ListaME*)malloc(sizeof(ListaME));
    if (aux == NULL)
    {
        free(aux);
        return h;
    }
    aux->proximo = h->proximo;
    aux->meioDeME = h->meioDeME;

    if (h == NULL)
    {
        return false;
    }
    while (h)
    {
        if (strcmp(h->meioDeME.matricula, x) == 0)
        {
            return true;
        }
        h = h->proximo;
    }

    return false;
}
