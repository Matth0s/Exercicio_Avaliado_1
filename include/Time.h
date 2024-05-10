#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <iomanip>

using namespace std;

enum Campeonato
{
	CARIOCA,
	COPADOBRASIL,
	BRASILEIRAO
};

class Time {

	public:
		static const int	ANOATUAL = 2024;
		static const int	ANOFINAL = 2017;

	private:
		static const int	_campeonatos = 3;
		static const int	_anosHistorico = 8;

		string	_nome;
		int		_golsEfetuados[_anosHistorico][_campeonatos];
		int		_golsSofridos[_anosHistorico][_campeonatos];

		void	_mostrarGolsPorCampeonato(string nomeCampeonato,
									int gols[][_campeonatos], Campeonato campeonato);
		int		_golsCampeonatoAno(int categoria[][_campeonatos], int ano,
							Campeonato campeonato);

	public:
		Time(void);
		Time(string nome, const int golsEfetuados[], const int golsSofridos[]);
		~Time(void);

		void	mostrarGols(void);
		string	getNome(void);
		int		getGolsEfetuadosCampeonatoAno(int ano, Campeonato campeonato);
		int		getGolsSofridosCampeonatoAno(int ano, Campeonato campeonato);
};

#endif
