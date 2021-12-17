#include <bits/stdc++.h>
using namespace std;
int main()
{
    //code
    int n, k;
    cin >> n;
    vector<int> arr(n), ans;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> k;
    deque<int> list;

    int j(0), i(0);
    while (j < arr.size())
    {
        if (arr[j] < 0)
            list.push_back(arr[j]);

        if (j - i + 1 < k)
        {
            j++;
            continue;
        }
        else if (j - i + 1 == k)
        {
            if (!list.empty())
                ans.push_back(list.front());
            else
                ans.push_back(0);

            if (arr[i] < 0)
                list.pop_front();
            i++;
        }
        j++;
    }
    for (int item : ans)
        cout << item << " ";
    cout << endl;
    return 0;
}