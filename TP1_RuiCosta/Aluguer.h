/*****************************************************************//**
 * \file   Aluguer.h
 * \brief  Assinaturas de funções e defenição de classes para os Aluguers
 * 
 * \author User
 * \date   May 2023
 *********************************************************************/

#include "Constantes.h"
#include "Cliente.h"
#include "MeioDeME.h"
#include "Gestor.h"
#include "Cidades.h"

#pragma once


typedef struct Aluguer Aluguer;
struct Aluguer
{
	int codAluguer;
	int cliente;
	char veiculo[tMatricula];
	int origem;
	int destino;
	float custo;
	struct Aluguer* proximo;
};
 
typedef struct AluguerFile
{
	int codAluguer;
	int cliente;
	char veiculo[tMatricula];
	int origem;
	int destino;
	float custo;
}AluguerFile;

//assinaturas de funções

Aluguer* fazerAluguer(int cliente, int meio, int cidadeOrigem, int cidadeDestino, ListaClientes* hc, ListaME* hm, Cidades* hca, Aluguer* h);
