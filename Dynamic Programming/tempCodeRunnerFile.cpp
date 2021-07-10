int main()
{
    memset(dp, -1, sizeof(dp[0][0]) * 101 * 1001);
    int val[] = {1,3,4,5};
    int wt[] = {1,4,5,7};
    int cap = 7;
    int n = 4;

    cout << knapsnack(wt, val, cap, n)<<endl;

    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < cap+1; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}