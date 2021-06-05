#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    int n = sizeof(a) / sizeof(a[0]);
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            j++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}