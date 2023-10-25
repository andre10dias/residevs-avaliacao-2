#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cctype>

#include "include/funcoes_uteis.h"
#include "include/Lista.h"
// #include "include/ListaDatas.h"

#include "Data.cpp"
#include "ListaDatas.cpp"
#include "ListaNomes.cpp"
#include "ListaIdades.cpp"
#include "ListaSalarios.cpp"
#include "funcoes_uteis.cpp"

#define TRACO "-------------------------------------------------"

using namespace std;

int monta_menu(vector<string> itens, string titulo) {
    int op;
    cout << titulo << endl;
    for (auto item : itens) {
        cout << item << endl;
    }
    cout << "Opção: ";
    cin >> op;
    return op;
}

int main () {

ListaNomes listaNomes;
ListaDatas listaDatas;
ListaSalarios listaSalarios;
ListaIdades listaIdades;

 int opcao;
    vector<string> menu = {
        "-------------------------------------------------",
        "[1] Lista de nomes",
        "[2] Lista de datas",
        "[3] Lista de salários",
        "[4] Lista de idades",
        "[5] Sair."};

    while (true)
    {
        cout << TRACO << endl;
        opcao = monta_menu(menu, "DATAFRUTA - GERENCIAMENTO");

        cout << endl;

        switch (opcao)
        {
        case 1:
		{
		listaNomes.entradaDeDados();
        cout << endl;
        listaNomes.mostraMaior();
        cout << endl;
		listaNomes.mostraMenor();
        cout << endl;
		listaNomes.listarEmOrdem();
        cout << endl;
		listaNomes.mostraMediana();
        cout << endl;
        listaNomes.listarNPrimeiros();
        cout << endl;
            break;
		}
        case 2:
		{
		listaDatas.entradaDeDados();
        cout << endl;
		listaDatas.mostraMaior();
        cout << endl;
		listaDatas.mostraMenor();
        cout << endl;
		listaDatas.mostraMediana();
        cout << endl;
		listaNomes.listarNPrimeiros();
        cout << endl;

            break;
		}
        case 3:
		{
		listaSalarios.entradaDeDados();
        cout << endl;
    	listaSalarios.mostraMaior();
        cout << endl;
		listaSalarios.mostraMenor();
        cout << endl;
		listaSalarios.mostraMediana();
        cout << endl;
		listaNomes.listarNPrimeiros();
        cout << endl;

            break;
		}
        case 4:
		{
		listaIdades.entradaDeDados();
        cout << endl;
		listaIdades.mostraMaior();
        cout << endl;
		listaIdades.mostraMenor();
        cout << endl;
		listaIdades.mostraMediana();
        cout << endl;
		listaNomes.listarNPrimeiros();
        cout << endl;

			break;
		}
            
        case 5:
            cout << "Programa Finalizado.";
            exit(0);

        default:
            cout << "Opção invalida!" << endl;
            break;
        }
    }

}

