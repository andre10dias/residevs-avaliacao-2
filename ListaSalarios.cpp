#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cctype>

#include "include/Lista.h"
#include "include/funcoes_uteis.h"

using namespace std;


class ListaSalarios : Lista {
	vector<float> lista;
	
	public:
	
	/*
	O método abaixo pergunta ao usuários quantos
	elementos vão existir na lista e depois
	solicita a digitação de cada um deles
	*/	
	void entradaDeDados() override
    {
        float elemento;
        int qtde;
        bool flag;
        
        do 
        {
            // solicitar quantidade de elementos
            cout << "Quantos elementos vão existir na lista? ";
            cin >> qtde;
            cout << endl;
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
			
	void mostraMediana() override
    {   
        ordenarLista();
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

		cout << "A mediana da lista de salários é: " << mediana << endl;
	}
	
	void mostraMenor() override
    {
        float menor;
        getValorMinimo(lista, menor);

		cout << "O menor dos salarios é: " << menor << endl;
	}

	void mostraMaior() override
    {
        float maior;
        getValorMaximo(lista, maior);
        
		cout << "O maior dos salarios é: " << maior << endl;
	}

     //Ordenar lista de nome
    void ordenarLista()
        {
            for(int i=1; i<lista.size() ;i++)
            {
                for( int j=0; j<lista.size()-1; j++)
                {
                    if(lista[j] > lista[j+1])
                    {
                        int temp;
                        temp = lista[j];
                        lista[j] = lista[j+1];
                        lista[j+1] = temp;

                    }

                }
            }
    }
    void listarEmOrdem() override {
        ordenarLista();
        cout << "Lista em ordem crescente: " << endl;
        for(int i = 0; i <lista.size() ; i++){
            cout << lista[i] << endl;
        }
    }
	virtual void listarNPrimeiros()  override {
        int n = 0;
		do {
		cout << "Deseja ver os dados até qual índice? (entre 0 - " << lista.size() << "):";
		cin >> n;
        } while (n < 0 || n>lista.size());
        cout << "Lista dos " << n << " primeiros: " << endl;
        for(int i = 0; i < n; i++){
            cout << lista[i] << endl;
        }
    }
};