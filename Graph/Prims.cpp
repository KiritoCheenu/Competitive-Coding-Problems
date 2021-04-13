#include <bits/stdc++.h>
using namespace std;
#define vvi vector<vector<int>>
#define rep(i, k, n) for (int i = k; i < n; i++)
#define out cout <<
#define in cin >>
class PrimsAlgorithm
{

public:
    int V;
    PrimsAlgorithm(int v)
    {
        V = v;
    }

    int minKey(int key[], bool mstSet[])
    {
        int min = INT_MAX, min_index;
        rep(v, 0, V) if (mstSet[v] == false && key[v] < min)
            min = key[v],
            min_index = v;
        return min_index;
    }
    void printMST(int parent[], vvi graph)
    {
        rep(i, 1, V)
                out parent[i]
            << " - " << i << "\n";
    }
    void primMST(vvi graph)
    {
        int parent[V];
        int key[V];
        bool mstSet[V];
        rep(i, 0, V)
            key[i] = INT_MAX,
            mstSet[i] = false;
        key[0] = 0;
        parent[0] = -1;
        rep(count, 0, V - 1)
        {
            int u = minKey(key, mstSet);
            mstSet[u] = true;
            for (int v = 0; v < V; v++)
                if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                    parent[v] = u, key[v] = graph[u][v];
        }
        printMST(parent, graph);
    }
};
int main()
{
    int v, n;
    in v >> n;

    vector<vector<int>> graph(v);
    rep(i, 0, v)
    {
        graph[i] = vector<int>(v);
    }
    rep(i, 0, n)
    {

        int x, y, w;
        in x >> y >> w;
        graph[x][y] = w;
    }
    PrimsAlgorithm prims = PrimsAlgorithm(v);
    prims.primMST(graph);
    return 0;
}
