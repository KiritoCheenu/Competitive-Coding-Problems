#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

static int dp[101][1001]; //n=101,sum=1001 constraints will be given in the question

int subsetsum(int arr[], int sum, int n)
{
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 1;
    for (int j = 1; j < sum + 1; j++)
        dp[0][j] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {

            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}
int main()
{
    int arr[] = {1, 1, 2, 3};
    int targetsum = 1;
    int n = 4;
    int sum = 0;
    for (int x : arr)
        sum += x;
    int s1 = abs(sum - targetsum);
    if (sum < targetsum)
        cout << 0;
    else if (s1 % 2 == 1)
        cout << 0;
    else
        cout << subsetsum(arr, s1 / 2, n);
    cout << endl;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}