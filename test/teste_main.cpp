
/******************************************************************************/
/*____________________________________________________________________________*/
/*____ Autor: Matheus Moreira do Nascimento - 119042060 ______________________*/
/*____ Tarefa Avaliada 1 _____________________________________________________*/
/*____________________________________________________________________________*/
/*_______________________ Programa de Teste Principal ________________________*/
/*____________________________________________________________________________*/
/******************************************************************************/

#include "Time.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

void	arrayAleatorio(int array[]) {
	for (unsigned i = 0; i < 24; i++) {
		array[i] = rand() % 40 + 30;
	}
}

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
		Time	time1(array, array);
		time1.mostrarGols();

		cout << endl;
	}

	{
		srand(2);

		int		efetuados[24];
		int		sofridos[24];

		arrayAleatorio(efetuados);
		arrayAleatorio(sofridos);

		Time	time1(efetuados, sofridos);

		for (unsigned i = 0; i < 24; i++) {
			cout << (time1.getGolsEfetuadosCampeonatoAno(i % 8, CARIOCA)
					== efetuados[(i % 8) * 3 + CARIOCA] ? "✅" : "❌");
			cout << (time1.getGolsEfetuadosCampeonatoAno(i % 8, COPADOBRASIL)
					== efetuados[(i % 8) * 3 + COPADOBRASIL] ? "✅" : "❌");
			cout << (time1.getGolsEfetuadosCampeonatoAno(i % 8, BRASILEIRAO)
					== efetuados[(i % 8) * 3 + BRASILEIRAO] ? "✅" : "❌");

			cout << (time1.getGolsSofridosCampeonatoAno(i % 8, CARIOCA)
					== sofridos[(i % 8) * 3 + CARIOCA] ? "✅" : "❌");
			cout << (time1.getGolsSofridosCampeonatoAno(i % 8, COPADOBRASIL)
					== sofridos[(i % 8) * 3 + COPADOBRASIL] ? "✅" : "❌");
			cout << (time1.getGolsSofridosCampeonatoAno(i % 8, BRASILEIRAO)
					== sofridos[(i % 8) * 3 + BRASILEIRAO] ? "✅" : "❌");
		}
		cout << endl;
	}

	return (0);

}
