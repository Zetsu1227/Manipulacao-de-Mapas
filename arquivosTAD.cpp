#include "arquivosTAD.hpp"

std::unordered_map<std::string, int> carregarGrafo(const std::string& caminho, std::vector<std::vector<std::pair<int, int>>>& adj, std::unordered_map<int, std::string>& nomes)
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
				nomes[conta] = p1;
				conta++;
			}

			if (!numero.contains(p2))
			{
				numero[p2] = conta;
				nomes[conta] = p2;
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

void organizaMain(int edges, const std::vector<std::vector<std::pair<int, int>>>& adj, std::unordered_map<std::string, int>& numPaises,
	std::unordered_map<int, std::string>& nomePaises, bool conexo) 
{

	//opcao escolhida pelo usuario da manipulação do mapa
	int opcao = 0;

	//auxiliar para receber os inputs dos nomes
	std::string aux1, aux2;

	//Guarda os pais dos nodos
	std::vector<bool> visitado(edges, false);

	//Guarda menor caminho
	std::vector<int> menorCaminho;

	//Guarda menor caminho
	std::vector<int> agm(edges);

	//auxiliar para guardar o resultado das funcoes
	int resultado = -1;



	do
	{

		std::cout << "\n======= Manipulacao de Mapas =======\n\n";

		std::cout << "1. Caminhamento entre dois paises\n";		// BFS e DFS

		std::cout << "2. Caminho minimo de um pais para os outros\n";	// Dijkstra 

		std::cout << "3. Arvore geradora minima\n";		// Prim

		std::cout << "4. Sair\n";	// Sair do programa

		std::cout << "Escolha: ";
		std::cin >> opcao;

		switch (opcao)
		{

		case 1:

			//Para opcao == 1
			std::cout << "\n\n======= Manipulacao de Mapas =======\n";
			std::cout << "======= Distancia por caminhamentos =======\n\n";

			std::cout << "1. BFS\n";
			std::cout << "2. DFS\n";
			std::cout << "Escolha: ";
			std::cin >> opcao;

			std::cout << "\nPais de origem: ";
			std::cin >> aux1;

			std::cout << "Pais de destino: ";
			std::cin >> aux2;

			if (opcao == 1)
			{
				resultado = bfsMenor(numPaises[aux1], numPaises[aux2], adj);

				if (resultado != -1)
					std::cout << "\nDistancia total: " << resultado << "\n";
				else
					std::cout << "Nao encontrado no BFS\n";

			}
			else if (opcao == 2)
			{
				resultado = dfsMenor(numPaises[aux1], numPaises[aux2], adj, visitado);

				if (resultado != -1)
					std::cout << "Distancia total: " << resultado << "\n";
				else
					std::cout << "Nao encontrado no DFS\n";

			}
			else
				std::cout << "\n Escolha invalida \n";

			break;

		case 2:

			std::cout << "\n\n======= Manipulacao de Mapas =======\n";
			std::cout << "======= Menor distancias =======\n\n";

			std::cout << "Pais de partida: ";
			std::cin >> aux1;

			menorCaminho = dijkstra(numPaises[aux1], adj);

			for (int i = 0; i < edges; i++)
			{
				if (numPaises[aux1] != i)
				{
					if (menorCaminho[i] != INT_MAX)
						std::cout << "\n " << nomePaises[i] << ": " << menorCaminho[i];
					else
						std::cout << "\n " << nomePaises[i] << ": " << "nao acessivel";
				}
			}

			break;

		case 3:
			std::cout << "\n\n======= Manipulacao de Mapas =======\n";
			std::cout << "===== Arvore Geradora Minima =====\n\n";

			if (conexo)
			{
				resultado = prim(adj, agm);

				std::cout << "\nValor da agm: " << resultado << "\n\n";

				printAGM(agm, nomePaises);
			}
			else
				std::cout << "\nGrafo nao conexo\n";

			break;

		case 4:
			break;	//SAIR
		default:
			std::cout << "\n Escolha invalida \n";
		}

	} while (opcao != 4);


}
