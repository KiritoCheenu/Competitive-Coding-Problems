#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

static int dp[101][1001]; //n=101,cap=1001 constraints will be given in the question

int knapsnack(int wt[], int val[], int cap, int n)
{
    if (n == 0 || cap == 0)
        return 0;
    if (dp[n][cap] != -1)
        return dp[n][cap];
    if (wt[n - 1] <= cap)
        dp[n][cap] = max(val[n - 1] + knapsnack(wt, val, cap - wt[n - 1], n - 1), knapsnack(wt, val, cap, n - 1));
    else
        dp[n][cap] = knapsnack(wt, val, cap, n - 1);

    // cout<<dp[n][cap]<<" ";
    return dp[n][cap];
}
int main()
{
    memset(dp, -1, sizeof(dp[0][0]) * 101 * 1001);
    int val[] = {1, 3, 4, 5};
    int wt[] = {1, 4, 5, 7};
    int cap = 7;
    int n = 4;

    cout << knapsnack(wt, val, cap, n) << endl;

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < cap + 1; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}