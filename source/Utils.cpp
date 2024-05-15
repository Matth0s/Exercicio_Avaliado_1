#include "Utils.h"

void Utils::arrayGolsAleatorios(int array[limite]) {

	for (unsigned i = 0; i < limite; i++) {
		array[i] = rand() % 70 + 20;
	}
}

Time Utils::gerarTime(string nome) {

	int golsEfetuados[limite];
	int golsSofridos[limite];

	arrayGolsAleatorios(golsEfetuados);
	arrayGolsAleatorios(golsSofridos);

	return (Time(nome, golsEfetuados, golsSofridos));
}

Liga Utils::gerarLiga(void) {

	Liga liga;

	liga.adicionarTime(gerarTime("Flamengo"));
	liga.adicionarTime(gerarTime("Fluminense"));
	liga.adicionarTime(gerarTime("Botafogo"));
	liga.adicionarTime(gerarTime("Vasco"));
	liga.adicionarTime(gerarTime("Madureira"));
	liga.adicionarTime(gerarTime("Bangu"));
	liga.adicionarTime(gerarTime("Boavista"));
	liga.adicionarTime(gerarTime("Volta Redonda"));
	liga.adicionarTime(gerarTime("Nova Iguacu"));
	liga.adicionarTime(gerarTime("Audax Rio"));

	return (liga);
}
