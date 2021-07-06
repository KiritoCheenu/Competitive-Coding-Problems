#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define pb push_back
#define setBits(x) builtin_popcount(x)

const int N = 1e5 + 2, MOD = 1e9 + 7;

vi adj[N];

int main()
{
    int n, m;
    cin >> n >> m;
    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    //c++14
    rep(i, 1, n + 1)
    {
        cout << i << " -> ";
        for (int x : adj[i])
            cout << x << " ";
        cout << endl;
    }
    /*
    c++ 11
    rep(i, 1, n + 1)
    {
        cout << i << " -> ";
        vi ::iterator it;
        for (it = adj[i].begin(); it != adj[i].end(); it++)
            cout << *it << " ";
        cout << endl;
    }
    */
}