#include "Time.h"
#include <iomanip>

using namespace std;

Time::Time(void) : _golsEfetuados{}, _golsSofridos{} {}

Time::Time(const int golsEfetuados[], const int golsSofridos[]) {

	for (unsigned i = 0; i < _anosHistorico * _campeonatos; i++) {
		_golsEfetuados[i / _campeonatos][i % _campeonatos] = golsEfetuados[i];
		_golsSofridos[i / _campeonatos][i % _campeonatos] = golsSofridos[i];
	}
}

Time::~Time(void) {}

void	Time::_mostrarGolsPorCampeonato(string nomeCampeonato,
							int gols[][_campeonatos], Campeonato campeonato) {

	cout << left << setw(14) << nomeCampeonato;
	for (unsigned i = 0; i < _anosHistorico; i++) {
		cout << right << " |" << setw(3) << gols[i][campeonato];
	}
	cout << endl;
}

void	Time::mostrarGols(void) {

	cout << "     PRÓS      | 8° | 7° | 6° | 5° | 4° | 3° | 2° | 1° " << endl;
	cout << "-------------------------------------------------------" << endl;

	_mostrarGolsPorCampeonato("CARIOCA",_golsEfetuados, CARIOCA);
	_mostrarGolsPorCampeonato("COPA DO BRASIL",_golsEfetuados, COPADOBRASIL);
	_mostrarGolsPorCampeonato("BRASILEIRAO",_golsEfetuados, BRASILEIRAO);

	cout << endl;

	cout << "    CONTRAS    | 8° | 7° | 6° | 5° | 4° | 3° | 2° | 1° " << endl;
	cout << "-------------------------------------------------------" << endl;

	_mostrarGolsPorCampeonato("CARIOCA",_golsSofridos, CARIOCA);
	_mostrarGolsPorCampeonato("COPA DO BRASIL",_golsSofridos, COPADOBRASIL);
	_mostrarGolsPorCampeonato("BRASILEIRAO",_golsSofridos, BRASILEIRAO);
}

int		Time::getGolsEfetuadosCampeonatoAno(int ano, Campeonato campeonato) {
	return (_golsEfetuados[ano][campeonato]);
}

int		Time::getGolsSofridosCampeonatoAno(int ano, Campeonato campeonato) {
	return (_golsSofridos[ano][campeonato]);
}
