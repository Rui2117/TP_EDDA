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


typedef struct Aluguer
{
	int codAluguer;
	int cliente;
	int veiculo;
	int origem;
	int destino;
	float custo;
	struct Aluguer* proximo;
}Aluguer;
 
typedef struct AluguerFile
{
	int codAluguer;
	int cliente;
	int veiculo;
	int origem;
	int destino;
	float custo;
}AluguerFile;

 //typedef struct verticefile
 //{
	//int cod;
	//char cidade[n];
 //}verticefile;
 //
 //int saveGraph(Vertice* g, char* fileName)
 //{
	//if(g== NULL) retur 0;
	//FILE* fp;
	//fp=fopen(fileName, "wb");
 //}

//assinaturas de funções

