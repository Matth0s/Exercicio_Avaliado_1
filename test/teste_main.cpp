/******************************************************************************/
/*                                                                            */
/*     Autor: Matheus Moreira do Nascimento - 119042060                       */
/*     Tarefa Avaliada 1                                                      */
/*                                                                            */
/*                   ____ Programa Principal de Testes____                    */
/*                                                                            */
/******************************************************************************/

#include "Utils.h"

using namespace std;

int	main(void) {

	{
		cout << "____________________ Construtor Padrão ____________________"
			 << endl
			 << endl;

		Time	time1;
		time1.mostrarGols();

		cout << "____________________________//_____________________________"
			 << endl
			 << endl;
	}

	{
		cout << "____________________ Construtor Array _____________________"
			 << endl
			 << endl;

		int array[Utils::limite] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

		Time	time1("Flamengo", array, array);

		time1.mostrarGols();

		cout << "____________________________//_____________________________"
			 << endl
			 << endl;
	}

	{
		cout << "____________________________//_____________________________"
			 << endl;

		srand(2);

		int		efetuados[Utils::limite];
		int		sofridos[Utils::limite];

		Utils::arrayGolsAleatorios(efetuados);
		Utils::arrayGolsAleatorios(sofridos);

		Time	time1("Flamengo", efetuados, sofridos);

		for (unsigned i = 0; i < 20; i++) {

			cout << (time1.getGolsEfetuadosCampeonatoAno(
				CARIOCA, Time::MAXANO - (i % 3)) == efetuados[(i % 3) * 4 + CARIOCA] ? "✅" : "❌");
			cout << (time1.getGolsEfetuadosCampeonatoAno(
				COPADOBRASIL, Time::MAXANO - (i % 3)) == efetuados[(i % 3) * 4 + COPADOBRASIL] ? "✅" : "❌");
			cout << (time1.getGolsEfetuadosCampeonatoAno(
				BRASILEIRAO, Time::MAXANO - (i % 3)) == efetuados[(i % 3) * 4 + BRASILEIRAO] ? "✅" : "❌");

			cout << (time1.getGolsSofridosCampeonatoAno(
				CARIOCA, Time::MAXANO - (i % 3)) == sofridos[(i % 3) * 4 + CARIOCA] ? "✅" : "❌");
			cout << (time1.getGolsSofridosCampeonatoAno(
				COPADOBRASIL, Time::MAXANO - (i % 3)) == sofridos[(i % 3) * 4 + COPADOBRASIL] ? "✅" : "❌");
			cout << (time1.getGolsSofridosCampeonatoAno(
				BRASILEIRAO, Time::MAXANO - (i % 3)) == sofridos[(i % 3) * 4 + BRASILEIRAO] ? "✅" : "❌");
		}

		cout << endl;
		cout << "____________________________//_____________________________"
			 << endl
			<< endl;
	}

	{
		cout << "____________________________//_____________________________"
			 << endl;

		srand(3);

		Time	time1 = Utils::gerarTime("Flamengo");
		Liga	liga1;

		cout << "//¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\\\\"
			 << endl;
		time1.mostrarGols();
		cout << "\\\\________________________________________________________//"
			 << endl;

		cout << "//¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\\\\"
			 << endl;
		liga1.mostrarTimes();
		cout << "\\\\________________________________________________________//"
			 << endl;

		cout << "//¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\\\\"
			 << endl;
		liga1.adicionarTime(time1);
		liga1.mostrarTimes();
		cout << "\\\\________________________________________________________//"
			 << endl;

		cout << "//¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\\\\"
			 << endl;
		liga1.removerTimePorNome("Flamengo");
		liga1.mostrarTimes();
		cout << "\\\\________________________________________________________//"
			 << endl
			 << endl;
	}

	{
		cout << "____________________________//_____________________________"
			 << endl;

		Liga	liga;

		liga = Utils::gerarLiga();

		liga.mostrarTimes();

		cout << "____________________________//_____________________________"
			 << endl
			 << endl;
	}

	{
		cout << "____________________________//_____________________________"
			 << endl;

		srand(5);

		Time	time1 = Utils::gerarTime("Flamengo");

		time1.mostrarGols();

		cout << endl;

		cout << "Desempenho  Efetuados  Carioca        = "
			 << time1.getDesempenhoGolsEfetuadosCampeonato(CARIOCA) << endl;
		cout << "Desempenho  Sofridos   Carioca        = "
			 << time1.getDesempenhoGolsSofridosCampeonato(CARIOCA) << endl;
		cout << "Desempenho  Efetuados  Copa do Brasil = "
			 << time1.getDesempenhoGolsEfetuadosCampeonato(COPADOBRASIL) << endl;
		cout << "Desempenho  Sofridos   Copa do Brasil = "
			 << time1.getDesempenhoGolsSofridosCampeonato(COPADOBRASIL) << endl;
		cout << "Desempenho  Efetuados  Brasileirão    = "
			 << time1.getDesempenhoGolsEfetuadosCampeonato(BRASILEIRAO) << endl;
		cout << "Desempenho  Sofridos   Brasileirão    = "
			 << time1.getDesempenhoGolsSofridosCampeonato(BRASILEIRAO) << endl;

		cout << endl;

		cout << "Desempenho  Efetuados  Anual    = "
			 << time1.getDesempenhoGolsEfetuados() << endl;
		cout << "Desempenho  Sofridos   Anual    = "
			 << time1.getDesempenhoGolsSofridos() << endl;

		cout << "____________________________//_____________________________"
			 << endl
			 << endl;

	}

	{
		cout << "____________________________//_____________________________"
			 << endl;

		srand(8);

		Liga	liga;

		liga.adicionarTime(Utils::gerarTime("Flamengo"));
		liga.adicionarTime(Utils::gerarTime("Fluminense"));
		liga.adicionarTime(Utils::gerarTime("Botafogo"));
		liga.mostrarTimes();
		liga.desempenhoCampeonato(CARIOCA);
		liga.desempenhoCampeonato(COPADOBRASIL);
		liga.desempenhoCampeonato(BRASILEIRAO);
		liga.desempenhoAnual();

		cout << "____________________________//_____________________________"
			 << endl
			 << endl;
	}

	{
		cout << "____________________________//_____________________________"
			 << endl;
		Liga	liga;

		liga.desempenhoCampeonato(CARIOCA);
		liga.desempenhoAnual();

		cout << "____________________________//_____________________________"
			 << endl
			 << endl;
	}

	{
		cout << "____________________________//_____________________________"
			 << endl;

		srand(22);
		Liga	liga;

		liga.adicionarTime(Utils::gerarTime("Flamengo"));
		liga.adicionarTime(Utils::gerarTime("Fluminense"));
		liga.adicionarTime(Utils::gerarTime("Botafogo"));

		liga.desempenhoCampeonato(CARIOCA);
		liga.melhorEvolucaoCampeonato(CARIOCA);
		cout << endl;
		liga.desempenhoCampeonato(COPADOBRASIL);
		liga.melhorEvolucaoCampeonato(COPADOBRASIL);
		cout << endl;
		liga.desempenhoCampeonato(BRASILEIRAO);
		liga.melhorEvolucaoCampeonato(BRASILEIRAO);
		cout << endl;
		liga.desempenhoAnual();
		liga.melhorEvolucaoAnual();

		cout << "____________________________//_____________________________"
			 << endl
			 << endl;
	}

	{
		cout << "____________________________//_____________________________"
			 << endl;

		srand(15);
		Liga	liga;

		liga.adicionarTime(Utils::gerarTime("Flamengo"));
		liga.adicionarTime(Utils::gerarTime("Fluminense"));
		liga.adicionarTime(Utils::gerarTime("Botafogo"));

		liga.mostrarTimes();
		cout << endl;
		liga.maiorSaldoGolsCampeonato(CARIOCA);
		liga.maiorSaldoGolsCampeonato(COPADOBRASIL);
		liga.maiorSaldoGolsCampeonato(BRASILEIRAO);

		cout << "____________________________//_____________________________"
			 << endl
			 << endl;
	}

	{
		cout << "____________________________//_____________________________"
			 << endl;

		srand(30);

		Liga	liga;

		liga.adicionarTime(Utils::gerarTime("Flamengo"));
		liga.adicionarTime(Utils::gerarTime("Fluminense"));
		liga.adicionarTime(Utils::gerarTime("Botafogo"));

		liga.mostrarTimes();
		cout << endl;
		liga.maiorSaldoGolsAnual();

		cout << "____________________________//_____________________________"
			 << endl
			 << endl;
	}

	{
		srand(0);

		Liga	liga;

		liga.adicionarTime(Utils::gerarTime("Flamengo"));
		liga.adicionarTime(Utils::gerarTime("Fluminense"));
		liga.adicionarTime(Utils::gerarTime("Botafogo"));

		liga.mostrarTimes();
		cout << endl;
		cout << endl;
		cout << endl;
		liga.desempenhoCampeonato(CARIOCA);
		cout << endl;
		liga.desempenhoAnual();
		cout << endl;
		liga.maiorSaldoGolsCampeonato(CARIOCA);
		cout << endl;
		liga.maiorSaldoGolsAnual();
		cout << endl;
		liga.melhorEvolucaoCampeonato(CARIOCA);
		cout << endl;
		liga.melhorEvolucaoAnual();
		cout << endl;

	}

	{
		cout << "____________________________//_____________________________"
			 << endl
			 << endl;

		Liga	liga;

		liga.desempenhoCampeonato(CARIOCA);
		liga.desempenhoAnual();

		liga.maiorSaldoGolsCampeonato(CARIOCA);
		liga.maiorSaldoGolsAnual();

		liga.melhorEvolucaoCampeonato(CARIOCA);
		liga.melhorEvolucaoAnual();

		liga.mostrarTimes();

		cout << "____________________________//_____________________________"
			 << endl
			 << endl;
	}

	return (0);
}
