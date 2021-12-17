#include <bits/stdc++.h>
using namespace std;
int countAnagram(string p, string s)
{

    int n = s.length(), m = p.length();
    if (m > n)
        return 0;

    vector<int> pv(26, 0), sv(26, 0);

    for (int i = 0; i < m; i++)
        pv[p[i] - 'a']++;

    int i = 0, j = 0;
    int ans = 0;

    while (j < s.length())
    {

        sv[s[j] - 'a']++;

        if ((j - i + 1) < m)
            j++;

        else if ((j - i + 1) == m)
        {

            if (pv == sv)
                ans++;

            sv[s[i] - 'a']--;

            i++;
            j++;
        }
    }
    return ans;
}
int main(){
    string s,p;

    cin>>s>>p;
    cout<<countAnagram(p,s);

}