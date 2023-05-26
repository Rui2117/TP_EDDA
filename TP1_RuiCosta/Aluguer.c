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

Aluguer* fazerAluguer(AluguerFile* aluguer, ListaClientes* hc, ListaME* hm, Cidades* hca, Aluguer* h)
{
    Cidades* auxca = EncontrarCidade(hca, aluguer->origem);
    Cidades* auxcd = EncontrarCidade(hca, aluguer->destino);
    ListaME* auxme = EncontrarMeio(hm, aluguer->veiculo);

    if (ExisteCidade(hca, auxca->codCidade) == false) return h;
    if (ExisteCidade(hca, auxcd->codCidade) == false) return h;
    if (ExisteCliente(hc, aluguer->cliente) == false) return h;
    if (ExisteMeio(hm, aluguer->veiculo) == false) return h;

    //Cria lista auxiliar
    Aluguer* aux = (Aluguer*)malloc(sizeof(Aluguer));
    aux->cliente = aluguer->cliente;
    strcpy(aux->veiculo, aluguer->veiculo);
    aux->origem = aluguer->origem;
    aux->destino = aluguer->destino;
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
        //procurar adj para fazer o calculo do custo


        posicaoAtual->proximo = aux;
    }

    return h;
}
