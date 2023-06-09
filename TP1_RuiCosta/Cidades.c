#include "Cidades.h"

//cidades
// 
//Cidades* AdicionarCidade(char nomeCidade, int codCidade, Cidades* head)
Cidades* AdicionarCidade(Cidades* head, Cidades novo)
{
    //Cria lista auxiliar
    Cidades* aux = (Cidades*)malloc(sizeof(Cidades));
    if (aux == NULL)
    {
        free(aux);
        return head;
    }
    aux->proximo = NULL;
    aux->conexoes = NULL;
    aux->codCidade = novo.codCidade;
    strcpy(aux->nomeCidade, novo.nomeCidade);


    //Caso a lista esteja vazia
    if (head == NULL)
    {
        return aux;
    }
    else
    {
        Cidades* posicaoAtual = head;

        //Procurar o ultimo elemento na lista
        while (posicaoAtual->proximo != NULL)
        {
            posicaoAtual = posicaoAtual->proximo;
        }
        posicaoAtual->proximo = aux;
        posicaoAtual->proximo->codCidade = aux->codCidade;
        strcpy(posicaoAtual->proximo->nomeCidade, aux->nomeCidade);
        posicaoAtual->proximo->conexoes = NULL;
        posicaoAtual->proximo->proximo = NULL;
    }

    return head;
}

Cidades* LerListaCidade(Cidades* head)
{
    //abrir o ficheiro
    FILE* file;
    file = fopen(binFileCidades, "rb");

    //verificar o ficheiro
    if (file == NULL)
    {
        return head;
    }

    CidadeFile aux;
    Cidades novo = { "", 0, NULL, NULL };

    //inserir os dados dentro do ficheiro na lista
    while (fread(&aux, sizeof(CidadeFile), 1, file) != NULL)
    {
        strcpy(novo.nomeCidade, aux.nomeCidade);
        novo.codCidade = aux.codCidade;
        head = AdicionarCidade(head, novo);
    }
    fclose(file);
    return head;
}

Cidades* LerAdjacencias(Cidades* head)
{
    //abrir o ficheiro
    FILE* file;
    file = fopen(binFileAdj, "rb");

    //verificar o ficheiro
    if (file == NULL)
    {
        return head;
    }
    AdjFile aux;
    while (fread(&aux, sizeof(AdjFile), 1, file) != NULL)
    {
        AdicionarAdj(head, aux);
    }
    fclose(file);

    return head;
}

Cidades* EncontrarCidade(Cidades* head, int x)
{
    Cidades* aux = head;

    if (head == NULL)
    {
        return NULL;
    }
    while (aux)
    {
        if (aux->codCidade == x)
        {
            return aux;
        }
        aux = aux->proximo;
    }
    return NULL;
}

void MostraListaCidades(Cidades* listaCidades)
{
    Cidades* aux = listaCidades;
    Adj* aux2 = NULL;

    while (aux != NULL)
    {
        //enquanto que a lista tiver membros escreve os parametros
        printf("%d\n", aux->codCidade);
        printf("%s\n", aux->nomeCidade);
        aux2 = aux->conexoes;
        while (aux2 != NULL)
        {            
            printf(" - %d\n", aux2->codDestino);
            printf(" - %d\n", aux2->peso);
            aux2 = aux2->next;
        }
        aux = aux->proximo;
    }
}

//percisa de testes

int GravaListaCidade(Cidades* head)
{
    if (head == NULL)
    {
        return (-1);
    }

    FILE* file;
    file = fopen(binFileCidades, "wb");
    if (file == NULL)
    {
        return (-2);
    }

    FILE* filea;
    filea = fopen(binFileAdj, "wb");
    if (filea == NULL)
    {
        return (-3);
    }

    Cidades* aux = head;
    CidadeFile auxfile;

    while (aux)
    {
        auxfile.codCidade = aux->codCidade;
        strcpy(auxfile.nomeCidade, aux->nomeCidade);

        fwrite(&auxfile, sizeof(CidadeFile), 1, file);

        
        if (aux->conexoes != NULL)
        {
            Adj* auxA = aux->conexoes;
            AdjFile auxfileA;

            while (aux->conexoes)
            {

                auxfileA.codOrigem = aux->codCidade;
                auxfileA.codDestino = aux->conexoes->codDestino;
                auxfileA.peso = aux->conexoes->peso;
                fwrite(&auxfileA, sizeof(AdjFile), 1, filea);

                aux->conexoes = aux->conexoes->next;
            }
        }
        aux = aux->proximo;
    }
    fclose(filea);
    fclose(file);
}

bool ExisteCidade(Cidades* h, char x[])
{
    Cidades* aux = (Cidades*)malloc(sizeof(Cidades));
    if (aux == NULL)
    {
        free(aux);
        return h;
    }
    aux->proximo = h->proximo;
    aux->codCidade = h->codCidade;
    aux->conexoes = h->conexoes;
    strcpy(aux->nomeCidade, h->nomeCidade);

    if (h == NULL)
    {
        return false;
    }
    while (aux)
    {
        if (strcmp(aux->nomeCidade, x) == 0)
        {
            return true;
        }
        aux = aux->proximo;
    }

    return false;
}

void AdicionarAdj(Cidades* head, AdjFile novo)
{
    Adj* novaAdj = (Adj*)malloc(sizeof(Adj));

    if (novaAdj == NULL) return;

    Cidades* cidade = EncontrarCidade(head, novo.codOrigem);

    novaAdj->codDestino = novo.codDestino;
    novaAdj->peso = novo.peso;
    novaAdj->next = NULL;

    if (cidade->conexoes == NULL)
    {
        cidade->conexoes = novaAdj;
    }
    else {
        Adj* adjancencia = cidade->conexoes;
        while (adjancencia->next != NULL) {
            if (adjancencia->codDestino == novaAdj->codDestino) return;
            adjancencia = adjancencia->next;
        }
        if (adjancencia->codDestino == novaAdj->codDestino) return;
        adjancencia->next = novaAdj;
    }

    AdjFile aux = { novo.codDestino, novo.codOrigem, novo.peso };
    AdicionarAdj(head, aux);
}

//Adj

/*
Cidades* AdicionarAdj(Cidades* head, AdjFile novo)
{
    //Cria lista auxiliar
    AdjFile* aux = (AdjFile*)malloc(sizeof(AdjFile));
    aux->codDestino = novo.codDestino;
    aux->codOrigem = novo.codOrigem;
    aux->peso = novo.peso;

    Cidades* posicaoAtual = head;
    Adj* adjacencias;

    Adj* a = (Adj*)malloc(sizeof(Adj));
    a->codDestino = aux->codDestino;
    a->peso = aux->peso;
    a->next = NULL;

    Adj* b = (Adj*)malloc(sizeof(Adj));
    b->codDestino = aux->codOrigem;
    b->peso = aux->peso;
    b->next = NULL;

    if (head == NULL)//ve se a lista esta vazia
    {
        return NULL;
    }
    while (posicaoAtual)
    {
        adjacencias = posicaoAtual->conexoes;

        if (posicaoAtual->codCidade == novo.codOrigem)
        {
            if (posicaoAtual->conexoes == NULL)
            {
                posicaoAtual->conexoes= a;
            }
            else
            {
                while (adjacencias->next)
                {
                    adjacencias = adjacencias->next;
                }
                adjacencias = a;
            }
        }

        adjacencias = posicaoAtual->conexoes;

        if (posicaoAtual->codCidade == novo.codDestino)
        {
            if (posicaoAtual->conexoes == NULL)
            {
                posicaoAtual->conexoes = b;
            }
            else
            {
                while (adjacencias->next)
                {
                    adjacencias = adjacencias->next;
                }
                adjacencias = b;
            }
        }
        posicaoAtual = posicaoAtual->proximo;
    }

    return head;
}*/
