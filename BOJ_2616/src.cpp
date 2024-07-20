#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a, psum;
vector<vector<int>> dp;

int main()
{
    cin >> n;

    a = vector<int>(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    psum = vector<int>(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        psum[i] = psum[i - 1] + a[i];
    }

    cin >> k;

    dp = vector<vector<int>>(3 + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= 3; i++)
    {
        for (int j = k; j <= n; j++)
        {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - k] + psum[j] - psum[j - k]);
        }
    }

    cout << dp[3][n] << "\n";
}