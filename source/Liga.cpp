#include "Liga.h"

using namespace std;

Liga::Liga(void) : _times() {}

Liga::~Liga(void) {}

double Liga::_calcularMediaMovel(Time time, int ano, Campeonato campeonato) {

	double total;

	if (ano > Time::ANOATUAL) {
		ano = Time::ANOATUAL;
	} else if (ano < Time::ANOFINAL) {
		ano = Time::ANOFINAL;
	}

	total = 0;
	for (unsigned i = ano; i >= Time::ANOFINAL; i--) {
		total += time.getGolsEfetuadosCampeonatoAno(ano, campeonato);
	}
	total *= 1 / (ano - Time::ANOFINAL);

	return (total);
}

double Liga::_calcularDesempenho(Time time, int ano, Campeonato campeonato) {

	_calcularMediaMovel(time, ano, campeonato) / _calcularMediaMovel(time, ano, campeonato);
}

void Liga::adicionarTime(Time time) {
	_times.push_back(time);
}

void Liga::removerTimePorNome(string nome) {

	for (unsigned i = 0; i < _times.size(); i++) {
		if (_times[i].getNome().compare(nome) == 0) {
			_times.erase(_times.begin() + i);
			break;
		}
	}
}

void Liga::mostrarTimes(void) {

	for (unsigned i = 0; i < _times.size(); i++) {
		_times[i].mostrarGols();
	}
}

// void	Liga::maiorSaldoGolsCampeonato(Campeonato campeonato) {

// 	// if (teste < 0)
// 	// // else if ( = 0)
// 	// // else ( outro)


// 	// for (unsigned i = 0; i < _times.size(); i++) {
// 	// 	if ()
// 	// }
// }
