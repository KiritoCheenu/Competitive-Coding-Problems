#include <bits/stdc++.h>
using namespace std;

int maximumSumSubarray(int K, vector<int> &Arr, int N)
{
    // code here
    int i = 0, j = 0, mx = 0, sum = 0;

    while (j < Arr.size())
    {
        sum += Arr[j];
        if (j - i + 1 < K)
        {
            j++;
        }
        else if (j - i + 1 == K)
        {
            mx = max(sum, mx);
            sum = sum - Arr[i];
            i++;
            j++;
        }
    }
    return mx;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        arr[i]=temp;
    }
    cout<<maximumSumSubarray(k,arr,n);
}