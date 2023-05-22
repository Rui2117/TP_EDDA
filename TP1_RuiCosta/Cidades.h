/*****************************************************************//**
 * \file   Cidades.h
 * \brief  
 * 
 * \author User
 * \date   May 2023
 *********************************************************************/

#include "Constantes.h"

#pragma once

//Constantes

#define tNomeCidades 30
#define txtFileCidades "CidadesSaveTxt.txt"
#define binFileCidades "CidadesSaveBin.bin"

#define txtFileAdj "AdjSaveTxt.txt"
#define binFileAdj "AdjSaveBin.bin"

//defenir os caminhos entre cidades

typedef struct Adj Adj;
struct Adj
{
	//int codOrigem;
	int codDestino;
	int peso;
	Adj* next;
};

typedef struct AdjFile 
{
	int codOrigem;
	int codDestino;
	int peso;
}AdjFile;

//defenir cidades

typedef struct Cidades Cidades;
struct Cidades 
{
	char nomeCidade[tNomeCidades];
	int codCidade;
	Adj* conexoes;
	Cidades* proximo;
};

typedef struct CidadeFile
{
	char nomeCidade[tNomeCidades];
	int codCidade;
}CidadeFile;

//typedef struct ListaCidades
//{
//	Cidades cidade;
//	struct ListaCidades *proximo;
//}ListaCidades;

//assinaturas de funções das cidades

Cidades* AdicionarCidade(Cidades* listaCidades, Cidades novo);//O
Cidades* LerListaCidade(Cidades* listaCidades);//O
Cidades* EliminarCidade(Cidades* listaCidades, int x);//X
Cidades* EncontrarCidade(Cidades* head, int x);//O

void MostraListaCidades(Cidades* listaCidades);//O
int GravaListaCidade(Cidades* listaCidades);//O

bool EliminaListaCidade(Cidades* listaCidades);//X
bool ExisteCidade(Cidades* h, int x);//X

//assinaturas das funções dos caminhos

//Cidades* AdicionarAdj(Cidades* listaCidades, AdjFile novo);//X/O
void AdicionarAdj(Cidades* cidades, AdjFile novo);//O
Cidades* LerAdjacencias(Cidades* head);//O

int EliminarAdj(Cidades* listaCidades, char x, char y);//X
bool EliminaListaAdj(Cidades* listaCidades, char x);//X


