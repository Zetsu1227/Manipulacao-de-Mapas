#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

// Busca em largura que retorna um caminho entre dois pontos -> iterativo
int bfsMenor(int origem, int destino, const std::vector<std::vector<std::pair<int, int >>>& adj, std::vector<int>& ids);

//Busca em profundidade que retorna um caminho entre dois pontos -> recursivo
int dfsMenor(int origem, int destino, const std::vector<std::vector<std::pair<int, int >>>& adj, std::vector<int>& ids);
