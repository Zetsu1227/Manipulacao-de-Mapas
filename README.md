# 🗺️ Manipulacao-de-Mapas  

**-> Foco Principal**: Utilizar os conhecimentos de grafos em um programa que manipule-os por meio dos algoritmos: BFS, DFS, Dijkstra e Prim.

-------------------------------------

## 💡 Introdução

O objetivo deste projeto é colocar em prática as principais lógicas que aprendi em Projeto e Análise de Algoritmos 1 na UFRGS. Assim, pensei em manipular mapas 
de países/cidades para criar caminhos, seja para se deslocar de forma ótima ou eficiente.

-------------------------------------
## 💻 Implementação  

- `grafosTAD.cpp` - arquivo que contém o código dos algoritmos de percorrer grafos.
- `grafosTAD.hpp` - arquivo que contém o protótipos das funções presentes em grafosTAD.cpp.

- `arquivosTAD.cpp` - arquivo que contém o código de carregamento do grafo no arquivo .txt e a função de organização da main.
- `arquivosTAD.hpp` - arquivo que contém o protótipos das funções presentes em arquivosTAD.cpp.
  
- `main.c` - arquivo principal, responsável por chamar todas as funções utilizadas no código.

-------------------------------------

-------------------------------------

## 🧠 Complexidades de Tempo

Levando em consideração um Grafo G simples, não-orientado e valorado, com V vértices e E arestas, implementado com lista de adjacência.

**-> BFS**:  
- Base: Nesse tipo de caminhamento, cada vértice é inserido na fila e percorrido por seus vizinhos. Portanto, sua complexidade fica O(V + E).
- Modificado: Nesse programa, o BFS é utilizado como uma alternativa para se encontrar caminhos de uma origem para um destino. Sabendo disso, eu utilizei uma lógica a mais para se encontrar o valor total desse caminho, como o caminho tem no máximo V vértices, tive que utilizar um vetor para percorrer a lista de adjacência de cada vértice para encontrar o vértice "pai" dele e somar seu peso; consequentemente, ficando com O(V^2).
  
 **-> DFS**:  
 - Base: Utilizei um DFS recursivo, ele marca cada vértice que percorre como visitado e executa chamadas de cada um de seus vizinhos; portanto, fica com custo de O(V + E).
 - Modificado: No programa, apenas coloquei uma verificação caso o DFS encontre o destino, se sim, ele retorna os pesos do caminho, se não, ele retorna -1. Nesse contexto, a complexidade do DFS não mudou, continua O(V + E).
   
**-> Dijkstra**:  
  - Base: Inicializa-se um vetor para percorrer todos os vértices, cada vértice pode se removido de uma min-heap pelo menos uma vez com sua menor distância definitiva, com isso, para cada aresta verifica se a nova opcao é maior do que a antiga mais o peso, caso a aresta seja relaxada com sucesso, insere dá um push na heap. Sabendo disso, fica com custo aproximado de O(E.logV).

**-> Prim**:  
  - Base: a cada iteração, o vértice de menor chave é escolhido por meio de uma busca linear em todos os vértices ainda não visitados. Como essa operação é realizada uma vez para cada vértice, esse custo é dominado pela seleção linear do mínimo, fazendo com que o tempo final do algoritmo seja O(V^2). Como não utilizei min-heap nesse algoritmo, sua complexidade piorou bastante em comparação com a versão otimizada.
    
-------------------------------------

## 📉 Resultados

Mapas são naturalmente modelados como grafos. Com este projeto: vértices podem ser moldados para serem países e arestas representarem suas fronteiras/conexões com pesos como distâncias/custos. Essa modelagem permite transformar um problema geográfico real em um problema computacional definido; desse modo, isso viabiliza a aplicação direta dos algoritmos.    
  
Com essas informações, é possível perceber que a utilização de grafos na modelagem de mapas mostra-se essencial para traduzir problemas reais em soluções computacionais eficientes. Ao aplicar algoritmos clássicos como BFS, DFS, Dijkstra e Prim, o projeto evidencia na prática os conceitos fundamentais estudados em Projeto e Análise de Algoritmos I, especialmente no que diz respeito à escolha correta de algoritmos, estruturas de dados apropriadas e análise rigorosa de complexidade.


-------------------------------------



