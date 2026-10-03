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
    int n, k;
    cin >> n >> k;
    sieve(n);
    vector<ll> f(n + 1, 1e18);
    f[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (i <= k) f[i] = 0;
        else if (!vis[i])
        {
            if (i <= k) f[i] = 0;
            else f[i] = 1;
        }
    }
    vector<vector<int>> inz(n + 1);
    for (auto i : p)
    {
        for (int j = 2; 1ll * j * i <= n; j++) inz[1ll * j * i].push_back(i);
    }
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i]) continue;
        for (auto j : inz[i]) f[i] = min(f[i], f[i / j] * j + 1);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        ans += f[x];
    }
    // for (int i = 1; i <= n; i++) cout << f[i] << " ";
    // cout << '\n';
    cout << ans << '\n';
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