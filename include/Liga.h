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

		/* Função para organizar dados que serão exibidos, de forma descrescente. */
		void	_bubbleSort(vector<vector<double> > &dados);

		/* Formatação padronizada para exibição do cabeçalho. */
		void	_exibirCabecalho(string texto);

		/* Formatação padronizada para exibição do tipo da estatistica. */
		void	_exibirTitulo(string texto);

		/* Formatação padronizada para exibição das informações da estatistica. */
		void	_exibirCorpo(int index, int flag, double valor);

		/* Formatação padronizada para exibição do rodapé. */
		void	_exibirRodape(void);

		/* Formatação para padronizar saidas de metodos com Liga sem Times. */
		void	_exibirLigaVazia(void);

		/*  Função auxiliar para exibir o desempenho dos Times de forma agrupada
		nas categorias Melhora, Estavel e Piora. */
		void	_exibirDesempenho(vector<vector<double> > &dados);

	public:
		/* Construtor Padrão que inicia uma Liga sem Times. */
		Liga(void);

		void	adicionarTime(Time time);
		void	removerTimePorNome(string nome);

		/* Lista o desempenho dos Times da Liga em determinado campeonato.
		Os numeros são exibidos de forma agrupada e calculados para gols
		Efetuados e Sofridos. */
		void	desempenhoCampeonato(Campeonato campeonato);

		/* Lista o desempenho dos Times da Liga durante todo o Ano.
		Os numeros são exibidos de forma agrupada e calculados para gols
		Efetuados e Sofridos. */
		void	desempenhoAnual(void);

		/* Exibe o Time com maior saldo de gols em determinado campeonato. */
		void	maiorSaldoGolsCampeonato(Campeonato campeonato);

		/* Exibe o Time com maior saldo de gols anual. */
		void	maiorSaldoGolsAnual(void);

		/* Lista os melhores desempenhos(por gols Efetuados e Sofridos) dos
		Times da Liga em determinado campeonato. */
		void	melhorEvolucaoCampeonato(Campeonato campeonato);

		/* Lista os melhores desempenhos(por gols Efetuados e Sofridos) dos
		Times da Liga durante o Ano. */
		void	melhorEvolucaoAnual(void);

		/* Função para a visualização dos Times da Liga. */
		void	mostrarTimes(void);

};

#endif
