#pragma once
#include "grafosTAD.hpp"
#include "arquivosTAD.hpp"

int main()
{

	// número de vértices, inicializado em 0
	int edges = 0; 

	std::cout << "Digite o numero de paises: ";
	std::cin >> edges;

	// Lista de Adjacência --> adj[u] = lista de (v,peso)
	std::vector<std::vector<std::pair<int, int>>> adj(edges);

	std::unordered_map<std::string, int> numPaises;
	std::unordered_map<int, std::string> nomePaises;

	//Fazer leitura das conexões em um .txt
	numPaises = carregarGrafo("grafos.txt", adj, nomePaises);

	//verifica se o grafo eh conexo
	bool conexo = ehConexo(edges, adj);

	// Parte principal do codigo para receber os inputs e chamar as funcoes
	organizaMain(edges, adj, numPaises, nomePaises, conexo);


	return 0;
}