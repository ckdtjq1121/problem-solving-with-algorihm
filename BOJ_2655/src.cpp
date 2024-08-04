#include <bits/stdc++.h>
using namespace std;

int n;
struct block
{
    int idx;
    int width;
    int height;
    int weight;
    block(int x, int y, int z, int w) : idx(x), width(y), height(z), weight(w) {}

    bool operator<(struct block b)
    {
        return width > b.width; // desc
    }
};
vector<struct block> a;
vector<vector<int>> dp;
vector<vector<int>> parent;

int rec(int idx, int weight)
{

    int &ret = dp[idx][weight]; // height
    if (ret != -1)
        return ret;

    ret = 0;
    for (int i = idx + 1; i <= n; i++)
    {
        if (weight > a[i].weight)
        {
            int cand = rec(i, a[i].weight) + a[i].height;
            if (ret < cand)
            {
                ret = cand;
                parent[idx][weight] = (i) * 1e5 + a[i].weight;
            }
        }
    }

    return ret;
}

int main()
{
    cin >> n;
    a.push_back(block(0, 0, 0, 0));
    for (int i = 1; i <= n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a.push_back(block(i, x, y, z));
    }
    sort(a.begin() + 1, a.end());

    dp = vector<vector<int>>(n + 1, vector<int>(10000 + 2, -1));
    parent = dp;
    int ans = rec(0, 10000 + 1);
    // cout << ans << "\n";

    vector<pair<int, int>> back;
    int i = 0, j = 10000 + 1;
    while (1)
    {
        int ni = parent[i][j] / int(1e5);
        int nj = parent[i][j] % int(1e5);

        if (nj == -1 || ni > n)
            break;
        back.push_back({ni, nj}); // {idx, groups}

        i = ni;
        j = nj;
    }

    cout << back.size() << "\n";
    for (int i = back.size() - 1; i >= 0; i--)
    {
        int x = back[i].first;
        // int y = a[x].idx;
        // cout << x << ' ' << y << '\n';
        cout << a[x].idx << '\n';
    }
}
