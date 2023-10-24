#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cctype>

#include "funcoes_uteis.h"

using namespace std;


template<typename T> void getValorMaximo(vector<T> elementos, T &maximo) 
{
    T max = INT_MIN;

    for (unsigned int i = 0; i < elementos.size(); i++)
    {
        if (elementos[i] > max) { max = elementos[i]; }
    }

    maximo = max;
}

template<typename T> void getValorMinimo(vector<T> elementos, T &minimo) 
{
    T min = INT_MAX;

    for (unsigned int i = 0; i < elementos.size(); i++)
    {
        if (elementos[i] < min) { min = elementos[i]; }
    }

    minimo = min;
}

bool isTextoValido(std::string _nome)
{
    if ( _nome.empty() ) {
        return false;
    }

    return true;
}

bool isPar(int _numero)
{
    return _numero % 2 == 0;
}

bool isImpar(int _numero)
{
    return _numero % 3 == 0;
}

bool isNumeroValido(int numero) 
{
    return isPar(numero) || isImpar(numero) || numero == 1;
}

void systemClear() {
    #if __linux__
        system("clear");
    #else
        system("cls");
    #endif
}

void systemPause() {
    cout << "\nPressione ENTER para continuar...\n";
    #if __linux__
        cin.ignore();
    #else
        cin.sync();
    #endif
    cin.get();
}

void systemPauseAndClear() {
    systemPause();
    systemClear();
}