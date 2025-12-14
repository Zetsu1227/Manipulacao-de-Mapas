#include "grafosTAD.hpp"


int bfsMenor(int origem, int destino, const std::vector<std::vector<std::pair<int, int>>>& adj, std::vector<int>& ids)
{

    int tam = adj.size();

    std::vector<bool> visitado(tam, false);
    std::vector<int> pai(tam, -1);



    std::queue<int> q;
    q.push(origem);
    visitado[origem] = true;

    bool achou = false;

    while (!q.empty() && !achou)
    {
        int atual = q.front();
        q.pop();

        ids.push_back(atual);

        if (atual == destino)
            achou = true;

        if(!achou)
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

    if(!achou)
        return -1;

    // reconstrução do caminho
    for (int v = destino; v != -1; v = pai[v])
        ids.push_back(v);

    std::reverse(ids.begin(), ids.end());

    int soma = 0;

    for (int i = 0; i + 1 < ids.size(); i++) 
    {
        int u = ids[i];
        int v = ids[i + 1];

        for (auto x : adj[u]) 
        {
            if (x.first == v) 
            {
                soma += x.second;
                std::cout  << " -> " << x.first;
                break;
            }
        }
    }

    return soma;

}

int dfsMenor(int origem, int destino, const std::vector<std::vector<std::pair<int, int>>>& adj, std::vector<int>& ids)
{
    return 0;
}
