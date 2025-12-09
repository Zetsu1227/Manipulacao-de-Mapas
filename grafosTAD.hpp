#pragma once
#include <string>
#include <iostream>
#include <vector>


//Estrutura que representa um país -> nome e cor
//É possível colocar mais informações sobre
typedef struct Country
{
	std::string name = "Vazio";

	int color = -1;

};


// Busca em largura que retorna o menor caminho entre dois pontos -> iterativo
int bfsMenor(int origem, int destino, const std::vector<std::vector<std::pair<Country, int >>>& adj);

//Busca em profundidade que retorna o menor caminho entre dois pontos -> recursivo
int dfsMenor(int origem, int destino, const std::vector<std::vector<std::pair<Country, int >>>& adj);
