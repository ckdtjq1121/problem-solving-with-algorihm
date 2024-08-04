#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        ret ^= a[i];
    }
    // cout << ret << "\n";
    int cnt = 0;
    if (ret)
    {

        for (int i = 0; i < n; i++)
        {
            int tmp = ret ^ a[i];
            // cout << a[i] << ' ' << tmp << '\n';
            cnt += (a[i] >= tmp);
        }
    }

    cout << cnt << "\n";
}