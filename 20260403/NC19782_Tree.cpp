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
        if (c == '-')
            s = -1;
        c = getchar();
    }
    return x * s;
}
// 快写
void write(i128 x)
{
    if (x > 9)
        write(x / 10);
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
    vector<ll> ans(n + 1), f(n + 1), dp(n + 1);
    auto dfs = [&](auto &&self, int u, int fa) -> void
    {
        dp[u] = 1;
        for (auto v : g[u])
        {
            if (v == fa)
                continue;
            self(self, v, u);
            dp[u] *= (dp[v] + 1);
            dp[u] %= mod;
        }
    };
    dfs(dfs, 1, 0);
    auto dfs2 = [&](auto &&self, int u, int fa) -> void
    {
        int m = g[u].size();
        vector<ll> pre(m + 2, 1), suf(m + 2, 1);
        for (int i = 1; i <= m; i++)
        {
            int v = g[u][i - 1];
            if (v == fa)
                pre[i] = pre[i - 1] * (f[u] + 1);
            else
                pre[i] = pre[i - 1] * (dp[v] + 1);
            pre[i] %= mod;
        }
        for (int i = m; i >= 1; i--)
        {
            int v = g[u][i - 1];
            if (v == fa)
                suf[i] = suf[i + 1] * (f[u] + 1);
            else
                suf[i] = suf[i + 1] * (dp[v] + 1);
            suf[i] %= mod;
        }
        ans[u] = pre[m];
        for (int i = 1; i <= m; i++)
        {
            int v = g[u][i - 1];
            if (v == fa)
                continue;
            f[v] = pre[i - 1] * suf[i + 1] % mod;
            self(self, v, u);
        }
    };
    dfs2(dfs2, 1, 0);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--)
        moth();
    return 0;
}