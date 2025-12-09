#include "grafosTAD.hpp"

int main()
{

	// número de vértices, inicializado em 0
	int edges = 0; 

	//opcao escolhida pelo usuario da manipulação do mapa
	int opcao = 0;

	Country aux1, aux2;

	std::cout << "Digite o numero de paises: ";
	std::cin >> edges;

	// Lista de Adjacência --> adj[u] = lista de (v,peso)
	std::vector<std::vector<std::pair<Country, int>>> adj(edges);

	//Fazer leitura das conexões em um .txt

	std::cout << "\n======= Manipulacao de Mapas =======\n\n";

	std::cout << "1. Distancia entre dois paises\n";

	std::cout << "2. Caminho minimo de um pais para os outros\n";

	std::cout << "3. Arvore geradora minima\n";

	std::cout << "4. Conjuntos de paises que nao fazem fronteira\n";

	std::cout << "5. Sair\n";

	std::cout << "Escolha: ";
	std::cin >> opcao;


	//Para opcao == 1
	std::cout << "\n======= Manipulacao de Mapas =======\n";
	std::cout << "\n======= Distancia =======\n\n";

	std::cout << "1. BFS";
	std::cout << "2. DFS";
	std::cout << "3. Dijkstra";
	std::cout << "Dijkstra eh garantido ser a distancia minima" << std::endl;
	std::cout << "Escolha: ";
	std::cin >> opcao;

	std::cout << "\nPais de origem: ";
	std::cin >> aux1.name;

	std::cout << "Pais de destino: ";
	std::cin >> aux2.name;


	return 0;
}