#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

static int dp[101][1001]; //n=101,sum=1001 constraints will be given in the question

int subsetsum(int arr[], int sum, int n)
{
    if (sum == 0)
    {
        dp[n][sum] = 1;
        return 1;
    }
    if (n == 0)
    {
        dp[n][sum] = 0;
        return 0;
    }
    if (dp[n][sum] != -1)
        return dp[n][sum];
    if (arr[n - 1] <= sum)
        dp[n][sum] = subsetsum(arr, sum - arr[n - 1], n - 1) || subsetsum(arr, sum, n - 1);
    else
        dp[n][sum] = subsetsum(arr, sum, n - 1);

    // cout<<dp[n][sum]<<" ";
    return dp[n][sum];
}
int main()
{
    memset(dp, -1, sizeof(dp[0][0]) * 101 * 1001);

    int arr[] = {1, 5, 3, 7, 4};
    int sum = 12;
    int n = 5;

    cout << subsetsum(arr, sum, n) << endl;

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}