#include <bits/stdc++.h>
using namespace std;

string s, t;
vector<vector<int>> dp;
// https://en.wikipedia.org/wiki/Levenshtein_distance
int levenshtein(int a, int b)
{
    if (a == s.size())
        return t.size() - b;

    if (b == t.size())
        return s.size() - a;

    int &ret = dp[a][b];
    if (ret != -1)
        return ret;

    if (s[a] == t[b])
        ret = levenshtein(a + 1, b + 1);
    else
    {
        int del = levenshtein(a + 1, b) + 1;     // delete
        int ins = levenshtein(a, b + 1) + 1;     // insert
        int rep = levenshtein(a + 1, b + 1) + 1; // replace
        ret = min({del, ins, rep});
    }

    return ret;
}

int main()
{
    cin >> s >> t;
    dp = vector<vector<int>>(1001, vector<int>(1001, -1));
    int ans = levenshtein(0, 0);
    cout << ans << "\n";
}