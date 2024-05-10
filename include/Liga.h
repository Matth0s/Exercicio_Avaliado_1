#ifndef LIGA_H
#define LIGA_H

#include "Time.h"
#include <vector>
#include <stdlib.h>

class Liga {

	private:
		vector<Time>	_times;

		double	_calcularMediaMovel(Time time, int ano, Campeonato campeonato);
		double	_calcularDesempenho(Time time, int ano, Campeonato campeonato);

	public:
		Liga(void);
		~Liga(void);

		void	adicionarTime(Time time);
		void	removerTimePorNome(string nome);
		void	mostrarTimes();

		/*
		1 - exibir evolução da media dos gols realizados e sofridos de tres times nos ultimos anos
			média por campeonato e total

		2 - exibir de forma agrupada os times que apresentaram melhoria de desempenho em relação aos gols efetuados e sofridos
			no ultimo ano	para cada campeonato
			melhoria de sesempenho ano atual / ano anterior  10%

			mostrar times que pioraram

			mostrar times que ficaram na mesma

		3 - o mesmo que o 2, mas no total

		exibir o time com maior saldo de gols e
			pra cada campeonato
		5 mostrar qual dos times teve maior evolução no ultimo ano total


		// */

		// // 4
		// void	maiorSaldoGolsCampeonato(Campeonato campeonato);
		// void	maiorSaldoGolsTotal();

		// //5
		// void	timeMaiorEvolucaoGolsEfetuadosPorCampeonato(Campeonato campeonato);
		// void	timeMaiorEvolucaoGolsSofridosPorCampeonato(Campeonato campeonato);
		// void	timeMaiorEvolucaoGolsEfetuadosTotal();
		// void	timeMaiorEvolucaoGolsSofridosTotal();
};

#endif
