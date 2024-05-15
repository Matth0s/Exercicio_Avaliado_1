/******************************************************************************/
/*                                                                            */
/*     Autor: Matheus Moreira do Nascimento - 119042060                       */
/*     Tarefa Avaliada 1                                                      */
/*                                                                            */
/*                        ____ Programa Principal ____                        */
/*                                                                            */
/******************************************************************************/

#include "Utils.h"

using namespace std;

void exibirMenuPrincipal(void) {
	cout << endl;
	cout << "|¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨|\n";
	cout << "|   Digite o numero do comando necessario:   |\n";
	cout << "|                                            |\n";
	cout << "|    1 - Times do Campeonato                 |\n";
	cout << "|    2 - Evolucao dos Times Por Campeonato   |\n";
	cout << "|    3 - Evolucao dos Times Geral            |\n";
	cout << "|    4 - Maior Saldo de Gols Por Campeonato  |\n";
	cout << "|    5 - Maior Saldo de Gols Geral           |\n";
	cout << "|    6 - Maior Evolucao Por Campeonato       |\n";
	cout << "|    7 - Maior Evolucao Geral                |\n";
	cout << "|    8 - Trocar Historico dos Times          |\n";
	cout << "|                                            |\n";
	cout << "|    9 - Encerrar Programa                   |\n";
	cout << "|____________________________________________|"
		 << endl
		 << endl;
}

void exibirMenuCampeonatos(void) {
	cout << endl;
	cout << " |¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨|\n";
	cout << " |      Digite o numero do campeonato:      |\n";
	cout << " |                                          |\n";
	cout << " |         1 - Campeonato Carioca           |\n";
	cout << " |         2 - Copa do Brasil               |\n";
	cout << " |         3 - Brasileirao                  |\n";
	cout << " |__________________________________________|"
		 << endl
		 << endl;
}

Campeonato menuEscolhaCampeonato(void) {

	string comando;

	while (true) {

		exibirMenuCampeonatos();
		cout << "# Insira o comando: ";
		getline(cin, comando);

		if (!comando.compare("1")) {
			return (CARIOCA);

		} else if (!comando.compare("2")) {
			return (COPADOBRASIL);

		} else if (!comando.compare("3")) {
			break;

		} else {
			cout << "\n/¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\\\n";
			cout << "|     Comando não encontrado     |\n";
			cout << "|         Tente novamente        |\n";
			cout << "\\________________________________/\n"
				 << endl;
		}
	}

	return (BRASILEIRAO);
}

int main(void) {

	Liga liga;
	string comando;

	srand(time(0));
	liga = Utils::gerarLiga();

	cout << endl;
	cout << " * ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨ *\n";
	cout << " |       Bem Vindo Programa Principal       |\n";
	cout << " |                                          |\n";
	cout << " |        utilize os codigos do Menu        |\n";
	cout << " |       para interacao com o sistema       |\n";
	cout << " * ________________________________________ *"
		 << endl
		 << endl;

	while (true) {

		exibirMenuPrincipal();
		cout << "# Insira o comando: ";
		getline(cin, comando);

		if (!comando.compare("1")) {
			liga.mostrarTimes();

		} else if (!comando.compare("2")) {
			liga.desempenhoCampeonato(menuEscolhaCampeonato());

		} else if (!comando.compare("3")) {
			liga.desempenhoAnual();

		} else if (!comando.compare("4")) {
			liga.maiorSaldoGolsCampeonato(menuEscolhaCampeonato());

		} else if (!comando.compare("5")) {
			liga.maiorSaldoGolsAnual();

		} else if (!comando.compare("6")) {
			liga.melhorEvolucaoCampeonato(menuEscolhaCampeonato());

		} else if (!comando.compare("7")) {
			liga.melhorEvolucaoAnual();

		} else if (!comando.compare("8")) {
			liga = Utils::gerarLiga();
			cout << "\n/¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\\\n";
			cout << "|  Historico dos Times trocados  |\n";
			cout << "\\________________________________/\n"
				 << endl;

		} else if (!comando.compare("9")) {
			cout << "\n/¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\\\n";
			cout << "|       Programa Encerrado       |\n";
			cout << "\\________________________________/\n"
				 << endl;
			break;

		} else {
			cout << "\n/¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\\\n";
			cout << "|     Comando não encontrado     |\n";
			cout << "|         Tente novamente        |\n";
			cout << "\\________________________________/\n"
				 << endl;
		}

		cout << "Aperte Enter para continuar...";
		getline(cin, comando);
	}

	return (0);
}
