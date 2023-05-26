/*****************************************************************//**
 * \file   MeioDeME.h
 * \brief  Assinaturas de funções e defenição de classes para os Meios de Mobilidade Eletrica
 *
 * \author Rui Costa
 * \date   March 2023
 *********************************************************************/

#include "Constantes.h"

#pragma once

//constantes

#define tNomeM 20
#define tGeocodigo 20
#define tMatricula 8
#define txtFileM "MSaveTxt.txt"
#define binFileM "MSaveBin.bin"

 //enums

typedef enum tCarga
{
	M1,
	M2,
	M3,
	M4
}tCarga;

//structs


typedef struct MeioDeME
{
	char nome[tNomeM], matricula[tMatricula];
	tCarga carga;
	int custo, autonomia, localizacao;
}MeioDeME;

typedef struct ListaME ListaME;
struct ListaME
{
	MeioDeME meioDeME;
	ListaME* proximo;
};

//assinaturas de funções

ListaME* AdicionarMeios(ListaME* listaMeios, MeioDeME veiculo);//O
ListaME* LerListaM(ListaME* h);//O
ListaME* EliminarMeio(ListaME* h, char x);//X
ListaME* TrocaM(ListaME* x, ListaME* y);//O
ListaME* OrdenarMPorAutonomia(ListaME* head);//O
ListaME* EncontrarMeio(ListaME* h, char x[]);//O

void MostraListaM(ListaME* head);//O
void VeiculosNumaLocalidde(ListaME* head, int cidade);//O
int GravaListaM(ListaME* h);//O

bool EliminaListaM(ListaME** h);//O
bool ExisteMeio(ListaME* h, char x[]);//O
