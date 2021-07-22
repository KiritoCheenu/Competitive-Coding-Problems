// Evaluate Expression to True Boolean Parenthesization Recursive
#include <bits/stdc++.h>
using namespace std;

int parenthesis_count(string s, int i, int j, int isTrue)
{
    if (i > j)
        return false;
    if (i == j)
    {
        if (isTrue == 1)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }
    int ans = 0;
    for (int k = i + 1; k <= j - 1; k = k + 2)
    {
        int leftF, leftT, rightT, rightF;

        leftT = parenthesis_count(s, i, k - 1, 1);
        rightT = parenthesis_count(s, k + 1, j, 1);
        leftF = parenthesis_count(s, i, k - 1, 0);
        rightF = parenthesis_count(s, k + 1, j, 0);
        if (s[k] == '&')
        {
            if (isTrue == 1)
                ans += leftT * rightT;
            else
                ans += leftF * rightF + leftT * rightF + leftF * rightT;
        }
        else if (s[k] == '|')
        {
            if (isTrue == 1)
                ans += leftT * rightT + leftT * rightF + leftF * rightT;
            else
                ans = ans + leftF * rightF;
        }
        else if (s[k] == '^')
        {
            if (isTrue == 1)
                ans = ans + leftF * rightT + leftT * rightF;
            else
                ans = ans + leftT * rightT + leftF * rightF;
        }
        }
    return ans;
}
int main()
{
    string symbols = "TTFT";
    string operators = "|&^";
    string s;
    int j = 0;
    for (int i = 0; i < symbols.length(); i++)
    {
        s.push_back(symbols[i]);
        if (j < operators.length())
            s.push_back(operators[j++]);
    }
    int n = s.length();
    cout << parenthesis_count(s, 0, n - 1, 1);
    return 0;
}
