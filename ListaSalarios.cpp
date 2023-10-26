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
            cout << "Salário " + to_string(i + 1) + ": "; cin >> elemento;
            //-colocar validacao

            lista.push_back(elemento);
        }
	}

    void mostraMediana() override
    {   
        ordenarLista();
        int tamanho = lista.size();
        float mediana;

        if (isPar(tamanho))
        {
            int indiceMeio1 = (tamanho / 2) - 1;
            int indiceMeio2 = tamanho / 2;
            mediana = (lista[indiceMeio1] + lista[indiceMeio2]) / 2.0; // Média dos dois elementos do meio
        } 
        else
        {
            mediana = lista[tamanho / 2];
        }

        cout << "A mediana da lista de idades é: " << mediana << endl;
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
        int tamanho = lista.size();

        for(int i = 1; i < tamanho ;i++)
        {
            for(int j = 0; j < tamanho-1; j++)
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
        int tamanho = lista.size();
        cout << "Lista em ordem crescente: " << endl;

        for(int i = 0; i < tamanho; i++){
            cout << lista[i] << endl;
        }
    }

	virtual void listarNPrimeiros()  override {
        int tamanho = lista.size();
        int n = 0;

		do {
            cout << "Deseja ver os dados até qual índice? (entre 0 - " << tamanho << "):";
            cin >> n;
        } while (n < 0 || n > tamanho);

        cout << "Lista dos " << n << " primeiros: " << endl;
        for(int i = 0; i < n; i++){
            cout << lista[i] << endl;
        }
    }
};