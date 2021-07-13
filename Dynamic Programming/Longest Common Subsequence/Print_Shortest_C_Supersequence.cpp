#include <bits/stdc++.h>
using namespace std;

string lcs(string x, string y, int n, int m)
{
    int dp[n + 1][m + 1];
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
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string s = "";
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            s.push_back(x[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                s.push_back(x[i - 1]);
                i--;
            }
            else
            {
                s.push_back(y[j - 1]);
                j--;
            }
        }
    }
    while (i > 0)
    {
        s.push_back(x[i - 1]);
        i--;
    }
    while (j > 0)
    {
        s.push_back(y[j - 1]);
        j--;
    }
    // for (int i = 0; i < n + 1; i++)
    // {
    //     for (int j = 0; j < m + 1; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    // cout << m + n - dp[n][m] << endl;

    return s;
}

int main()
{
    string x = "HELLO";
    string y = "GEEK";
    int n = x.length();
    int m = y.length();
    // int l = lcs(x, y, n, m);
    cout << lcs(x, y, n, m);
}