#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;

enum Campeonato
{
	CARIOCA,
	COPADOBRASIL,
	BRASILEIRAO
};

class Time {

	private:
		static const int	_campeonatos = 3;
		static const int	_anosHistorico = 8;

		int		_golsEfetuados[_anosHistorico][_campeonatos];
		int		_golsSofridos[_anosHistorico][_campeonatos];

		void	_mostrarGolsPorCampeonato(string nomeCampeonato,
							int gols[][_campeonatos], Campeonato campeonato);

	public:
		Time(void);
		Time(const int golsEfetuados[], const int golsSofridos[]);
		~Time(void);

		void	mostrarGols(void);
		int		getGolsEfetuadosCampeonatoAno(int ano, Campeonato campeonato);
		int		getGolsSofridosCampeonatoAno(int ano, Campeonato campeonato);
};

#endif
