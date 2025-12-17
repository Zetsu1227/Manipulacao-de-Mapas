#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "grafosTAD.hpp"

//Carrega o grafo dado no grafos.txt
std::unordered_map<std::string, int> carregarGrafo(const std::string& caminho, std::vector<std::vector<std::pair<int, int>>>& adj, std::unordered_map<int, std::string>& nomes);

// Interface do usuario -> chamada das funcoes e saida do programa
void organizaMain(int edges, const std::vector<std::vector<std::pair<int, int>>>& adj, std::unordered_map<std::string, int>& numPaises, 
	std::unordered_map<int, std::string>& nomePaises, bool conexo);