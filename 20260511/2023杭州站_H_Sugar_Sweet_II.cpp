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
ll ksm(ll a, ll b, ll c)
{
    ll res = 1;
    while (b)
    {
        if (b & 1) res = res * a % c;
        a = a * a % c;
        b >>= 1;
    }
    return res;
}
void moth()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1), w(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> w[i];
    vector<vector<int>> g(n + 1);
    vector<ll> ans(n + 1, -1);
    vector<ll> invf(n + 1);
    invf[0] = 0, invf[1] = 1;
    vector<ll> d(n + 1, 0);
    for (int i = 2; i <= n; i++) invf[i] = invf[i - 1] * ksm(i, mod - 2, mod) % mod;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < a[b[i]]) ans[i] = (a[i] + w[i]) % mod, d[i] = 1;
        else if (a[i] >= a[b[i]] + w[b[i]]) ans[i] = a[i] % mod, d[i] = 0;
        else g[b[i]].push_back(i);
    }
    auto dfs = [&](auto &&self, int u, ll dis) -> void
    {
        d[u] = dis;
        for (auto v : g[u]) self(self, v, dis + 1);
    };
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 1) dfs(dfs, i, 1);
    }
    // cout << d[2] << '\n';
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == -1) ans[i] = (a[i] + invf[d[i]] * w[i] % mod) % mod;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}