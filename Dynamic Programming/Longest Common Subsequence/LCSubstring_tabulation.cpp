#include <bits/stdc++.h>
using namespace std;

int lcs(string x, string y, int n, int m)
{
    int dp[n + 1][m + 1];
    int result = 0;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 0;
            result = max(result, dp[i][j]);
        }
    }
    // for (int i = 0; i < n + 1; i++)
    // {
    //     for (int j = 0; j < m + 1; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    return result;
}

int main()
{
    string x = "AGGTAB";
    string y = "GTXAYB";
    int n = x.length();
    int m = y.length();
    cout << lcs(x, y, n, m);
}