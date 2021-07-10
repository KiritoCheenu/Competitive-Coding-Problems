#include <bits/stdc++.h>
#include <sstream>
using namespace std;

#define V 4
#define INF 99999
#define rep(i, k, n) for (int i = k; i < n; i++)

void printMatrix(int dist[][V])
{
    rep(i, 0, V)
    {
        rep(j, 0, V)
        {
            if (dist[i][j] == INF)
                cout << "INF  ";
            else
                cout << dist[i][j] << "  ";
        }
        cout << endl;
    }
}

void FloydWarshall(int graph[][V])
{
    int dist[V][V], i, j, k;
    rep(i, 0, V)
        rep(j, 0, V)
            dist[i][j] = graph[i][j];
    rep(k, 0, V)
        rep(i, 0, V)
            rep(j, 0, V) if (dist[i][k] + dist[k][j] < dist[i][j])
                dist[i][j] = dist[i][k] + dist[k][j];
    printMatrix(dist);
}

int main()
{
    int graph[V][V];
    string temp;
    // int x;
    rep(i, 0, V)
        rep(j, 0, V)
    {
        // x = 0;
        cin >> temp;
        if (temp == "INF")
            graph[i][j] = INF;
        else
        {
            stringstream s(temp);
            s >> graph[i][j];
            // graph[i][j] = x;
        }
    }

    FloydWarshall(graph);
    return 0;
}
