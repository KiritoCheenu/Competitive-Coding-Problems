#include <bits/stdc++.h>
#define rep(i, k, n) for (int i = k; i < n; i++)
#define out cout <<
#define in cin >>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

    void topologicalSortUtil(int v, bool visited[],stack<int> &Stack);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void topologicalSort();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::topologicalSortUtil(int v, bool visited[],
                                stack<int> &Stack)
{
    visited[v] = true;
    list<int>::iterator i;

    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);

    Stack.push(v);
}

void Graph::topologicalSort()
{
    stack<int> Stack;
    bool *visited = new bool[V];
    rep(i, 0, V)
        visited[i] = false;

    rep(i, 0, V) if (visited[i] == false)
        topologicalSortUtil(i, visited, Stack);

    while (Stack.empty() == false)
    {
        out Stack.top() << " ";
        Stack.pop();
    }
}

int main()
{
    int n;
    in n;
    Graph g(n);

    rep(i, 0, n)
    {
        int u, v;
        in u >> v;
        g.addEdge(u, v);
    }

    g.topologicalSort();
}