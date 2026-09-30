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
struct dsu
{
    vector<int> fa, sz;
    int n;
    dsu(int len)
    {
        n = len;
        fa.resize(n + 1);
        sz.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) fa[i] = i;
    }
    int find(int x)
    {
        if (x == fa[x]) return x;
        return fa[x] = find(fa[x]);
    }
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
    bool merge(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        fa[y] = x;
        return true;
    }
};
void moth()
{
    int n, m;
    cin >> n >> m;
    dsu dsu(n);
    vector<vector<pair<int, ll>>> g(n + 1);
    vector<tuple<int, int, ll>> es;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        if (!dsu.same(u, v))
        {
            g[u].push_back({v, w});
            g[v].push_back({u, w});
            dsu.merge(u, v);
        }
        else es.push_back({u, v, w});
    }
    vector<int> root;
    for (int i = 1; i <= n; i++)
    {
        if (dsu.find(i) == i) root.push_back(i);
    }
    vector<ll> ww(n + 1);
    auto dfs = [&](auto &&self, int u, int fa) -> void
    {
        for (auto [v, w] : g[u])
        {
            if (v == fa) continue;
            ww[v] = ww[u] ^ w;
            self(self, v, u);
        }
    };

    vector<vector<int>> son(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (dsu.find(i) != i) son[dsu.find(i)].push_back(i);
    }
    for (auto i : root) dfs(dfs, i, 0);
    vector<ll> ans(n + 1);
    for (auto u : root)
    {
        for (int bit = 0; bit <= 40; bit++)
        {
            ll sum0 = 0, sum1 = 1ll << bit;
            for (auto v : son[u])
            {
                sum0 += (((ww[v] >> bit) & 1) << bit);
                sum1 += (1ll * (((ww[v] >> bit) ^ 1) & 1) << bit);
            }
            // cout << bit << ' ' << sum0 << ' ' << sum1 << '\n';
            if (sum1 < sum0) ans[u] += (1ll << bit);
        }
    }
    for (auto u : root)
    {
        for (auto v : son[u]) ans[v] = ans[u] ^ ww[v];
    }
    // for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    // cout << '\n';
    for (auto [u, v, w] : es)
    {
        if ((ans[u] ^ ans[v]) != w)
        {
            cout << -1 << '\n';
            return;
        }
    }
    // for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    // cout << '\n';
    cout << accumulate(ans.begin() + 1, ans.end(), 0ll) << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}