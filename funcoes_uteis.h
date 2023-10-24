#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cctype>

using namespace std;


template<typename T> void getValorMaximo(vector<T> elementos, T &maximo);           // Template para pegar o valor máximo em um vector númerico
template<typename T> void getValorMinimo(vector<T> elementos, T &minimo);           // Template para pegar o valor mínimo em um vector númerico

bool isTextoValido(std::string _nome);
bool isPar(int _numero);
bool isImpar(int _numero);
bool isNumeroValido(int numero);

void systemClear();
void systemPause();
void systemPauseAndClear();