#include "grafosTAD.hpp"


//implementado com logica de bfs
bool ehConexo(int edges, const std::vector<std::vector<std::pair<int, int>>>& adj)
{
    std::vector<bool> visited(edges, false);
    std::queue<int> q;

    q.push(0);  // começa do vertice 0
    visited[0] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // percorre apenas os vizinhos, ignorando o peso
        for (const auto& [v, peso] : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    // se nodo nao visitado -> grafo desconexo
    for (bool v : visited)
        if (!v) 
            return false;

    return true;
}

int bfsMenor(int origem, int destino, const std::vector<std::vector<std::pair<int, int>>>& adj)
{

    int tam = adj.size();

    std::vector<bool> visitado(tam, false);
    std::vector<int> pai(tam, -1);

    std::queue<int> q;
    q.push(origem);
    visitado[origem] = true;

    while (!q.empty())
    {
        int atual = q.front();
        q.pop();


        if (atual == destino)
            break;

            for (const auto& v : adj[atual])
            {
                if (!visitado[v.first])
                {
                    visitado[v.first] = true;
                    pai[v.first] = atual;
                    q.push(v.first);
                }
            }
    }

    if(!visitado[destino])
        return -1;

    std::vector<int> cam;

    // reconstrucao do caminho
    for (int v = destino; v != -1; v = pai[v])
        cam.push_back(v);

    std::reverse(cam.begin(), cam.end());

    int soma = 0;

    for (int i = 0; i + 1 < cam.size(); i++) 
    {
        int u = cam[i];
        int v = cam[i + 1];

        for (const auto& x : adj[u]) 
        {
            if (x.first == v) 
            {
                soma += x.second;
                break;
            }
        }
    }

    return soma;

}

int dfsMenor(int origem, int destino, const std::vector<std::vector<std::pair<int, int>>>& adj, std::vector<bool>& visitado)
{
    if (origem == destino)
        return 0;

    visitado[origem] = true;

    for (auto [v, peso] : adj[origem]) 
    {
        if (!visitado[v]) 
        {
            int custo = dfsMenor(v, destino, adj, visitado);
        
            if (custo != -1)
                return custo + peso;
            
        }
    }

    return -1; // não encontrou caminho 

}

std::vector<int> dijkstra(int origem, const std::vector<std::vector<std::pair<int, int>>>& adj)
{
    int tam = adj.size();
    std::vector<int> dist(tam, INT_MAX);  // Inicializa com infinito

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> heapMin;

    // trivial
    dist[origem] = 0;
    heapMin.emplace(0, origem);

    while (!heapMin.empty())
    {
        // Pega nodo com a menor dist acumulada
        int u = heapMin.top().second;
        int d = heapMin.top().first;
        heapMin.pop();

        // dist menor que a encontrada
        if (d > dist[u])
            continue;

        // Verifica os vizinhos
        for (const std::pair<int, int>& p : adj[u])
        {
            int v = p.first;  //vizinho
            int peso = p.second;  // valor

            // Verifica se o caminho ate v eh menor
            if (dist[u] + peso < dist[v])
            {
                dist[v] = dist[u] + peso;
                heapMin.emplace(dist[v], v);  // coloca na heap
            }
        }
    }

    return dist;
}


int prim(const std::vector<std::vector<std::pair<int, int>>>& adj, std::vector<int>& agm)
{
    int tam = adj.size();

    //inicializa e reestrutura pra confirmar o tamanho
    agm.resize(tam, -1);

    std::vector<int> chave(tam, INT_MAX);
    std::vector<bool> visited(tam, false);

    int somaTotal = 0;

    //primeiro na arvore
    chave[0] = 0;

 
    for (int i = 0; i < tam; i++)
    {
        int u = chaveMin(chave, visited);

        //caso seja desconexo
        if (u == -1)
            break;

        visited[u] = true;

        // soma a chave do vertice escolhido (exceto o primeiro)
        somaTotal += chave[u];

        for (const auto& v : adj[u])
        {
            if (!visited[v.first] && (v.second < chave[v.first]))
            {
                chave[v.first] = v.second;
                agm[v.first] = u;
            }
        }
    }

    return somaTotal;
}


int chaveMin(std::vector<int>& chave, std::vector<bool>& visited)
{
    //inicializa as opcoes
    int min = INT_MAX;
    int minIndex = -1;

    for (int v = 0; v < chave.size(); v++)
    {
        if (!visited[v] && chave[v] < min)
        {
            min = chave[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void printAGM(const std::vector<int>& agm)
{
    int tam = agm.size();

    std::unordered_multimap<int, int> mapa;

    int raiz = -1;

    int i = 0; //auxiliar

    //encontra a raiz
    for (int i = 0; i < tam; i++)
    {
        if (i == agm[i])
            raiz = i;
        else
        {
            mapa.insert({ agm[i], i });
        }
    }

    auxPrint(raiz, mapa, 1);


    
}

void auxPrint(int origem, const std::unordered_multimap<int, int>& mapa, int espacamento)
{
    
    for (int i = 0; i < espacamento; i++)
        std::cout << "=";

    std::cout << " " << origem << "\n";

    auto range = mapa.equal_range(origem);

    //it->second eh o filho da origem
    for (auto it = range.first; it != range.second; ++it)
        auxPrint(it->second, mapa, espacamento + 1);

}
