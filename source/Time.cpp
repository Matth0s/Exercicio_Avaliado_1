#include "Time.h"

using namespace std;

Time::Time(void) : _nome("Desconhecido"), _golsEfetuados{}, _golsSofridos{} {}

Time::Time(string nome, const int golsEfetuados[], const int golsSofridos[]) {

	_nome = nome;

	for (unsigned i = 0; i < _campeonatos * _anos; i++) {
		_golsEfetuados[i / _anos][i % _anos] = golsEfetuados[i];
		_golsSofridos[i / _anos][i % _anos] = golsSofridos[i];
	}
}

void Time::_mostrarGolsCampeonato(string texto,
								  int gols[][_anos], Campeonato campeonato) {

	cout << texto;
	for (unsigned i = 0; i < _anos; i++) {
		cout << " |" << setw(5) << gols[campeonato][i];
	}
	cout << endl;
}

int Time::_golsCampeonatoAno(int gols[][_anos], Campeonato campeonato, int ano) {

	if (ano > MAXANO) {
		ano = MAXANO;
	} else if (ano < MINANO) {
		ano = MINANO;
	}

	return (gols[MAXANO - ano][campeonato]);
}

double Time::_mediaMovelCampeonato(int gols[][_anos], Campeonato campeonato,
																	int ano) {

	double total;

	total = 0;
	for (unsigned i = 0; i < _mediaN; i++) {
		total += gols[campeonato][ano + i];
	}
	total *= (1 / (double)_mediaN);

	return (total);
}

double Time::_mediaMovelAnual(int gols[][_anos], int ano) {

	double total = 0;

	for (unsigned i = 0; i < _mediaN; i++) {
		total += gols[CARIOCA][ano + i];
		total += gols[COPADOBRASIL][ano + i];
		total += gols[BRASILEIRAO][ano + i];
	}
	total *= (1 / (double)_mediaN);

	return (total);
}

string Time::getNome(void) {
	return (_nome);
}

int Time::getGolsEfetuadosCampeonatoAno(Campeonato campeonato, int ano) {
	return (_golsCampeonatoAno(_golsEfetuados, campeonato, ano));
}

int Time::getGolsSofridosCampeonatoAno(Campeonato campeonato, int ano) {
	return (_golsCampeonatoAno(_golsSofridos, campeonato, ano));
}

int Time::getSaldoGolsCampeonato(Campeonato campeonato) {

	int	total = 0;

	for (unsigned i = 0; i < _anos; i++) {
		total += (_golsEfetuados[campeonato][i] - _golsSofridos[campeonato][i]);
	}

	return (total);
}

int Time::getSaldoGols(void) {

	int	total = 0;

	for (unsigned i = 0; i < _anos; i++) {
		total += (_golsEfetuados[CARIOCA][i] - _golsSofridos[CARIOCA][i]);
		total += (_golsEfetuados[COPADOBRASIL][i] - _golsSofridos[COPADOBRASIL][i]);
		total += (_golsEfetuados[BRASILEIRAO][i] - _golsSofridos[BRASILEIRAO][i]);
	}

	return (total);
}

double Time::getDesempenhoGolsEfetuadosCampeonato(Campeonato campeonato) {

	double desempenho;

	// M_a / M_{a-1}
	desempenho = _mediaMovelCampeonato(_golsEfetuados, campeonato, 0)
					/ _mediaMovelCampeonato(_golsEfetuados, campeonato, 1);

	// 1,24562875 - 1   (pegar o decimal)
	// 0,24562875 * 100 (transformar em porcentagem)
	// 24,562875 * 100  (preparar para o round())
	// 2456 / 100       (voltar para porcentagem)
	// 24,56            (resultado final)
	desempenho = round((desempenho - 1) * 100 * 100) / 100;

	return (desempenho);
}

double Time::getDesempenhoGolsSofridosCampeonato(Campeonato campeonato) {

	double desempenho;

	// M_{a-1) / M_{a} (para avaliar valores maiores que 1 como melhora)
	desempenho = _mediaMovelCampeonato(_golsSofridos, campeonato, 1)
					/ _mediaMovelCampeonato(_golsSofridos, campeonato, 0);

	// 1,24562875 - 1   (pegar o decimal)
	// 0,24562875 * 100 (transformar em porcentagem)
	// 24,562875 * 100  (preparar para o round())
	// 2456 / 100       (voltar para porcentagem)
	// 24,56            (resultado final)
	desempenho = round((desempenho - 1) * 100 * 100) / 100;

	return (desempenho);
}

double Time::getDesempenhoGolsEfetuados(void) {

	double desempenho;

	// M_a / M_{a-1}
	desempenho = _mediaMovelAnual(_golsEfetuados, 0)
					/ _mediaMovelAnual(_golsEfetuados, 1);

	// 1,24562875 - 1   (pegar o decimal)
	// 0,24562875 * 100 (transformar em porcentagem)
	// 24,562875 * 100  (preparar para o round())
	// 2456 / 100       (voltar para porcentagem)
	// 24,56            (resultado final)
	desempenho = round((desempenho - 1) * 100 * 100) / 100;

	return (desempenho);
}

double Time::getDesempenhoGolsSofridos(void) {

	double desempenho;

	// M_{a-1) / M_{a} (para avaliar valores maiores que 1 como melhora)
	desempenho = _mediaMovelAnual(_golsSofridos, 1)
					/ _mediaMovelAnual(_golsSofridos, 0);

	// 1,24562875 - 1   (pegar o decimal)
	// 0,24562875 * 100 (transformar em porcentagem)
	// 24,562875 * 100  (preparar para o round())
	// 2456 / 100       (voltar para porcentagem)
	// 24,56            (resultado final)
	desempenho = round((desempenho - 1) * 100 * 100) / 100;

	return (desempenho);
}

void Time::mostrarGols(void) {

	cout << "/ ******************************************************* \\" << endl;
	cout << "|          "
		 << left << setw(18) << _nome
		 << right << "| 2023 | 2022 | 2021 | 2020 "
		 << endl;
	cout << "-----------------------------------------------------------" << endl;
	_mostrarGolsCampeonato("|                | Efetuados", _golsEfetuados, CARIOCA);
	_mostrarGolsCampeonato("| CARIOCA        | Sofridos ", _golsSofridos, CARIOCA);
	cout << "-----------------------------------------------------------" << endl;
	_mostrarGolsCampeonato("|                | Efetuados", _golsEfetuados, COPADOBRASIL);
	_mostrarGolsCampeonato("| COPA DO BRASIL | Sofridos ", _golsSofridos, COPADOBRASIL);
	cout << "-----------------------------------------------------------" << endl;
	_mostrarGolsCampeonato("|                | Efetuados", _golsEfetuados, BRASILEIRAO);
	_mostrarGolsCampeonato("| BRASILEIRÃO    | Sofridos ", _golsSofridos, BRASILEIRAO);
	cout << "\\ ******************************************************* /" << endl;
}
