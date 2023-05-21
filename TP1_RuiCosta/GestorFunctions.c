/*****************************************************************//**
 * \file   GestorFunctions.c
 * \brief  
 * 
 * \author User
 * \date   March 2023
 *********************************************************************/
#include "Gestor.h"

//Adiciona gestor inseridos a lista
ListaGestor* AdicionarGestor(ListaGestor* head, Gestor novo)
{
    //Cria lista auxiliar
    ListaGestor* aux = (ListaGestor*)malloc(sizeof(ListaGestor));
    if (aux == NULL)
    {
        free(aux);
        return head;
    }
    aux->proximo = NULL;
    aux->gestor = novo;

    //Caso a lista esteja vazia
    if (head == NULL)
    {
        //head = aux;
        return aux;
    }
    else
    {
        ListaGestor* posicaoAtual = head;

        //Procurar o ultimo elemento na lista
        while (posicaoAtual->proximo != NULL)
        {
            posicaoAtual = posicaoAtual->proximo;
        }
        posicaoAtual->proximo = aux;
    }

    return head;
}

ListaGestor* LerListaG(ListaGestor* h)
{
    //abrir o ficheiro
    FILE* fp;
    fp = fopen(binFileG, "rb");

    //verificar o ficheiro
    if (fp == NULL)
    {
        return h;
    }

    Gestor aux;
    //inserir os dados dentro do ficheiro na lista
    while (fread(&aux, sizeof(Gestor), 1, fp) != NULL)
    {
        h = AdicionarGestor(h, aux);
    }
    fclose(fp);
    return h;
}

ListaGestor* EliminarGestor(ListaGestor* h, int x)
{
    return h;
}

//Mostra a lista 
void MostraListaG(ListaGestor* head)
{
    ListaGestor* aux = head;

    //enquanto que a lista tiver membros escreve os parametros
    while (aux != NULL)
    {
        printf("%s\n", aux->gestor.nome);
        printf("%s\n", aux->gestor.morada);
        printf("%s\n", aux->gestor.password);
        printf("%d\n", aux->gestor.nif);
        aux = aux->proximo;
    }
}

int ModificarGestor(ListaGestor* h)
{
    return 1;
}

int GravaListaG(ListaGestor* h)
{
    //testa se a lista é vazia
    if (h == NULL)
    {
        return (-1);
    }

    ListaGestor* aux = h;

    //abrir o ficheiro
    FILE* fp;
    fp = fopen(binFileG, "wb");

    if (fp == NULL)
    {
        return (-2);
    }

    while (aux != NULL)
    {
        fwrite(&aux->gestor, sizeof(Gestor), 1, fp);
        aux = aux->proximo;
    }
    fclose(fp);

    return 1;
}

bool EliminaListaG(ListaGestor** h)
{
    ListaGestor* aux;
    ListaGestor* aux2 = *h;

    *h = NULL;
    //corre a lista de gestores 
    while (aux2 != NULL)
    {
        aux = aux2;
        aux2 = aux->proximo;
        free(aux);
    }
    return true;
}

bool ExisteGestor(ListaGestor* h, int x)
{
    if (h == NULL)
    {
        return false;
    }
    while (h)
    {
        if (h->gestor.nif == x)
        {
            return true;
        }
        h = h->proximo;
    }

    return false;
}