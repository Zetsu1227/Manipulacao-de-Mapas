#pragma once
#include "grafosTAD.hpp"
#include "arquivosTAD.hpp"

int main()
{

	// número de vértices, inicializado em 0
	int edges = 0; 

	//opcao escolhida pelo usuario da manipulação do mapa
	int opcao = 0;

	std::string aux1, aux2;
	bool achouDFS = false;

	std::cout << "Digite o numero de paises: ";
	std::cin >> edges;

	// Lista de Adjacência --> adj[u] = lista de (v,peso)
	std::vector<std::vector<std::pair<int, int>>> adj(edges);

	std::unordered_map<std::string, int> numPaises;

	//Guarda os pais dos nodos
	std::vector<bool> visitado(edges, false);

	//Guarda menor caminho
	std::vector<int> menorCaminho;

	//Guarda menor caminho
	std::vector<int> agm(edges);

	//auxiliar para guardar o resultado das funcoes
	int resultado = -1;

	//Fazer leitura das conexões em um .txt
	numPaises = carregarGrafo("grafos.txt", adj);

	//verifica se o grafo eh conexo
	bool conexo = ehConexo(edges, adj);


	do
	{

		std::cout << "\n======= Manipulacao de Mapas =======\n\n";

		std::cout << "1. Caminhamento entre dois paises\n";		// BFS e DFS

		std::cout << "2. Caminho minimo de um pais para os outros\n";	// Dijkstra 

		std::cout << "3. Arvore geradora minima\n";		// Prim

		std::cout << "4. Conjuntos de paises que nao fazem fronteira\n";	// Coloração

		std::cout << "5. Sair\n";	// Sair do programa

		std::cout << "Escolha: ";
		std::cin >> opcao;

		switch (opcao)
		{

		case 1:

			//Para opcao == 1
			std::cout << "\n======= Manipulacao de Mapas =======\n";
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

			std::cout << "\n======= Manipulacao de Mapas =======\n";
			std::cout << "======= Menor distâncias =======\n\n";

			std::cout << "Pais de partida: ";
			std::cin >> aux1;

			menorCaminho = dijkstra(numPaises[aux1], adj);
			
			for (int i = 0; i < edges; i++)
			{
				if (menorCaminho[i] != INT_MAX)
					std::cout << "\n " << i << ": " << menorCaminho[i];
				else
					std::cout << "\n " << i << ": " << "nao acessivel";
			}

			break;

		case 3:
			std::cout << "\n======= Manipulacao de Mapas =======\n";
			std::cout << "===== Arvore Geradora Minima =====\n\n";

			if (conexo)
			{
				resultado = prim(adj, agm);

				std::cout << "\nValor da agm: " << resultado << "\n\n";

				printAGM(agm);
			}
			else
				std::cout << "\nGrafo nao conexo\n";
			
			break;

		case 4: 
			// Para opcao 4
			break;


		case 5:
			break;	//SAIR
		default:
			std::cout << "\n Escolha invalida \n";
		}

	} while (opcao != 5);

	return 0;
}