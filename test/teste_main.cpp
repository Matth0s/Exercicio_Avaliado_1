
/******************************************************************************/
/*____________________________________________________________________________*/
/*____ Autor: Matheus Moreira do Nascimento - 119042060 ______________________*/
/*____ Tarefa Avaliada 1 _____________________________________________________*/
/*____________________________________________________________________________*/
/*_______________________ Programa de Teste Principal ________________________*/
/*____________________________________________________________________________*/
/******************************************************************************/

#include "Utils.h"

using namespace std;

int	main(void) {

	{
		cout << "----- Construtor Padrão -----" << endl << endl;

		Time	time1;
		time1.mostrarGols();

		cout << endl;
	}

	{
		cout << "----- Construtor Array -----" << endl << endl;

		int array[Utils::limite] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

		Time	time1("Flamengo", array, array);

		time1.mostrarGols();

		cout << endl;
	}

	{
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
	}

	{
		srand(3);

		Time	time1 = Utils::gerarTime("Flamengo");
		Liga	liga1;

		cout << "_______________________________________________________________" << endl;
		time1.mostrarGols();
		cout << "_______________________________________________________________" << endl;
		liga1.mostrarTimes();
		cout << "_______________________________________________________________" << endl;
		liga1.adicionarTime(time1);
		liga1.mostrarTimes();
		cout << "_______________________________________________________________" << endl;
		liga1.removerTimePorNome("Flamengo");
		liga1.mostrarTimes();
		cout << "_______________________________________________________________" << endl;
	}

	{
		Liga	liga;

		liga = Utils::gerarLiga();

		cout << endl << endl;
		liga.mostrarTimes();
		cout << endl << endl;
	}

	{
		srand(10);

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

		cout << endl;
	}

	return (0);
}
