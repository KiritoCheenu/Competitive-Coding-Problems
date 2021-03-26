// Kadane's Algorithm

#include <iostream>
using namespace std;

int maxSubArraySum(int a[], int size);

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    maxSubArraySum(arr, n);
    cout << maxSubArraySum(arr, n);
    return 0;
}

int maxSubArraySum(int a[], int size)
{
    int max = 0, maxSubArray = 0;
    for (int i = 0; i < size; i++)
    {
        maxSubArray += a[i];
        if (maxSubArray < 0)
            maxSubArray = 0;
        else if (max < maxSubArray)
            max = maxSubArray;
    }
    return max;
}