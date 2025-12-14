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

	std::cout << "Digite o numero de paises: ";
	std::cin >> edges;

	// Lista de Adjacência --> adj[u] = lista de (v,peso)
	std::vector<std::vector<std::pair<int, int>>> adj(edges);

	std::unordered_map<std::string, int> numPaises;

	//Guarda os nodos percorridos
	std::vector<int> ids;

	//Fazer leitura das conexões em um .txt
	numPaises = carregarGrafo("grafos.txt", adj);

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
			std::cout << "======= Distancia =======\n\n";

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
				int resultado = bfsMenor(numPaises[aux1], numPaises[aux2], adj, ids);

				if (resultado != -1)
					std::cout << "\nDistancia total: " << resultado << "\n";
				else
					std::cout << "Nao encontrado no BFS\n";

			}
			else if (opcao == 2)
			{
				int resultado = dfsMenor(numPaises[aux1], numPaises[aux2], adj, ids);

				if (resultado != -1)
					std::cout << "Distancia total: " << resultado << "\n";
				else
					std::cout << "Nao encontrado no DFS\n";

			}
			else
				std::cout << "\n Escolha invalida \n";

			break;

		case 2:
			// Para opcao == 2
			break;

		case 3:
			// Para opcao == 3
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