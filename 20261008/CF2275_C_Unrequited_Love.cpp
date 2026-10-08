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
vector<int> p, vis;
void sieve(int n)
{
    vis.assign(n + 1, 0);
    p.clear();
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i]) p.push_back(i);
        for (auto j : p)
        {
            if (i * j > n) break;
            vis[i * j] = 1; // 被标记的不是素数
            if (i % j == 0) break;
        }
    }
}
void moth()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), sum(n + 1);
    map<int, map<int, ll>> mp;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n - 4; i++) sum[i] = a[i] + a[i + 2] - a[i + 4], mp[sum[i]][i] = 1;
    ll ans = 0;
    for (int i = 1; i <= n - 4; i++) ans += 1ll * mp[sum[i]].size() - 1 - (mp[sum[i]].count(i - 2)) - (mp[sum[i]].count(i - 4)) - (mp[sum[i]].count(i + 2)) - (mp[sum[i]].count(i + 4));
    cout << ans / 2 << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cout << p.size();
    cin >> _;
    while (_--) moth();
    return 0;
}