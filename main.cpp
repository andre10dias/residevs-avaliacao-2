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
    	listaNomes.mostraMaior();
		listaNomes.mostraMenor();
		listaNomes.mostraMediana();
            break;
		}
        case 2:
		{
		listaDatas.entradaDeDados();
		listaDatas.mostraMaior();
		listaDatas.mostraMenor();
		listaDatas.mostraMediana();
            break;
		}
        case 3:
		{
		listaSalarios.entradaDeDados();
    	listaSalarios.mostraMaior();
		listaSalarios.mostraMenor();
		listaSalarios.mostraMediana();
            break;
		}
        case 4:
		{
		listaIdades.entradaDeDados();
		listaIdades.mostraMaior();
		listaIdades.mostraMenor();
		listaIdades.mostraMediana();
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

// vector<Lista*> listaDeListas;

	
	


	

	

	
	
		

	// for (Lista* l : listaDeListas) {
	// 	l->mostraMediana();
	// 	l->mostraMenor();
	// 	l->mostraMaior();
	// }
	
