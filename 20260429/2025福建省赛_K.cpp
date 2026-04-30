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
struct Edge
{
    ll u, v, w;
    bool operator<(const Edge &b) const
    {
        return w < b.w;
    }
};
void moth()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "YES\n";
        cout << 1 << '\n';
        return;
    }
    vector<Edge> es;
    vector<vector<array<ll, 2>>> g(n + 1);
    for (int i = 1; i < n; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        es.push_back({u, v, w});
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector<int> dep(n + 1), df(n + 1);
    auto dfs = [&](auto &&self, int u, int fa) -> void
    {
        dep[u] = dep[fa] + 1;
        for (auto [v, w] : g[u])
        {
            if (v == fa) continue;
            df[v] = w - df[u];
            self(self, v, u);
        }
    };
    dfs(dfs, 1, 0);
    int l = 1, r = 1e9;
    int mx = 1e9;
    for (int i = 2; i <= n; i++)
    {
        if (dep[i] % 2)
        {
            l = max(l, 1 - df[i]);
            r = min(r, mx - df[i]);
        }
        else
        {
            l = max(l, df[i] - mx);
            r = min(r, df[i] - 1);
        }
    }
    if (l <= r)
    {
        cout << "YES\n";
        cout << l << ' ';
        for (int i = 2; i <= n; i++)
        {
            if (dep[i] % 2) cout << df[i] + l << ' ';
            else cout << df[i] - l << ' ';
        }
        cout << '\n';
    }
    else cout << "NO\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}