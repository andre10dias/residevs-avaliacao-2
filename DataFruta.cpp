#include <iostream>
#include <string>
#include <vector>

using namespace std;

void systemPause();
void systemClear();
void systemPauseAndClear();

class Data {
	int dia, mes, ano;

	private:
		static bool ehAnoBisexto(int ano) {
			if (ano % 100 > 0 && ano % 4 == 0)
			{
				return true;
			}
			
			return false;
		}

	public:
	
	/*
	O m�todo abaixo retornar� -1 se d1 � anterior a d2
	Retornar� 0 se d1 = d2
	Retornar� +1 se d1 � posterior a d2
	*/	
	static int compara(Data d1, Data d2) { 
		if (d1.dia == d2.dia && d1.mes == d2.mes && d1.ano == d2.ano)
		{
			return 0;
		}
		
		if (d1.ano < d2.ano)
		{
			return -1;
		}
		else if (d1.ano == d2.ano)
		{
			if (d1.mes < d2.mes)
			{
				return -1;
			}
			else if (d1.mes == d2.mes)
			{
				if (d1.dia < d2.dia)
				{
					return -1;
				}
			}
		}

		return 1;
	}

	static vector<Data> ordenaDatasCrescente(vector<Data> listaDatas) {
		int tamanho = listaDatas.size();
		Data aux;

		for (int i = 0; i < tamanho; i++)
		{
			for (int j = i+1; j < tamanho; j++)
			{
				if (compara(listaDatas[i], listaDatas[j]) == 1)
				{
					aux = listaDatas[i];
					listaDatas[i] = listaDatas[j];
					listaDatas[j] = aux;
				}
			}
		}
		
		return listaDatas;
	}

	static bool ehFormatoValido(string data) {
		string dia, mes, ano, barra1, barra2;
		string somenteDigitos;

		if (data.size() != 10)
		{
			return false;
		}

		dia = data.substr(0, 2);
		barra1 = data.substr(2, 1);
		mes = data.substr(3, 2);
		barra2 = data.substr(5, 1);
		ano = data.substr(6, 4);

		somenteDigitos = dia + mes + ano;
		int tamanho = somenteDigitos.size();

		for (int i = 0; i < tamanho; i++)
		{
			if (!isdigit(somenteDigitos[i]))
			{
				return false;
			}
		}
		
		if (barra1.compare("/") != 0 || barra2.compare("/") != 0)
		{
			return false;
		}

		return true;
	}

	static bool ehDataValida(Data data) {
		bool ehValido = true;

		if (data.dia < 1 || data.dia > 31 || data.mes < 1 || data.mes > 12)
		{
			return false;
		}
		else 
		{
			if (data.mes < 8)
			{
				if (data.mes % 2 == 0 && data.dia > 30) //Meses pares de JAN a JUL só vão até dia 30
				{
					ehValido = false;
				}

				if (data.mes == 2)
				{
					if ((!ehAnoBisexto(data.ano) && data.dia > 28) || data.dia > 29) //FEV vai somente até 28 nos anos não bisextos 
					{
						ehValido = false;
					}
				}
			}
			else if (data.mes % 2 == 1 && data.dia > 30) //Meses ímpares de AGO a DEZ só vão até dia 30
			{
				ehValido = false;
			}
		}
		
		return ehValido;
	}

	Data()
	{
	}
	
	Data(int _dia, int _mes, int _ano) {
		dia = _dia;
		mes = _mes;
		ano = _ano;
	}

	string toString() {
		string ret = "";
		string _dia = dia < 10 ? "0"+to_string(dia) : to_string(dia);
		string _mes = mes < 10 ? "0"+to_string(mes) : to_string(mes);

		ret.append(_dia);
		ret.append("/");
		ret.append(_mes);
		ret.append("/");
		ret.append(to_string(ano));
		return ret;
	}
};

class Lista {
	public:
		virtual void entradaDeDados() = 0;
		virtual void imprimir() = 0;
		virtual void mostraMediana() = 0;
		virtual void mostraMenor() = 0;
		virtual void mostraMaior() = 0;
};

class ListaNomes : public Lista {
	vector<string> lista;
	
	public:
	
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() {
		lista.push_back("Teste");
	}
		
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de strings" << endl;
	}
	
	void mostraMenor() {
		cout << "Aqui vai mostrar o primeiro nome alfabeticamente" << endl;
	}
	void mostraMaior() {
		cout << "aqui vai mostrar o ultimo nome alfabeticamente" << endl;
	}
};

class ListaDatas : public Lista  {
	vector<Data> lista;
	
	public:
		
		/*
		O m�todo abaixo pergunta ao usu�rios quantos
		elementos v�o existir na lista e depois
		solicita a digita��o de cada um deles
		*/	
		void entradaDeDados() override {
			int qtdItens = 0; 
			int contador = 0;
			bool dataValida = true;
			string entrada, dia, mes, ano;

			systemClear();
			cout << "Informe a quantidade de itens na lista: ";
			cin >> qtdItens;

			if (qtdItens > 0)
			{
				do
				{
					systemClear();
					cout << "Inserindo Datas na lista:" << endl;

					cout << "\nInforme uma data no formato dd/mm/aaaa: ";

					cout << "\nData " << contador+1 << ": ";
					cin >> entrada;

					if (!Data::ehFormatoValido(entrada))
					{
						dataValida = false;
						cout << "\nFormato de Data inválido.\n";
						systemPause();
					}
					else
					{
						dia = entrada.substr(0, 2);
						mes = entrada.substr(3, 2);
						ano = entrada.substr(6, 4);

						Data data(stoi(dia), stoi(mes), stoi(ano));

						if (Data::ehDataValida(data))
						{
							lista.push_back(data);
							contador++;
							dataValida = true;
						}
						else
						{
							dataValida = false;
							cout << "\nData inválida.\n";
							systemPause();
						}
					}
				} while (contador < qtdItens || !dataValida);

				lista = Data::ordenaDatasCrescente(lista);
			}
		}

		void imprimir() override {
			systemClear();
			cout << "Datas inseridas em ordem cronologica:" << endl;

			for (Data data : lista)
			{
				cout << data.toString() << "\t";
			}

			cout << endl << endl;
		}
		
		void mostraMediana() override {
			lista = Data::ordenaDatasCrescente(lista);
			Data mediana;
			int tamanho = lista.size();
			
			if (tamanho % 2 == 0)
			{
				int index = ((tamanho / 2 - 1) + (tamanho / 2)) / 2;
				mediana = lista[index];
			}
			else
			{
				mediana = lista[tamanho / 2];
			}
			
			cout << "Mediana: " << mediana.toString() << endl;
		}
		
		void mostraMenor() override {
			cout << "Menor data: " << lista[0].toString() << endl;
		}

		void mostraMaior() override {
			int index = lista.size();
			cout << "Maior data: " << lista[index-1].toString() << endl;
		}
};

class ListaSalarios : public Lista  {
	vector<float> lista;
	
	public:
	
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() {
		
	}
			
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de salarios" << endl;
	}
	
	void mostraMenor() {
		cout << "Aqui vai mostrar o menor dos salarios" << endl;
	}
	void mostraMaior() {
		cout << "aqui vai mostrar o maior dos salarios" << endl;
	}
};


class ListaIdades : public Lista  {
	vector<int> lista;
	
	public:
		
		/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() {
		
	}
	
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de idades" << endl;
	}
	
	void mostraMenor() {
		cout << "Aqui vai mostrar a menor das idades" << endl;
	}
	void mostraMaior() {
		cout << "aqui vai mostrar a maior das idades" << endl;
	}
};
 
int main () {
	vector<Lista*> listaDeListas;
	
	// ListaNomes listaNomes;
	// listaNomes.entradaDeDados();
	// listaDeListas.push_back(&listaNomes);
	
	ListaDatas listaDatas;
	listaDatas.entradaDeDados();
	listaDeListas.push_back(&listaDatas);
	
	// ListaSalarios listaSalarios;
	// listaSalarios.entradaDeDados();
	// listaDeListas.push_back(&listaSalarios);
	
	// ListaIdades listaIdades;
	// listaIdades.entradaDeDados();
	// listaDeListas.push_back(&listaIdades);
	
	for (Lista* l : listaDeListas) {
		l -> imprimir();
		l -> mostraMediana();
		l -> mostraMenor();
		l -> mostraMaior();
	}
	
	cout << endl;
	return 0;
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
