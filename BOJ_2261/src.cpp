#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> a;

int square(int x)
{
    return x * x;
}

int dist(pair<int, int> A, pair<int, int> B)
{
    return square(A.first - B.first) + square(A.second - B.second);
}

int divideConquer(int low, int high)
{
    if (low == high)
        return INT_MAX;

    if (low + 1 >= high)
        return dist(a[low], a[high]);

    int ret = INT_MAX;
    int mid = (low + high) / 2;
    int ls = divideConquer(low, mid);
    int rs = divideConquer(mid + 1, high);
    ret = min(ls, rs);

    vector<pair<int, int>> innerSet;
    for (int i = mid; i >= low; i--)
    {
        if (ret <= square(a[mid + 1].first - a[i].first))
            break;
        innerSet.push_back(make_pair(a[i].second, a[i].first));
    }
    for (int i = mid + 1; i <= high; i++)
    {
        if (ret <= square(a[mid].first - a[i].first))
            break;
        innerSet.push_back(make_pair(a[i].second, a[i].first));
    }

    sort(innerSet.begin(), innerSet.end());
    for (int i = 0; i < innerSet.size(); i++)
    {
        for (int j = i + 1; j < innerSet.size(); j++)
        {
            if (ret <= square(innerSet[i].first - innerSet[j].first))
                break;

            ret = min(ret, dist(innerSet[i], innerSet[j]));
        }
    }
    return ret;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a.push_back(make_pair(x, y));
    }
    sort(a.begin(), a.end());
    int ans = divideConquer(0, n - 1);
    cout << ans << "\n";
}
