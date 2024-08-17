/*
n명의 이름을 적는다.
최대 m글자 적을 수 있는 곳에 적는다.
각 사람의 이름은 1칸씩 띄어 적는다.
m글자를 채우지 못했을 경우 -> 남은 칸의 제곱 penalty가 있다.
penalty를 최소화하는 방법으로 쓰고, 해당 penalty를 구하여라

dp[idx][groups]: 현재 idx번째 사람의 이름까지 groups 만큼의 줄에 적은 state

*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> dp;
vector<int> a;

int rec(int idx, int groups)
{
    if (idx == n)
        return 0;

    int &ret = dp[idx][groups];
    if (ret != -1)
        return ret;

    ret = INT_MAX;
    int now = 0;
    for (int i = idx + 1; i <= n; i++)
    {
        if (i != idx + 1) // 두번째 사람부터는 1칸 띄어야 쓸 수 있다.
            now++;
        now += a[i];

        if (now > m) // 한 줄에는 m칸 초과하여 작성할 수 없으므로 불가능한 경우의 수이다.
            break;

        int cost = (m - now) * (m - now); // 줄을 끝까지 사용하지 않고 남은 칸의 수의 제곱의 penalty를 얻는다.
        if (i == n)                       // (제일 마지막 줄은 앞으로 이름을 적을 기회가 있으므로 계산하지 않는다.)
            cost = 0;
        ret = min(ret, rec(i, groups + 1) + cost);
    }
    return ret;
}

int main()
{
    cin >> n >> m;
    a = vector<int>(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
    int ans = rec(0, 0);
    cout << ans << "\n";
}