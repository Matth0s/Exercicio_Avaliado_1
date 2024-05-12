#include "Liga.h"

using namespace std;

Liga::Liga(void) : _times() {}

void Liga::adicionarTime(Time time) {
	_times.push_back(time);
}

void Liga::removerTimePorNome(string nome) {

	for (unsigned i = 0; i < _times.size(); i++) {
		if (_times.at(i).getNome().compare(nome) == 0) {
			_times.erase(_times.begin() + i);
			break;
		}
	}
}

void Liga::mostrarTimes(void) {

	for (unsigned i = 0; i < _times.size(); i++) {
		_times.at(i).mostrarGols();
		cout << endl;
	}
}

// int

// desempenho campeonato efetuados (

// )

// desempenho campeonato sofridos {

// }

// desempenho total efetuados (

// )

// desempenho total sofridos (
//
// )

// void	Liga::desempenhoCampeonato(Campeonato campeonato) {

// 	vector<Time>	bomEfetuados;
// 	vector<Time>	bomSofridos;

// 	vector<Time>	medioEfetuados;
// 	vector<Time>	medioSofridos;

// 	vector<Time>	ruimEfetuados;
// 	vector<Time>	ruimSofridos;

// 	for (unsigned i = 0; i < _times.size(); i++) {
// 		switch (expression)
// 		{
// 		case /* constant-expression */:
// 			/* code */
// 			break;

// 		default:
// 			break;
// 		}
// 	}

// 	bom desempenho efetuados
// 	bom desempenho sofridos
// 	desempenho regular efetuados
// 	desempenho regular sofridos
// 	desempenho ruim efetuados
// 	desempenho ruim sofridos



// }
// void	Liga::desempenhoTotal(void) {}

// double	calcularSaldoGols(Time time, Campeonato campeonato) {

// 	for (unsigned i = 0; i < ) {

// 	}
// }
// void	Liga::maiorSaldoGolsCampeonato(Campeonato campeonato) {

// 	Time	time;
// 	int		maiorSaldo;
// 	int		saldo;

// 	if (!_times.size()) {
// 		cout << "A Liga não possui Times" << endl;
// 		return ;
// 	}

// 	maiorSaldo = calcularSaldoGols(_times.at(0), campeonato);
// 	saldo = 0;
// 	for (unsigned i = 0; i < _times.size(); i++) {
// 		saldo = calcularSaldoGols(_times.at(i), campeonato);
// 		if (maiorSaldo < saldo) {
// 			maiorSaldo = saldo;
// 			time = _times.at(i);
// 		}
// 	}

// 	//time com o maior saldo selecionado

// }

// void	Liga::maiorSaldoGolsTotal(void) {}

// void	Liga::melhorEvolucaoCampeonato(Campeonato campeonato) {}
// void	Liga::melhorEvolucaoTotal(void) {}

