#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Time.h"
#include "Liga.h"

class Utils {

	public:
		/* Numero de elementos dos arrays utilizados, esse numero é igual aos
		campeonatos disputados vezes os anos do historico. */
		static const int	limite = 12;

		/* Atribui aos elementos do array parametro um int do intervalo [20, 90). */
		static void			arrayGolsAleatorios(int array[limite]);

		/* Cria um objeto Time utilizando 2 arrays "aleatórios" e o nome parametro. */
		static Time			gerarTime(string nome);

		/* Cria um objeto do tipo Liga e adiciona 10 times com numeros ficticios. */
		static Liga			gerarLiga(void);

};

#endif
