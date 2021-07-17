#include <bits/stdc++.h>
using namespace std;

static int dp[1001][1001];

bool isPalindrome(string String, int i, int j)
{
    while (i < j)
    {
        if (String[i] != String[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int mcm(string s, int i, int j)
{
    if (i >= j)
        return 0;
    if (isPalindrome(s, i, j))
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int mn = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int left, right;
        if (dp[i][k] != -1)
            left = dp[i][k];
        else
        {
            left = mcm(s, i, k);
            dp[i][k] = left;
        }
        if (dp[k + 1][j] != -1)
            right = dp[k + 1][j];
        else
        {
            right = mcm(s, k + 1, j);
            dp[k + 1][j] = left;
        }
        int temp = left + right + 1;
        mn = min(mn, temp);
    }
    dp[i][j] = mn;
    return dp[i][j];
}

int main()
{
    string s = "nitin";
    memset(dp, -1, sizeof(dp));
    int i = 0;
    int j = s.length() - 1;
    cout << mcm(s, i, j);
}