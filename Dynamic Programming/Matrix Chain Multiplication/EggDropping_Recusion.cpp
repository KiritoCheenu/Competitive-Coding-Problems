#include <bits/stdc++.h>
using namespace std;
int solve(int e, int f)
{
    if (f == 0 || f == 1)
        return f;
    if (e == 1)
        return f;
    int ans = INT_MAX - 1;
    for (int k = 1; k <= f; k++)
    {
        int tempans = 1 + max(solve(e - 1, k - 1), solve(e, f - k));
        ans = min(ans, tempans);
    }
    return ans;
}

int main()
{
    int e=2;
    int f=4;
    cout << solve(e, f);
}