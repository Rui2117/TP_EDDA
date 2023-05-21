/*****************************************************************//**
 * \file   Cliente.h
 * \brief  Assinaturas de funções e defenição de classes para os clientes
 * 
 * \author Rui Costa
 * \date   March 2023
 *********************************************************************/

#include "Constantes.h"

#pragma once

//constantes

#define tNomeC 30
#define tMoradaC 80
#define txtFileC "CSaveTxt.txt"
#define binFileC "CSaveBin.bin"

//grafo exemplo
// 
// typedef struct AdjFile
// {
//	int codOrigem;
//	int codDestino;
//	float peso;
// }
// 
// typedef struct VerticeFile
// {
//	int cod;
//	char cidade[n];
// }VerticeFile;
// 
// int saveGraph(Vertice* g, char* fileName)
// {
//	if(g== NULL) retur 0;
//	FILE* fp;
//	fp=fopen(fileName, "wb");
// }
// 
// int savegAdj(Adj* adj, char*filename)
// {
//	if(adj==NULL) rturn 0;
// 
//	FILE* file;
//	file = fopen(fileName, "wb");
// 
//	if(f==NULL) return -1;
// 
//	Vertice* aux = g;
//	verticeFile auxfile;
//	while(g)
//	{
//	auxfile.cod= aux.cod;
//	auxfile.cidade=aux.cidade;
// 
//	fwrite(&auxFile->,1, sizeof());
//	fwrite(&auxfile->cod, 1, sizeof(aux->cod), fp);
//	fwrite(&auxdile->cidade, 1, sizeof(aux->cidade), fp);
//	aux=aux->next;
//	}
// 
//	fclose(filename);
// 
// 
//structs

typedef struct Cliente
{
	int nif;
	char nome[tNomeC], morada[tMoradaC];
	float saldo;
}Cliente;

typedef struct ListaClientes
{
	Cliente cliente;
	struct listaClientes *proximo;
}ListaClientes;

//assinaturas de funções

ListaClientes* AdicionarClientes(ListaClientes* listaC, Cliente cliente);//O
ListaClientes* LerListaC(ListaClientes* h);//O
ListaClientes* EliminarCliente(ListaClientes** h, int x);//X

void MostraListaC(ListaClientes* head);//O
int ModificarCliente(ListaClientes* h, int x);//X
int GravaListaC(ListaClientes* h);//O

bool EliminaListaC(ListaClientes** h);//O
bool ExisteCliente(ListaClientes* h, int x);//O