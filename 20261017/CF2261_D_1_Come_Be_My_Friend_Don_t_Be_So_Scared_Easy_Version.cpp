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
    int n, m;
    cin >> n >> m;
    int idx = 0;
    vector<array<int, 2>> g;
    // g.push_back({1, n, 1});
    // int cnt = 2;
    // while (idx < g.size())
    // {
    //     int l = g[idx][0], r = g[idx][1];
    //     if (l == r)
    //     {
    //         idx++;
    //         continue;
    //     }
    //     int mid = (g[idx][0] + g[idx][1]) / 2;
    //     g.push_back({l, mid, cnt++});
    //     g.push_back({mid + 1, r, cnt++});
    //     idx++;
    // }
    // vector<pair<int, int>> ans;
    // for (int i = 0; i < g.size(); i++)
    // {
    //     if (i % 2) ans.push_back({g[i][0], g[i][1]});
    // }
    // cout << ans.size() << '\n';
    // for (auto [x, y] : ans) cout << x << ' ' << y << '\n';
    // int mid = (1 + ((n - 1) % 2 ? n - 1 : n)) / 2;
    // g.push_back({1, mid});
    // g.push_back({mid, ((n - 1) % 2 ? n - 1 : n)});
    // while (idx < g.size())
    // {
    //     auto [l, r] = g[idx];
    //     if (r - l <= 1)
    //     {
    //         idx++;
    //         continue;
    //     }
    //     mid = (l + ((r - 1 - l) % 2 ? r - 2 : r - 1)) / 2;
    //     g.push_back({l, mid});
    //     g.push_back({mid, ((r - 1 - l) % 2 ? r - 2 : r - 1)});
    //     idx++;
    // }
    // cout << g.size() << '\n';
    // for (auto [x, y] : g) cout << x << ' ' << y << '\n';
    // set<pair<int, int>> ans;
    // g.push_back({1, n - 1});
    // while (idx < g.size())
    // {
    //     auto [l, r] = g[idx];
    //     // cout << l << ' ' << r << '\n';
    //     if (r < l)
    //     {
    //         idx++;
    //         continue;
    //     }
    //     int mid = (l + r) / 2;
    //     ans.insert({l, mid});
    //     ans.insert({mid, r});
    //     // [l,mid-1],[mid+1,r]
    //     if (mid - 2 - l + 1 >= 0) g.push_back({l, mid - 2});
    //     if (r - 1 - (mid + 1) + 1 >= 0) g.push_back({mid + 1, r - 1});
    //     idx++;
    // }
    // cout << ans.size() << '\n';
    // for (auto [x, y] : ans) cout << x << ' ' << y << '\n';
    if (n == 1) cout << 0 << '\n';
    else
    {
        cout << (n + 1) / 2 << '\n';
        for (int i = 1; i <= (n + 1) / 2; i++) cout << i << ' ' << min(n, i + (n + 1) / 2 - 1) << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}