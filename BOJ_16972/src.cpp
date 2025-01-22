#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(-8140, 8140);
    for (int i = 0; i < 814; i++)
    {
        auto x = dist(mt);
        auto y = dist(mt);
        cout << x << ' ' << y << '\n';
    }
}