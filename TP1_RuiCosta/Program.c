#include "Cliente.h"
#include "Gestor.h"
#include "MeioDeME.h"
#include "Cidades.h"
#include "Constantes.h"
#include "Aluguer.h"

//existem varios erros com os ficheiros
int main()
{

	//Clientes

	ListaClientes* inicio = NULL;

	inicio = LerListaC(inicio);
	////
	//Cliente Jorge = {1234567, "jorge", "rua", 30.2};
	//Cliente manel = { 2738732, "manel", "casa", 5 };

	////inicio = AdicionarClientes(inicio, Jorge);
	////inicio = AdicionarClientes(inicio, manel);

	/////*if (ExisteCliente(&inicio, 1234567) == true)
	////{
	////	printf("sim");
	////}*/

	MostraListaC(inicio);
	//inicio = EliminarCliente(&inicio, 2738732);
	////EliminaListaC(&inicio);

	////ModificarCliente(&inicio, "jorge");

	//MostraListaC(inicio);
	////GravaListaC(inicio);
	////MostraListaC(inicio);

	printf("\n\n\n");


	//Gestores

	ListaGestor* iniciog = NULL;

	iniciog = LerListaG(iniciog);

	//Gestor joao = { 1234567, "joao", "rua", "ola123" };
	//Gestor quim = { 2738732, "quim", "casa", "adeus9" };

	////inicio = AdicionarGestor(inicio, joao);
	////inicio = AdicionarGestor(inicio, quim);

	///*if (ExisteGestor(iniciog, 2738732) == true)
	//{
	//	printf("sim\n");
	//}
	//else
	//{
	//	printf("nao\n");
	//}*/

	////inicio = EliminarGestor(inicio, 2738732);


	////ModificarGestor(&inicio, "jorge");

	MostraListaG(iniciog);
	//GravaListaG(iniciog);
	//EliminaListaG(&iniciog);
	//MostraListaG(iniciog);

	printf("\n\n\n");

	//Meios De Mobilidade

	ListaME* iniciom = NULL;

	iniciom = LerListaM(iniciom);

	MeioDeME tesla = { "tesla", "73-op-78", M1, 4, 350, 2 };
	MeioDeME ix = { "ix", "21-er-42", M3, 5, 300, 1 };
	MeioDeME i7 = { "i7", "67-kl-12", M4, 2, 500, 4 };
	MeioDeME teste = { "teste", "11-aa-11", M2, 1, 460, 2 };

	iniciom = AdicionarMeios(iniciom, tesla);
	iniciom = AdicionarMeios(iniciom, ix);
	iniciom = AdicionarMeios(iniciom, i7);
	iniciom = AdicionarMeios(iniciom, teste);

	//char maux[] = "73-op-78";

	/*if (ExisteMeio(iniciom, maux) == true)
	{
		printf("sim\n");
	}
	else
	{
		printf("nao\n");
	}*/

	//iniciom = EliminarMeio(inicio, );

	//VeiculosNumaLocalidde(iniciom, 2);
	MostraListaM(iniciom);
	//iniciom = ordenarMPorAutonomia(iniciom);
	//MostraListaM(iniciom);
	//GravaListaM(iniciom);
	//EliminaListaG(&iniciom);
	//MostraListaG(iniciom);

	printf("\n\n\n");

	//Cidades e Adjacencias

	Cidades* inicioca = NULL;
	
	//inicioca = LerListaCidade(inicioca);
	//inicioca = LerAdjacencias(inicioca);

	Cidades guimaraes = { "Gumaraes", 1, NULL, NULL };
	Cidades braga = { "Braga", 2, NULL, NULL };
	Cidades porto = { "Porto", 3, NULL, NULL };
	Cidades benfica = { "Benfica", 4, NULL, NULL };

	inicioca = AdicionarCidade(inicioca, guimaraes);
	inicioca = AdicionarCidade(inicioca, braga);
	inicioca = AdicionarCidade(inicioca, porto);
	inicioca = AdicionarCidade(inicioca, benfica);
	
	AdjFile a11 = { 1, 2, 20 };
	AdjFile a3 = { 3, 2, 50 };
	AdjFile a7 = { 1, 3, 50 };
	AdjFile a1 = { 3, 4, 300 };

	AdicionarAdj(inicioca, a11);
	AdicionarAdj(inicioca, a3);
	AdicionarAdj(inicioca, a7);
	AdicionarAdj(inicioca, a1);

	char caux[] = "Porto";

	/*if (ExisteCidade(inicioca, caux) == true)
	{
		printf("sim\n");
	}*/

	MostraListaCidades(inicioca);
	//GravaListaCidade(inicioca);
	//EliminaListCidade(&inicioca);
	//MostraListaCidade(inicioca);

	printf("\n\n\n");

}
