#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cctype>

#include "funcoes_uteis.h"

using namespace std;


class ListaNomes : Lista {
	vector<string> lista;
	
	public:
	
	/*
	O método abaixo pergunta ao usu�rios quantos
	elementos vão existir na lista e depois
	solicita a digitação de cada um deles
	*/	
	void entradaDeDados()  override
    {
        string elemento;
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
        string mediana = "";

        if ( isPar(divisao) )
        {
            string primeiro = lista[divisao - 1];
            string segundo = lista[divisao ];
             
            for ( unsigned int i = 0; i < primeiro.length() && mediana == ""; i++ ) 
            {
                if ( primeiro[i] > segundo[i] ) {
                    mediana = primeiro;
                } 
                else if ( primeiro[i] < segundo[i] ) {
                    mediana = segundo;
                }
            }
        } 
        else
        {
            mediana = lista[divisao];
        }

		cout << "A mediana da lista de nomes é: " << mediana << endl;
	}
	
	void mostraMenor()  override
    {
        string menor = lista[0];
        
        for (int i = 0; i < lista.size() ; i++) {
            if(lista[i]<menor){
                menor = lista[i];
            }
        }
        

		cout << "O primeiro nome alfabeticamente é: " << menor << endl;
	}

	void mostraMaior()  override
    {
        string maior = lista[0];
        
        for (int i = 0; i < lista.size() ; i++) {
            if(lista[i]>maior){
                maior = lista[i];
            }
        }
		cout << "O último nome alfabeticamente é: " << maior << endl;
	}
};
