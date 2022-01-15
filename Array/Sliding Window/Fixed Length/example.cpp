#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string s = "bacdaabaa", p = "aab";
    long lenS, lenP, sumS = 0, sumP = 0;
    string temp;
    lenS = s.size();
    lenP = p.size();
    for (int i = 0; i < lenP; i++)
    {
        sumP = sumP + (int)p[i] - 96;
    }
    int i = 0, j = 0;
    while (j < lenS)
    {
        sumS += ((int)s[j]) - 96;
        temp += s[j];
        if (sumS < sumP)
        {
            j++;
        }
        else if (sumS == sumP)
        {
            cout << temp << " " << j - lenP + 1 << endl;
            sumS -= (temp[0] - 96);
            temp.erase(0, 1);
            j++;
        }
        else
        {
            sumS -= (temp[0] - 96);
            temp.erase(0, 1);
            j++;
        }
    }
    if (i == 0)
        cout << -1 << endl;
    return 0;
}