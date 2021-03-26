#include <bits/stdc++.h>
using namespace std;
bool pairsum(int arr[], int n, int s)
{
    int low = 0, high = n - 1;
    while (low < high)
    {
        if (arr[low] + arr[high] == s)
            return true;
        else if (arr[low] + arr[high] < s)
            low++;
        else
            high++;
    }
    return false;
}
int main()
{
    int n, s;
    cin >> n >> s;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    cout << pairsum(arr, n, s);
}