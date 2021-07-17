#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string String, int i, int j)
{
    while (i < j)
    {
        if (String[i] != String[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int mcm(string s, int i, int j)
{
    if (i >= j)
        return 0;
    if (isPalindrome(s, i, j))
        return 0;
    int mn = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = mcm(s, i, k) + mcm(s, k + 1, j) + 1;
        mn = min(mn, temp);
    }
    return mn;
}

int main()
{
    string s = "nitik";
    int i = 0;
    int j = s.length() - 1;
    cout << mcm(s, i, j);
}