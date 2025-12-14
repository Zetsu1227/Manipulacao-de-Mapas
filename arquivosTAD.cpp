#include "arquivosTAD.hpp"

std::unordered_map<std::string, int> carregarGrafo(const std::string& caminho, std::vector<std::vector<std::pair<int, int>>>& adj)
{
	//ler arquivo
	std::ifstream arq(caminho);

	int num;
	std::string p1, p2;

	std::unordered_map<std::string, int> numero;

	int conta = 0;


	if (!arq)
		std::cout << "Erro ao abrir o arquivo em carregarGrafo" << std::endl;
	else
	{

		std::string linha;

		while (std::getline(arq, linha))
		{
			std::stringstream ss(linha);
			std::string parte;

			// le string ate o proximo ';'
			std::getline(ss, p1, ';');

			// le string ate o proximo ';'
			std::getline(ss, p2, ';');


			// le double ate o fim da linha
			std::getline(ss, parte, ';');
			num = std::stoi(parte);


			// Coloca eles no mapeamento
			if (!numero.contains(p1))
			{
				numero[p1] = conta;
				conta++;
			}

			if (!numero.contains(p2))
			{
				numero[p2] = conta;
				conta++;
			}

			//Ja que é nao-orientado
			adj[numero[p1]].push_back({ numero[p2], num });
			adj[numero[p2]].push_back({ numero[p1], num });
		}
	}

	arq.close();
	std::cout << "Dados carregados!" << std::endl;

	return numero;

}
