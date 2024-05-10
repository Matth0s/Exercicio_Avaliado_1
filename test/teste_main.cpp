
/******************************************************************************/
/*____________________________________________________________________________*/
/*____ Autor: Matheus Moreira do Nascimento - 119042060 ______________________*/
/*____ Tarefa Avaliada 1 _____________________________________________________*/
/*____________________________________________________________________________*/
/*_______________________ Programa de Teste Principal ________________________*/
/*____________________________________________________________________________*/
/******************************************************************************/

#include "include.h"

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

		int array[24] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
							17, 18, 19, 20, 21, 22, 23, 24};
		Time	time1("Flamengo", array, array);
		time1.mostrarGols();

		cout << endl;
	}

	{
		srand(2);

		int		efetuados[24];
		int		sofridos[24];

		arrayGolsAleatorios(efetuados);
		arrayGolsAleatorios(sofridos);

		Time	time1("Flamengo", efetuados, sofridos);

		for (unsigned i = 0; i < 20; i++) {

			cout << (time1.getGolsEfetuadosCampeonatoAno(Time::ANOATUAL - (i % 8), CARIOCA)
					== efetuados[(i % 8) * 3 + CARIOCA] ? "✅" : "❌");
			cout << (time1.getGolsEfetuadosCampeonatoAno(Time::ANOATUAL - (i % 8), COPADOBRASIL)
					== efetuados[(i % 8) * 3 + COPADOBRASIL] ? "✅" : "❌");
			cout << (time1.getGolsEfetuadosCampeonatoAno(Time::ANOATUAL - (i % 8), BRASILEIRAO)
					== efetuados[(i % 8) * 3 + BRASILEIRAO] ? "✅" : "❌");

			cout << (time1.getGolsSofridosCampeonatoAno(Time::ANOATUAL - (i % 8), CARIOCA)
					== sofridos[(i % 8) * 3 + CARIOCA] ? "✅" : "❌");
			cout << (time1.getGolsSofridosCampeonatoAno(Time::ANOATUAL - (i % 8), COPADOBRASIL)
					== sofridos[(i % 8) * 3 + COPADOBRASIL] ? "✅" : "❌");
			cout << (time1.getGolsSofridosCampeonatoAno(Time::ANOATUAL - (i % 8), BRASILEIRAO)
					== sofridos[(i % 8) * 3 + BRASILEIRAO] ? "✅" : "❌");
		}
		cout << endl;
	}

	{
		srand(3);

		Time	time1 = gerarTime("Flamengo");
		Liga	liga1;

		cout << "___________________________________________________________________" << endl;
		time1.mostrarGols();
		cout << "___________________________________________________________________" << endl;
		liga1.mostrarTimes();
		cout << "___________________________________________________________________" << endl;
		liga1.adicionarTime(time1);
		liga1.mostrarTimes();
		cout << "___________________________________________________________________" << endl;
		liga1.removerTimePorNome("Flamengo");
		liga1.mostrarTimes();
		cout << "___________________________________________________________________" << endl;
	}

	{
		Liga	liga;

		cout << endl << endl;
		liga.adicionarTime(gerarTime("Flamengo"));
		liga.adicionarTime(gerarTime("Fluminense"));
		liga.adicionarTime(gerarTime("Botafogo"));
		liga.adicionarTime(gerarTime("Vasco"));
		liga.adicionarTime(gerarTime("Madureira"));
		liga.mostrarTimes();
		cout << endl << endl;
	}

	{
		Liga	liga;

		liga = gerarLiga();

		cout << endl << endl;
		liga.mostrarTimes();
		cout << endl << endl;
	}

	{

	}

	return (0);
}
