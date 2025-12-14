#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

std::unordered_map<std::string, int> carregarGrafo(const std::string& caminho, std::vector<std::vector<std::pair<int, int>>>& adj);