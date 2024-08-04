#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        ret ^= x;
    }

    if (!ret)
        cout << "cubelover\n";
    else
        cout << "koosaga\n";
}