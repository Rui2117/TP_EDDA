#include "Aluguer.h"
#include "Cidades.h"
#include "Cliente.h"
#include "Constantes.h"
#include "MeioDeME.h"


//
/*int codAluguer;
	int cliente;
	int veiculo;
	int origem;
	int destino;
	float custo;*/

Aluguer* fazerAluguer(int cliente, int meio, int cidadeOrigem, int cidadeDestino, Aluguer* h)
{
    //Cria lista auxiliar
    Aluguer* aux = (Aluguer*)malloc(sizeof(Aluguer));
    aux->cliente = cliente;
    aux->veiculo = meio;
    aux->origem = cidadeOrigem;
    aux->destino = cidadeDestino;
    aux->proximo = NULL;

    //Caso a lista esteja vazia
    if (h == NULL)
    {
        aux->codAluguer = 0;
        //procurar adj para fazer o calculo do custo

        h = aux;
        return h;
    }
    else
    {
        Aluguer* posicaoAtual = h;

        //Procurar o ultimo elemento na lista
        while (posicaoAtual->proximo != NULL)
        {
            posicaoAtual = posicaoAtual->proximo;
        }
        aux->codAluguer = posicaoAtual->codAluguer + 1;
        posicaoAtual->proximo = aux;
    }

    return h;
}
