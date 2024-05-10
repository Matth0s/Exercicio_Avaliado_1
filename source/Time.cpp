#include "Time.h"

using namespace std;

Time::Time(void) : _nome("Desconhecido"), _golsEfetuados{}, _golsSofridos{} {}

Time::Time(string nome, const int golsEfetuados[], const int golsSofridos[]) {

	_nome = nome;

	for (unsigned i = 0; i < _anosHistorico * _campeonatos; i++) {
		_golsEfetuados[i / _campeonatos][i % _campeonatos] = golsEfetuados[i];
		_golsSofridos[i / _campeonatos][i % _campeonatos] = golsSofridos[i];
	}
}

Time::~Time(void) {}

void Time::_mostrarGolsPorCampeonato(string texto,
							 int gols[][_campeonatos], Campeonato campeonato) {

	cout << texto;
	for (unsigned i = 0; i < _anosHistorico; i++) {
		cout << " |" << setw(5) << gols[i][campeonato];
	}
	cout << endl;
}

void Time::mostrarGols(void) {

	cout << "/ ********************************************************************************* \\" << endl;
	cout << "|          " << left << setw(18) << _nome << right << "| 2024 | 2023 | 2022 | 2021 | 2020 | 2019 | 2018 | 2017 " << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;
	_mostrarGolsPorCampeonato("|                | Efetuados", _golsEfetuados, CARIOCA);
	_mostrarGolsPorCampeonato("| CARIOCA        | Sofridos ", _golsSofridos, CARIOCA);
	cout << "-------------------------------------------------------------------------------------" << endl;
	_mostrarGolsPorCampeonato("|                | Efetuados", _golsEfetuados, COPADOBRASIL);
	_mostrarGolsPorCampeonato("| COPA DO BRASIL | Sofridos ", _golsSofridos, COPADOBRASIL);
	cout << "-------------------------------------------------------------------------------------" << endl;
	_mostrarGolsPorCampeonato("|                | Efetuados", _golsEfetuados, BRASILEIRAO);
	_mostrarGolsPorCampeonato("| BRASILEIRÃO    | Sofridos ", _golsSofridos, BRASILEIRAO);
	cout << "\\ ********************************************************************************* /" << endl;
}

string Time::getNome(void) {
	return (_nome);
}

int Time::_golsCampeonatoAno(int categoria[][_campeonatos], int ano,
														Campeonato campeonato) {

	if (ano > ANOATUAL) {
		ano = ANOATUAL;
	} else if (ano < ANOFINAL) {
		ano = ANOFINAL;
	}

	return (categoria[ANOATUAL - ano][campeonato]);
}

int Time::getGolsEfetuadosCampeonatoAno(int ano, Campeonato campeonato) {
	return (_golsCampeonatoAno(_golsEfetuados, ano, campeonato));
}

int Time::getGolsSofridosCampeonatoAno(int ano, Campeonato campeonato) {
	return (_golsCampeonatoAno(_golsSofridos, ano, campeonato));
}
