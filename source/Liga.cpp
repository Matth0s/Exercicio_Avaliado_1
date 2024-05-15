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

	_exibirCabecalho("TIMES");

	cout << endl;
	for (unsigned i = 0; i < _times.size(); i++) {
		_times.at(i).mostrarGols();
	}

	_exibirRodape();
}

void Liga::_bubbleSort(vector<vector<double>> &dados) {

	vector<double>	temp;

	if (dados.size()) {
		for (unsigned i = 0; i < dados.size() - 1; i++) {
			for (unsigned j = 0; j < dados.size() - 1 - i; j++) {
				if (dados.at(j).at(2) < dados.at(j + 1).at(2)) {
					temp = dados.at(j);
					dados.at(j) = dados.at(j + 1);
					dados.at(j + 1) = temp;
				}
			}
		}
	}
}

void Liga::_exibirCabecalho(string texto) {

	cout << "\n/¨¨¨¨¨¨¨   "
		 << left << setw(20) << texto
		 << right << "¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\\"
		 << endl;
}

void Liga::_exibirTitulo(string texto) {

	cout << "\n  ● " << texto << ":\n";
}

void Liga::_exibirCorpo(int index, int flag, double valor) {

	// Formata o nome do Time
	cout << "     "
		 << left << setw(15) << _times.at(index).getNome()
		 << right << " | ";

	// Escolhe o texto auxiliar do informe
	if (flag == 1) {
		cout << "Aumento de Gols Efetuados   : ";
	} else if (flag == 0) {
		cout << "Diminuição de Gols Sofridos : ";
	} else {
		cout << "Saldo de gols total         : ";
	}

	// Formatar o valor do informe
	if (flag == 2) {
		cout << setw(3) << defaultfloat << valor << " gols";
	} else {
		cout << setw(6) << fixed << setprecision(2) << valor << "%";
	}
	cout << endl;
}

void Liga::_exibirRodape(void) {

	cout << "\n\\_____________________________________________________________/\n"
		 << endl;
}

void Liga::_exibirLigaVazia(void) {

	_exibirCabecalho("LIGA SEM TIMES");
	_exibirRodape();
}

void Liga::_exibirDesempenho(vector<vector<double>> &dados) {

	unsigned int	j = 0;

	// Times com desempenho maior que 10%
	_exibirTitulo("Melhora de Desempenho");
	while (j < dados.size() && dados.at(j).at(2) > 10) {
		_exibirCorpo(dados.at(j).at(0), dados.at(j).at(1), dados.at(j).at(2));
		j++;
	}

	// Times com desempenho entre 10% e -10%
	_exibirTitulo("Estabilidade de Desempenho");
	while (j < dados.size() && dados.at(j).at(2) > -10) {
		_exibirCorpo(dados.at(j).at(0), dados.at(j).at(1), dados.at(j).at(2));
		j++;
	}

	// Times com desempenho menor que -10%
	_exibirTitulo("Piora de Desempenho");
	while (j < dados.size()) {
		_exibirCorpo(dados.at(j).at(0), dados.at(j).at(1), dados.at(j).at(2));
		j++;
	}
}

void Liga::desempenhoCampeonato(Campeonato campeonato) {

	// Variavel armazenara dados necessarios para exibição das estatisticas
	// Estruturada no formato { {i1, f1, d1} ,  {i2, f2, d2} } onde:
	//     numeração representa o time (Ex: time 1, time 2)
	//     i = indice do time na na lista _times;
	//     f = flag que indica são dados de gols Efetuados ou Sofridos
	//     d = valor em porcentagem do desempenho do time
	vector<vector<double>>	dados;

	if (!_times.size()) {
		_exibirLigaVazia();
		return;
	}

	for (unsigned i = 0; i < _times.size(); i++) {

		// Coletando desempenho por gols Efetuados
		dados.push_back(vector<double>({(double) i, 1,
			_times.at(i).getDesempenhoGolsEfetuadosCampeonato(campeonato)
		}));

		// Coletando desempenho por gols Sofridos
		dados.push_back(vector<double>({(double) i, 0,
			_times.at(i).getDesempenhoGolsSofridosCampeonato(campeonato)
		}));
	}

	_bubbleSort(dados);

	switch (campeonato) {
		case CARIOCA:
			_exibirCabecalho("CARIOCA");
			break;
		case COPADOBRASIL:
			_exibirCabecalho("COPA DO BRASIL");
			break;
		default:
			_exibirCabecalho("BRASILEIRAO");
			break;
	}
	_exibirDesempenho(dados);
	_exibirRodape();
}

void Liga::desempenhoAnual(void) {

	// Variavel armazenara dados necessarios para exibição das estatisticas
	// Estruturada no formato { {i1, f1, d1} ,  {i2, f2, d2} } onde:
	//     numeração representa o time (Ex: time 1, time 2)
	//     i = indice do time na na lista _times;
	//     f = flag que indica são dados de gols Efetuados ou Sofridos
	//     d = valor em porcentagem do desempenho do time
	vector<vector<double>>	dados;

	if (!_times.size()) {
		_exibirLigaVazia();
		return;
	}

	for (unsigned i = 0; i < _times.size(); i++) {

		// Coletando desempenho por gols Efetuados
		dados.push_back(vector<double>({
			(double) i, 1, _times.at(i).getDesempenhoGolsEfetuados()
		}));

		// Coletando desempenho por gols Sofridos
		dados.push_back(vector<double>({
			(double) i, 0, _times.at(i).getDesempenhoGolsSofridos()
		}));
	}

	_bubbleSort(dados);

	_exibirCabecalho("ANUAL");
	_exibirDesempenho(dados);
	_exibirRodape();
}

void Liga::maiorSaldoGolsCampeonato(Campeonato campeonato) {

	// Variavel armazenara dados necessarios para exibição das estatisticas
	// Estruturada no formato { i, s } onde:
	//     i = indice do time na na lista _times;
	//     s = valor do saldo de gols do time
	double	maior[2];

	if (!_times.size()) {
		_exibirLigaVazia();
		return;
	}

	// Carregando dados iniciais para as comparações
	maior[1] = _times.at(0).getSaldoGolsCampeonato(campeonato);

	for (unsigned i = 0; i < _times.size(); i++) {
		double saldo;

		saldo = _times.at(i).getSaldoGolsCampeonato(campeonato);
		if (maior[1] < saldo) {
			maior[0] = i;
			maior[1] = saldo;
		}
	}

	switch (campeonato) {
		case CARIOCA:
			_exibirCabecalho("CARIOCA");
			break;
		case COPADOBRASIL:
			_exibirCabecalho("COPA DO BRASIL");
			break;
		default:
			_exibirCabecalho("BRASILEIRAO");
			break;
	}
	_exibirTitulo("Maior Saldo de Gols");
	_exibirCorpo(maior[0], 2, maior[1]);
	_exibirRodape();
}

void Liga::maiorSaldoGolsAnual(void) {

	// Variavel armazenara dados necessarios para exibição das estatisticas
	// Estruturada no formato { i, s } onde:
	//     i = indice do time na na lista _times;
	//     s = valor do saldo de gols do time
	double	maior[2];

	if (!_times.size()) {
		_exibirLigaVazia();
		return;
	}

	// Carregando dados iniciais para as comparações
	maior[1] = _times.at(0).getSaldoGols();

	for (unsigned i = 0; i < _times.size(); i++) {
		double saldo;

		saldo = _times.at(i).getSaldoGols();
		if (maior[1] < saldo)
		{
			maior[0] = i;
			maior[1] = saldo;
		}
	}

	_exibirCabecalho("ANUAL");
	_exibirTitulo("Maior Saldo de Gols");
	_exibirCorpo(maior[0], 2, maior[1]);
	_exibirRodape();
}

void Liga::melhorEvolucaoCampeonato(Campeonato campeonato) {

	// Variavel armazenara dados necessarios para exibição das estatisticas
	// Estruturada no formato { {i1, f1, d1} ,  {i2, f2, d2} } onde:
	//     1 = vetor desempenho gols Efetuados
	//     2 = vetor desempenho gols Sofridos
	//     i = indice do time na na lista _times;
	//     f = flag que indica são dados de gols Efetuados ou Sofridos
	//     d = valor em porcentagem do desempenho do time
	vector<vector<double>>	dados({vector<double>({0, 1, 0}),
								  vector<double>({0, 0, 0})});

	if (!_times.size()) {
		_exibirLigaVazia();
		return;
	}

	// Carregando dados iniciais para as comparações
	dados.at(0).at(2) = _times.at(0).getDesempenhoGolsEfetuadosCampeonato(campeonato);
	dados.at(1).at(2) = _times.at(0).getDesempenhoGolsSofridosCampeonato(campeonato);

	for (unsigned i = 0; i < _times.size(); i++) {
		double desempenho;

		// Verificando maior desempenho em gols Efetuados (atualizando dados.at(0))
		desempenho = _times.at(i).getDesempenhoGolsEfetuadosCampeonato(campeonato);
		if (dados.at(0).at(2) < desempenho) {
			dados.at(0).at(0) = i;
			dados.at(0).at(2) = desempenho;
		}

		// Verificando maior desempenho em gols Sofridos (atualizando dados.at(1))
		desempenho = _times.at(i).getDesempenhoGolsSofridosCampeonato(campeonato);
		if (dados.at(1).at(2) < desempenho) {
			dados.at(1).at(0) = i;
			dados.at(1).at(2) = desempenho;
		}
	}

	_bubbleSort(dados);

	switch (campeonato) {
		case CARIOCA:
			_exibirCabecalho("CARIOCA");
			break;
		case COPADOBRASIL:
			_exibirCabecalho("COPA DO BRASIL");
			break;
		default:
			_exibirCabecalho("BRASILEIRAO");
			break;
	}
	_exibirTitulo("Melhor Evolucao");
	for (unsigned i = 0; i < dados.size(); i++) {
		_exibirCorpo(dados.at(i).at(0), dados.at(i).at(1), dados.at(i).at(2));
	}
	_exibirRodape();
}

void Liga::melhorEvolucaoAnual(void) {

	// Variavel armazenara dados necessarios para exibição das estatisticas
	// Estruturada no formato { {i1, f1, d1} ,  {i2, f2, d2} } onde:
	//     1 = vetor desempenho gols Efetuados
	//     2 = vetor desempenho gols Sofridos
	//     i = indice do time na na lista _times;
	//     f = flag que indica são dados de gols Efetuados ou Sofridos
	//     d = valor em porcentagem do desempenho do time
	vector<vector<double>>	dados({vector<double>({0, 1, 0}),
								  vector<double>({0, 0, 0})});

	if (!_times.size()) {
		_exibirLigaVazia();
		return;
	}

	// Carregando dados iniciais para as comparações
	dados.at(0).at(2) = _times.at(0).getDesempenhoGolsEfetuados();
	dados.at(1).at(2) = _times.at(0).getDesempenhoGolsSofridos();

	for (unsigned i = 0; i < _times.size(); i++) {
		double desempenho;

		// Verificando maior desempenho em gols Efetuados (atualizando dados.at(0))
		desempenho = _times.at(i).getDesempenhoGolsEfetuados();
		if (dados.at(0).at(2) < desempenho) {
			dados.at(0).at(0) = i;
			dados.at(0).at(2) = desempenho;
		}

		// Verificando maior desempenho em gols Sofridos (atualizando dados.at(1))
		desempenho = _times.at(i).getDesempenhoGolsSofridos();
		if (dados.at(1).at(2) < desempenho) {
			dados.at(1).at(0) = i;
			dados.at(1).at(2) = desempenho;
		}
	}

	_bubbleSort(dados);

	_exibirCabecalho("ANUAL");
	_exibirTitulo("Melhor Evolucao");
	for (unsigned i = 0; i < dados.size(); i++) {
		_exibirCorpo(dados.at(i).at(0), dados.at(i).at(1), dados.at(i).at(2));
	}
	_exibirRodape();
}
