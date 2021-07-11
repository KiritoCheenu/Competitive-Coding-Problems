#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

static int dp[101][1001]; //n=101,cap=1001 constraints will be given in the question

int knapsack(int length[], int prices[], int cap, int n)
{
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < cap + 1; j++)
        {
            if (length[i - 1] <= j)
                dp[i][j] = max(prices[i - 1] + dp[i][j - length[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][cap];
}
int main()
{
    int cap = 8;
    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int length[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = 8;

    cout << knapsack(length, prices, cap, n) << endl;

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < cap + 1; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}