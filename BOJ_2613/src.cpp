#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a, psum;
vector<vector<int>> dp;
vector<vector<int>> parent;
int rec(int idx, int groups)
{
    if (groups > m)
        return INT_MAX;

    if (idx == n)
    {
        if (groups == m)
            return 0;
        else if (groups < m)
            return INT_MAX;
    }

    int &ret = dp[idx][groups];
    if (ret != -1)
        return ret;

    ret = INT_MAX;
    for (int i = idx + 1; i <= n; i++)
    {
        int cost = psum[i] - psum[idx];
        int maxCost = max(cost, rec(i, groups + 1));
        if (ret > maxCost) // ret = min(ret, maxCost);
        {
            ret = maxCost;
            parent[idx][groups] = i * 10000 + groups + 1;
        }
    }
    return ret;
}

int main()
{
    cin >> n >> m;
    a = vector<int>(n + 1, 0);
    psum = vector<int>(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }

    dp = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));
    parent = vector<vector<int>>(n + 1, vector<int>(m + 1, -1));

    int ans = rec(0, 0);
    cout << ans << "\n";

    vector<pair<int, int>> back = {{0, 0}};
    int i = 0, j = 0;
    while (1)
    {
        int ni = parent[i][j] / 10000;
        int nj = parent[i][j] % 10000;

        if (nj == -1)
            break;
        back.push_back({ni, nj}); // {idx, groups}

        i = ni;
        j = nj;
    }
    /*
        0 0
        4 1
        6 2
        8 3
    */
    // for (int i = 0; i < back.size(); i++)
    //     cout << back[i].first << ' ' << back[i].second << '\n';

    for (int i = 1; i < back.size(); i++)
        cout << back[i].first - back[i - 1].first << ' ';
}