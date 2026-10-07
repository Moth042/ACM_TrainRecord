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
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> fac(n + 1, 1);
    fac[1] = 1, fac[2] = 2;
    for (int i = 3; i <= n; i++) fac[i] = fac[i - 2] * i % MOD;
    auto Fac = [&](int x) -> ll
    {
        if (x <= 0) return 1;
        return fac[x];
    };
    vector<ll> dp(n + 1, 1);
    vector<int> sz(n + 1), odd(n + 1);
    auto dfs = [&](auto &&self, int u, int fa) -> void
    {
        sz[u] = 1;
        for (auto v : g[u])
        {
            if (v == fa) continue;
            self(self, v, u);
            sz[u] += sz[v];
            if (sz[v] % 2) odd[u]++;
            dp[u] = (dp[u] * dp[v]) % MOD;
        }
        if (odd[u] % 2) dp[u] = (dp[u] * Fac(odd[u])) % MOD;
        else dp[u] = (dp[u] * Fac(odd[u] - 1)) % MOD;
    };
    dfs(dfs, 1, 0);
    cout << dp[1] << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}