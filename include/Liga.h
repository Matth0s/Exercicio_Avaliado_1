#ifndef LIGA_H
#define LIGA_H

#include "Time.h"
#include <vector>
#include <stdlib.h>

class Liga {

	private:
		/* Numero de anos considerados no calculo da Média Movel. */
		static const int	_mediaN = 3;

		vector<Time>		_times;

	public:
		Liga(void);

		void	adicionarTime(Time time);
		void	removerTimePorNome(string nome);

		//1 -- 2
		// void	desempenhoCampeonato(Campeonato campeonato);
		// 3
		// void	desempenhoTotal(void);

		//4
		// void	maiorSaldoGolsCampeonato(Campeonato campeonato);
		// void	maiorSaldoGolsTotal(void);

		// 5
		// void	melhorEvolucaoCampeonato(Campeonato campeonato);
		// void	melhorEvolucaoTotal(void);

		/* Função para a visualização dos Times da Liga. */
		void	mostrarTimes(void);

};

#endif
