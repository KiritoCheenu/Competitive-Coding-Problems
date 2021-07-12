#include <bits/stdc++.h>
using namespace std;

int dp[101][101];

int lcs(string x, string y, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];
    if (x[n - 1] == y[m - 1])
        dp[n][m] = 1 + lcs(x, y, n - 1, m - 1);
    else
        dp[n][m] = max(lcs(x, y, n - 1, m), lcs(x, y, n, m - 1));
    return dp[n][m];
}

int main()
{
    memset(dp, -1, sizeof(dp[0][0]) * 101 * 101);
    string x = "AGGTAB";
    string y = "GXTXAYB";
    int n = x.length();
    int m = y.length();

    cout << lcs(x, y, n, m);
}