#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

static int dp[101][1001]; //n=101,cap=1001 constraints will be given in the question

int knapsack(int wt[], int val[], int cap, int n)
{
    if (n == 0 || cap == 0)
        return 0;
    if (dp[n][cap] != -1)
        return dp[n][cap];
    if (wt[n - 1] <= cap)
        dp[n][cap] = max(val[n - 1] + knapsack(wt, val, cap - wt[n - 1], n), knapsack(wt, val, cap, n - 1));
    else
        dp[n][cap] = knapsack(wt, val, cap, n - 1);

    // cout<<dp[n][cap]<<" ";
    return dp[n][cap];
}
int main()
{
    memset(dp, -1, sizeof(dp[0][0]) * 101 * 1001);
    int cap = 100;
    int val[] = {10, 30, 20};
    int wt[] = {5, 10, 15};
    int n = 4;

    cout << knapsack(wt, val, cap, n) << endl;

    // for (int i = 0; i < n + 1; i++)
    // {
    //     for (int j = 0; j < cap + 1; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
}