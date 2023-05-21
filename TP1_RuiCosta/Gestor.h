/*****************************************************************//**
 * \file   Gestor.h
 * \brief  Assinaturas de funções e defenição de classes para os gestores
 *
 * \author Rui Costa
 * \date   March 2023
 *********************************************************************/

#include "Constantes.h"

#pragma once

//constantes

#define tNomeG 30
#define tMoradaG 80
#define tPassword 20
#define txtFileG "GSaveTxt.txt"
#define binFileG "GSaveBin.bin"

//structs

typedef struct Gestor
{
	int nif;
	char nome[tNomeG], morada[tMoradaG], password[tPassword];
}Gestor;

typedef struct listaGestor
{
	Gestor gestor;
	struct listaGestor* proximo;
}ListaGestor;

//assinaturas de funções

ListaGestor* AdicionarGestor(ListaGestor* listaG, Gestor gestor);//O
ListaGestor* LerListaG(ListaGestor* h);//O
ListaGestor* EliminarGestor(ListaGestor* h, int x);//X

void MostraListaG(ListaGestor* h);//O
int ModificarGestor(ListaGestor* h);//X
int GravaListaG(ListaGestor* h);//O

bool EliminaListaG(ListaGestor** h);//O
bool ExisteGestor(ListaGestor* h, int x);//O