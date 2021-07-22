#include <bits/stdc++.h>
using namespace std;

static int dp[1001][1001];

int mcm(int arr[], int i, int j)
{
    if (i >= j)
        return 0;
    int mn = INT_MAX;
    if (dp[i][j] != -1)
        return dp[i][j];
    for (int k = i; k < j; k++)
    {
        int temp = mcm(arr, i, k) + mcm(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        mn = min(mn, temp);
    }
    dp[i][j] = mn;
    return dp[i][j];
}

int main()
{
    int arr[] = {1, 2, 3, 4, 3};
    memset(dp, -1, sizeof(dp));
    int i = 1;
    int j = sizeof(arr) / sizeof(arr[0]) - 1;
    cout << mcm(arr, i, j);
}