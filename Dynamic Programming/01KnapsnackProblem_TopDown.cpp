#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

static int dp[101][1001]; //n=101,cap=1001 constraints will be given in the question

int knapsnack(int wt[], int val[], int cap, int n)
{
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < cap + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][cap - wt[i - 1]], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][cap];
}
int main()
{
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