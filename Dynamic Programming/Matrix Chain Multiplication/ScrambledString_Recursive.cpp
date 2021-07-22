#include <bits/stdc++.h>
using namespace std;

bool solve(string a, string b)
{
    if (a.compare(b) == 0)
        return true;
    if (a.length() <= 1)
        return false;
    int n = a.length();
    bool flag = false;
    for (int i = 1; i < n; i++)
    {
        if (solve(a.substr(0, i), b.substr(n - i, i)) && solve(a.substr(i, n - i), b.substr(0, n - i)))
            flag = true;
        if (flag || (solve(a.substr(0, i), b.substr(0, i)) && solve(a.substr(i, n - i), b.substr(i, n - i))))
            return true;
    }
    return false;
}
int main()
{
    string a = "great";
    string b = "rteag";
    if (a.length() != b.length())
        cout << false;
    else if (a.length() == 0 && b.length() == 0)
        cout<<false;
    else
        cout<<solve(a,b);
}