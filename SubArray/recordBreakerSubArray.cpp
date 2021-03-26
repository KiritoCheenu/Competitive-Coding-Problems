#include <bits/stdc++.h>
using namespace std;
int countRecordBreakingDays(vector<long> visitors)
{
    long recordBreaksCount = 0;
    long previousRecord = 0;
    for (int i = 0; i < visitors.size(); i++)
    {
        bool greaterThanPreviousDays = i == 0 || visitors[i] > previousRecord;
        bool greaterThanFollowingDay = i == visitors.size() - 1 || visitors[i] > visitors[i + 1];
        if (greaterThanPreviousDays && greaterThanFollowingDay)
        {
            recordBreaksCount++;
        }
        previousRecord = max(previousRecord, visitors[i]);
    }
    return recordBreaksCount;
}
int main()
{
    int n, t, k = 1;
    cin >> t;
    while (t-- > 0)
    {
        cin >> n;
        vector<long> v;
        long temp;
        for (int i = 0; i < n; i++)
        {
            cin>>temp;
            v.push_back(temp);
        }
        int ans = countRecordBreakingDays(v);

        cout << "Case #" << k++ << ": " << ans << endl;
    }
}