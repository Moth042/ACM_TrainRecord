#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int N = 1e5 + 9;
const int mod = 1e9 + 7;
const int MOD = 998244353;
int dx[] = {-1, 0, 1, 0}; // 上右下左
int dy[] = {0, 1, 0, -1};
int ddx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int ddy[] = {0, 1, 1, 1, 0, -1, -1, -1};
// 快读
inline i128 read()
{
    char c = getchar();
    i128 x = 0, s = 1;
    while (c < '0' || c > '9')
    {
        if (c == '-') s = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x * s;
}
// 快写
void write(i128 x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 | 48);
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int randint(int l, int r)
{
    return uniform_int_distribution{l, r}(rnd);
}
void moth()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> ans(k + 1);
    // vector<vector<int>>vis(n+1,vector<int>(n+1));
    for (int i = 1; i <= n * 2; i++)
    {
        // if (i % 2)
        // {
        //     ans[i] = {i, i};
        //     // vis[i][i]=1;
        // }
        // else
        // {
        //     if (i != n * 2)
        //     {
        //         ans[i] = {i, i + 1};
        //         // vis[i][i+1]=1;
        //     }
        //     else ans[i] = {n, 1};
        //     // vis[n][1]=1;
        // }
        int x = (i + 1) / 2;
        int y;
        if (i == n * 2) y = 1;
        else
        {
            if (i % 2) y = x;
            else y = x + 1;
        }

        ans[i] = {x, y};
    }
    // for(int i=n*2+1;i<=k;i++)
    // {

    // }
    int cur = n * 2 + 1;
    int r = 1, c = 1;
    while (cur <= k)
    {

        // while (r <= n && (c == r || c == (r == n ? 1 : r + 1)))
        // {
        //     cout<<r<<' '<<c<<'\n';
        //     c++;
        //     if (c == n + 1)
        //     {
        //         c = 1;
        //         r++;
        //     }
        // }
        // cout<<r<<' '<<c<<'\n';
        // ans[cur++] = {r, c};
        // if (c == n)
        // {
        //     c = 1;
        //     r++;
        // }
        while (c <= n && (c == r || c == (r == n ? 1 : r + 1))) c++;
        if (c == n + 1)
        {
            c = 1;
            r++;
        }
        else ans[cur++] = {r, c}, c++;
    }
    for (int i = 1; i <= k; i++) cout << ans[i].first << " " << ans[i].second << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}