#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

static int dp[101][1001]; //n=101,cap=1001 constraints will be given in the question

int knapsack(int coin[], int cap, int n)
{
    for (int i = 0; i < cap + 1; i++)
        dp[0][i] = INT_MAX - 1;
    for (int i = 1; i < cap + 1; i++)
    {
        if (i % coin[0] == 0)
            dp[1][i] = i / coin[0];
        else
            dp[1][i] = INT_MAX - 1;
    }
    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 1; j < cap + 1; j++)
        {
            if (coin[i - 1] <= j)
            {
                dp[i][j] = min(1 + dp[i][j - coin[i - 1]], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][cap];
}
int main()
{
    int cap = 10;
    int coin[] = {1, 5, 3, 7, 4};
    int n = 5;

    cout << knapsack(coin, cap, n) << endl;

    // for (int i = 0; i < n + 1; i++)
    // {
    //     for (int j = 0; j < cap + 1; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
}