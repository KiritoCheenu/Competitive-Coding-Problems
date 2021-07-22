#include <bits/stdc++.h>
using namespace std;
int dp[101][101];
int solve(int e, int f)
{
    if (f == 0 || f == 1)
        return f;
    if (e == 1)
        return f;
    if (dp[e][f] != -1)
        return dp[e][f];
    int ans = INT_MAX - 1;
    for (int k = 1; k <= f; k++)
    {
        if (dp[e - 1][k - 1] == -1)
            dp[e - 1][k - 1] = solve(e - 1, k - 1);
        if (dp[e][f - k] == -1)
            dp[e][f - k] = solve(e, f - k);
        int tempans = 1 + max(dp[e - 1][k - 1], dp[e][f - k]);
        ans = min(ans, tempans);
    }
    dp[e][f] = ans;
    return ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int e = 2;
    int f = 4;
    cout << solve(e, f);
}