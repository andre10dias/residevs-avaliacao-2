#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cctype>

#include "Lista.cpp"
#include "Data.cpp"
#include "ListaDatas.cpp"
#include "ListaNomes.cpp"
#include "ListaIdades.cpp"
#include "ListaSalarios.cpp"
#include "funcoes_uteis.cpp"

using namespace std;


int main () {
	// vector<Lista*> listaDeListas;

	// ListaNomes listaNomes;
	// listaNomes.entradaDeDados();
    // listaNomes.mostraMediana();
    // listaNomes.mostraMenor();
    // listaNomes.mostraMaior();
	//listaDeListas.push_back(&listaNomes);

	ListaDatas listaDatas;
	listaDatas.entradaDeDados();
	listaDatas.imprimir();
	listaDatas.mostraMaior();
	listaDatas.mostraMenor();
	listaDatas.mostraMediana();
	//listaDeListas.push_back(&listaDatas);

	// ListaSalarios listaSalarios;
	// listaSalarios.entradaDeDados();
    // listaSalarios.mostraMediana();
    // listaSalarios.mostraMenor();
    // listaSalarios.mostraMaior();

	//listaDeListas.push_back(&listaSalarios);

	// ListaIdades listaIdades;
	// listaIdades.entradaDeDados();
	// listaDeListas.push_back(&listaIdades);

	// for (Lista* l : listaDeListas) {
	// 	l->mostraMediana();
	// 	l->mostraMenor();
	// 	l->mostraMaior();
	// }
}