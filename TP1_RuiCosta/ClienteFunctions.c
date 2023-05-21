#include "Cliente.h"

//Adiciona clientes inseridos 
ListaClientes* AdicionarClientes(ListaClientes* head, Cliente novo)
{
    //Cria lista auxiliar
    ListaClientes* aux = (ListaClientes*)malloc(sizeof(ListaClientes));
    if (aux == NULL)
    {
        free(aux);
        return head;
    }
    aux->proximo = NULL;
    aux->cliente = novo;

    //Caso a lista esteja vazia
    if (head == NULL)
    {
        //head = aux;
        return aux;
    }
    else
    {
        ListaClientes* posicaoAtual = head;

        //Procurar o ultimo elemento na lista
        while (posicaoAtual->proximo != NULL)
        {
            posicaoAtual = posicaoAtual->proximo;
        }
        posicaoAtual->proximo = aux;
    }

    return head;
}

ListaClientes* LerListaC(ListaClientes* h)
{
    // ListaClientes* aux = h;

    //abrir o ficheiro
    FILE* fp;
    fp = fopen(binFileC, "rb");

    //verificar o ficheiro
    if (fp == NULL)
    {
        return h;
    }

    Cliente aux;
    //inserir os dados dentro do ficheiro na lista
    while (fread(&aux, sizeof(Cliente), 1, fp) != NULL)
    {
        h=AdicionarClientes(h, aux);
    }
    fclose(fp);
    return h;
}

//elimina um cliente da lista
//nao sei como usar o free
ListaClientes* EliminarCliente(ListaClientes** h, int x)
{
    //Caso a lista esteja vazia
    if (h == NULL)
    {
        return h;
    }

    ListaClientes* posicaoAtual = h;
    ListaClientes* anterior = h;
    //encontra o elemento a eliminar
    if (posicaoAtual->cliente.nif == x)
    {
        posicaoAtual = anterior->proximo;
        free(anterior);
        return posicaoAtual;
    }
    while (posicaoAtual != NULL)
    {
        if (posicaoAtual->cliente.nif == x)
        {
            anterior->proximo = posicaoAtual->proximo;
            free(anterior);

            return (h);
        }
        anterior = posicaoAtual;
        posicaoAtual = posicaoAtual->proximo;
    }
    return h;
}

//Mostra a lista 
void MostraListaC(ListaClientes* head)
{
    ListaClientes* aux = head;

    while (aux != NULL)
    {
        //enquanto que a lista tiver membros escreve os parametros
        printf("%s\n", aux->cliente.nome);
        printf("%s\n", aux->cliente.morada);
        printf("%d\n", aux->cliente.nif);
        printf("%f\n", aux->cliente.saldo);
        aux = aux->proximo;
    }
}

//Modificar um parametro de Cliente
//nao sei como fazer isto dar certo
int ModificarCliente(ListaClientes* h,char n , int x)
{
    //Caso a lista esteja vazia
    if (h == NULL)
    {
        return -1;
    }
    ListaClientes* aux = h;

    while (aux)
    {
        if ("nome" == n)
        {
            char nome2[tNomeC] = "antonio";

            strcpy(aux->cliente.nome, nome2);
            return 1;
        }
        if ("nif" == x)
        {
            int nif2 = 123456789;

            aux->cliente.nif = nif2;
            return 2;
        }
        if ("morada" == x)
        {
            char nome2[tNomeC] = "antonio";

            strcpy(aux->cliente.morada, nome2);
            return 3;
        }

        aux = aux->proximo;
    }
    return -2;
}

//Gravar a lista 
int GravaListaC(ListaClientes* h)
{
    //testa se a lista é vazia
    if (h == NULL)
    {
        return (-1);
    }

    ListaClientes* aux = h;

    //abrir o ficheiro
    FILE* fp;
    fp = fopen(binFileC, "wb");

    if (fp == NULL)
    {
        return (-2);
    }

    while (aux != NULL)
    {
        fwrite(&aux->cliente, sizeof(Cliente), 1, fp);
        aux = aux->proximo;
    }
    fclose(fp);

    return 1;
}

//Eliminar lista de clientes 
bool EliminaListaC(ListaClientes** h)
{
    //
    ListaClientes* aux;
    ListaClientes* aux2 = *h;

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

//procura o cliente pelo nif
bool ExisteCliente(ListaClientes* h, int x)
{
    if (h == NULL)
    {
        return false;
    }
    while (h)
    {
        if (h->cliente.nif == x)
        {
            return true;
        }
        h = h->proximo;
    }

    return false;
}

