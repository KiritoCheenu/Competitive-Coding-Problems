#include <bits/stdc++.h>
using namespace std;

#define vvi vector<vector<int>>
#define rep(i, k, n) for (int i = k; i < n; i++)
#define out cout <<
#define in cin >>

class KruskalsAlgorithm
{
    int V;

public:
    vector<int> parent;
    KruskalsAlgorithm(int v)
    {
        V = v;
        parent.resize(v);
    }
    int find(int i)
    {
        while (parent[i] != i)
            i = parent[i];
        return i;
    }
    void union1(int i, int j)
    {
        int a = find(i);
        int b = find(j);
        parent[a] = b;
    }
    void kruskalMST(vvi cost)
    {
        int mincost = 0;
        for (int i = 0; i < V; i++)
            parent[i] = i;
        int edge_count = 0;
        while (edge_count < V - 1)
        {
            int min = INT_MAX, a = -1, b = -1;
            for (int i = 0; i < V; i++)
            {
                for (int j = 0; j < V; j++)
                {
                    if (find(i) != find(j) && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
            union1(a, b);
            out a << " - " << b << endl;
            mincost += min;
            edge_count++;
        }
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

    rep(i, 0, v)
    {
        rep(j, 0, v)
            graph[i][j] = INT_MAX;
    }
    rep(i, 0, n)
    {
        int x, y, w;
        in x >> y >> w;
        graph[x][y] = w;
    }
    KruskalsAlgorithm kruskal = KruskalsAlgorithm(v);
    kruskal.kruskalMST(graph);
    return 0;
}
