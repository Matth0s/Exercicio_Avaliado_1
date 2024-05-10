#include "include.h"

void arrayGolsAleatorios(int array[]) {

	for (unsigned i = 0; i < 24; i++) {
		array[i] = rand() % 70 + 20;
	}
}

Time gerarTime(string nome) {

	int golsEfetuados[24];
	int golsSofridos[24];

	arrayGolsAleatorios(golsEfetuados);
	arrayGolsAleatorios(golsSofridos);

	return (Time(nome, golsEfetuados, golsSofridos));
}

Liga gerarLiga(void) {

	Liga	liga;

	liga.adicionarTime(gerarTime("Flamengo"));
	liga.adicionarTime(gerarTime("Fluminense"));
	liga.adicionarTime(gerarTime("Botafogo"));
	liga.adicionarTime(gerarTime("Vasco"));
	liga.adicionarTime(gerarTime("Madureira"));
	liga.adicionarTime(gerarTime("Bangu"));
	liga.adicionarTime(gerarTime("Boavista"));
	liga.adicionarTime(gerarTime("Volta Redonda"));
	liga.adicionarTime(gerarTime("Nova Iguaçu"));
	liga.adicionarTime(gerarTime("Audax Rio"));

	return (liga);
}
