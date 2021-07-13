#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

static int dp[101][1001]; //n=101,cap=1001 constraints will be given in the question

int knapsack(int coin[], int cap, int n)
{
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 1;
    for (int j = 1; j < cap + 1; j++)
        dp[0][j] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < cap + 1; j++)
        {
            if (coin[i - 1] <= j)
            {
                dp[i][j] = dp[i][j - coin[i - 1]] + dp[i - 1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][cap];
}
int main()
{
    int cap = 5;
    int coin[] = {1, 2, 5};
    int n = 3;

    cout << knapsack(coin, cap, n) << endl;

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < cap + 1; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}