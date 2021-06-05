#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    int zero = 0, one = 0, two = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
            zero++;
        else if (a[i] == 1)
            one++;
        else if (a[i] == 2)
            two++;
    }
    for (int j = 0; j < zero; j++)
    {
        a[j] = 0;
    }
    for (int j = 0; j < one; j++)
    {
        a[j] = 1;
    }
    for (int j = 0; j < two; j++)
    {
        a[j] = 2;
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}