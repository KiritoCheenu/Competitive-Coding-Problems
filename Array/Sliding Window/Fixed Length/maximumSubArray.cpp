#include <bits/stdc++.h>
using namespace std;

void pop_front(vector<int> &v)
{
    if (v.size() > 0) {
        v.erase(v.begin());
    }
}
vector<int> maximumSumArray(vector<int> arr, int n, int k)
{

    vector<int> l(n, 0), ans;

    int i = 0, j = 0;

    while (j < n)
    {
        //calculations
        while (l.size() > 0 && l.back() < arr[j])
        {
            l.pop_back();
        }
        l.push_back(arr[j]);
        if ((j - i + 1) < k)
            j++;

        else if ((j - i + 1) == k)
        {
            //Calculations for removal
            ans.push_back(l.front());
            //Slide the window
            if (l.front() == arr[i])
                pop_front(l);
            i++;
            j++;
        }
    }
    return ans;
}
int main()
{
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    vector<int>ans= maximumSumArray(arr, n, k);
    for(auto var : ans)
    {
        cout<<var<<endl;
    }
}