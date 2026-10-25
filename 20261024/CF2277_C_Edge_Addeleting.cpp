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
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dep(n + 1);
    vector<vector<int>> f(n + 1, vector<int>(21));
    auto dfs = [&](auto &&self, int u, int fa) -> void
    {
        dep[u] = dep[fa] + 1;
        f[u][0] = fa;
        for (int i = 1; i < 21; i++) f[u][i] = f[f[u][i - 1]][i - 1];
        for (auto v : g[u])
        {
            if (v == fa) continue;
            self(self, v, u);
        }
    };
    dfs(dfs, 1, 0);
    auto lca = [&](int u, int v) -> int
    {
        if (dep[u] < dep[v]) swap(u, v);
        for (int i = 20; i >= 0; i--)
        {
            if (dep[f[u][i]] >= dep[v]) u = f[u][i];
        }
        if (u == v) return u;
        for (int i = 20; i >= 0; i--)
        {
            if (f[u][i] != f[v][i])
            {
                u = f[u][i];
                v = f[v][i];
            }
        }
        return f[u][0];
    };
    auto dis = [&](int u, int v) -> int { return dep[u] + dep[v] - dep[lca(u, v)] * 2; };
    int ans = dis(1, n);
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        if (x == n) continue;
        if (lca(x, n) == 1) continue;
        ans = max(ans, 1 + dis(x, n));
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}