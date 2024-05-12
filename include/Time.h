#ifndef TIME_H
#define TIME_H

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

enum Campeonato
{
	CARIOCA,
	COPADOBRASIL,
	BRASILEIRAO
};

class Time {

	public:
		/* Ano mais atual do historico de gols. */
		static const int	MAXANO = 2023;

		/* Ano mais antigo do historico de gols. */
		static const int	MINANO = 2020;

	private:
		/* Numero de campeonatos que um time participa. */
		static const int	_campeonatos = 3;

		/* Numero de anos no intervalo de tempo do historico. */
		static const int	_anos = (MAXANO - MINANO) + 1;

		/* Valor do intervalo de anos utilizado no calculo da Média Movel */
		static const int	_mediaN = 3;

		string	_nome;
		int		_golsEfetuados[_campeonatos][_anos];
		int		_golsSofridos[_campeonatos][_anos];

		/* Funçao auxiliar de exibição, formata o historico de gols de forma
		apropriada. */
		void	_mostrarGolsCampeonato(string texto, int gols[][_anos],
										Campeonato campeonato);

		/* Função auxiliar para os métodos getGols da classe. Retorna o elemento
		solicitado do array bidimensional solicitado realizando algumas
		contingências de acesso. */
		int		_golsCampeonatoAno(int gols[][_anos], Campeonato campeonato,
										int ano);

		/* Função que calcula a Media Movel por campeonato para o calculo do
		Desempenho do Time. */
		double _mediaMovelCampeonato(int gols[][_anos], Campeonato campeonato,
										int ano);

		/* Função que calcula a Media Movel anual para o calculo do Desempenho
		do Time. */
		double _mediaMovelAnual(int gols[][_anos], int ano);

	public:
		/* Construtor padrão, utilizado para a instanciação rápida de times.
		Zera o histórico de gols e atribui o nome "Desconhecido" ao Time. */
		Time(void);

		/* Atribui o nome parâmetro ao time e transforma os 2 arrays
		unidimensionais em arrays bidimensionais para os atributos, seguindo a
		relação:  a_1 = b_11; a_2 = b_12; a_3 = b_21 ;... */
		Time(string nome, const int golsEfetuados[], const int golsSofridos[]);


		string	getNome(void);
		int		getGolsEfetuadosCampeonatoAno(Campeonato campeonato, int ano);
		int		getGolsSofridosCampeonatoAno(Campeonato campeonato, int ano);
		int		getSaldoGolsCampeonatoAno(Campeonato campeonato, int ano);

		/* Calcula o desempenho do Time no campeonato considerando os gols
		efetuados, quanto mais gols efetuados, melhor. Retorna o valor calculado
		em porcentagem. */
		double		getDesempenhoGolsEfetuadosCampeonato(Campeonato campeonato);

		/* Calcula o desempenho do Time no campeonato considerando os gols
		sofridos, quando menos gol sofrido, melhor. Retorna o valor calculado
		em porcentagem. */
		double		getDesempenhoGolsSofridosCampeonato(Campeonato campeonato);

		/* Calcula o desempenho do Time utilizando os gols efetuados e
		considerando todos os campeonatos (desempenho anual). Retorna o valor
		calculado em porcentagem. */
		double		getDesempenhoGolsEfetuados(void);

		/* Calcula o desempenho do Time utilizando os gols sofridos e
		considerando todos os campeonatos (desempenho anual). Retorna o valor
		calculado em porcentagem. */
		double		getDesempenhoGolsSofridos(void);

		/* Função para a visualização do histórico de gols do time. */
		void	mostrarGols(void);

};

#endif
