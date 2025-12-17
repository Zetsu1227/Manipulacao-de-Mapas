#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

//verifica se o grafo eh conexo
bool ehConexo(int edges, const std::vector<std::vector<std::pair<int, int>>>& adj);

// Busca em largura que retorna um caminho entre dois pontos -> iterativo
int bfsMenor(int origem, int destino, const std::vector<std::vector<std::pair<int, int >>>& adj);

//Busca em profundidade que retorna um caminho entre dois pontos -> recursivo
int dfsMenor(int origem, int destino, const std::vector<std::vector<std::pair<int, int>>>& adj, std::vector<bool>& visitado);

//Caminho mínimo a partir de um vértice usando o algoritmo de dijkstra
//retorna uma lista contendo a distancia de cada nodo em relação a origem
std::vector<int> dijkstra(int origem, const std::vector<std::vector<std::pair<int, int>>>& adj);

//agm -> menor caminho do grafo que passa por todas os nodos sem formar ciclos, usando o algoritmo de prim
//alem de alterar um vetor para guardar os pais da agm, ele retorna o valor total dela
int prim(const std::vector<std::vector<std::pair<int, int>>>& adj, std::vector<int>& agm);

//retorna o menor valor entre os nodos nao visitados -> auxiliar para o algoritmo de prim
int chaveMin(std::vector<int>& chave, std::vector<bool>& visited);

//funcao principal que imprime a arvore geradora minima
void printAGM(const std::vector<int>& agm, std::unordered_map<int, std::string>& nomePaises);

//funcao recursiva auxiliar da printAGM para percorrer a arvore
void auxPrint(int origem, const std::unordered_multimap<int, int>& mapa, int espacamento, std::unordered_map<int, std::string>& nomePaises);




