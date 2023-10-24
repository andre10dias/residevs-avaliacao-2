#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cctype>

#include "funcoes_uteis.h"

using namespace std;


class ListaIdades : Lista {
	vector<int> lista;
	
	public:
		
		/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados()  override
    {
        int elemento;
        int qtde;
        bool flag;
        
        do 
        {
            // solicitar quantidade de elementos
            cout << "Quantos elementos vão existir na lista? "; cin >> qtde;

            // verificar se o número fornecido é válido, isto é, acima de 0
            flag = isNumeroValido(qtde);

            if (!flag) 
            {
                cout << "Aviso: Entre com um número a partir de 1." << endl;
            }
        } 
        while (!flag);
        
		// solicitar cada elemento
        for (int i = 0; i < qtde; i++) 
        {
            cout << "Elemento " + to_string(i + 1) + ": "; cin >> elemento;
            //-colocar validacao

            lista.push_back(elemento);
        }
	}

    void mostraMediana()  override
    {   
        int divisao = (lista.size() / 2);
        float mediana;

        if ( isPar(divisao) )
        {
            mediana = (lista[divisao] + lista[divisao - 1]) / 2;
        } 
        else
        {
            mediana = lista[divisao];
        }

		cout << "A mediana da lista de idades é: " << mediana << endl;
	}
	
	void mostraMenor()  override
    {
        int menor;
        getValorMinimo(lista, menor);

		cout << "O menor das idades é: " << menor << endl;
	}

	void mostraMaior()  override
    {
        int maior;
        getValorMaximo(lista, maior);
        
		cout << "O maior das idades é: " << maior << endl;
	}
};