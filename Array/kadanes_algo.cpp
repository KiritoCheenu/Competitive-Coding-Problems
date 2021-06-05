#include <bits/stdc++.h>
using namespace std;

int max(int a, int b)
{
    return a < b ? b : a;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int maxSubArr = arr[0];
    int current = arr[0];

    for (int i = 1; i < n; i++)
    {
        current = max(arr[i], current + arr[i]);
        maxSubArr = max(maxSubArr, current);
    }

    cout << maxSubArr;
}