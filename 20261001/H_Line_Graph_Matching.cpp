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
set<pair<int, int>> E;

struct EBCC
{
    int n;
    vector<vector<int>> adj;
    vector<int> stk;
    vector<int> dfn, low, bel;
    int cur, cnt;

    EBCC()
    {
    }
    EBCC(int n)
    {
        init(n);
    }

    void init(int n)
    {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.resize(n);
        bel.assign(n, -1);
        stk.clear();
        cur = cnt = 0;
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int x, int p)
    {
        dfn[x] = low[x] = cur++;
        stk.push_back(x);

        for (auto y : adj[x])
        {
            if (y == p) continue;
            if (dfn[y] == -1)
            {
                E.emplace(x, y);
                dfs(y, x);
                low[x] = min(low[x], low[y]);
            }
            else if (bel[y] == -1 && dfn[y] < dfn[x])
            {
                E.emplace(x, y);
                low[x] = min(low[x], dfn[y]);
            }
        }

        if (dfn[x] == low[x])
        {
            int y;
            do
            {
                y = stk.back();
                bel[y] = cnt;
                stk.pop_back();
            } while (y != x);
            cnt++;
        }
    }

    std::vector<int> work()
    {
        dfs(0, -1);
        return bel;
    }

    struct Graph
    {
        int n;
        vector<pair<int, int>> edges;
        vector<int> siz;
        vector<int> cnte;
    };
    Graph compress()
    {
        Graph g;
        g.n = cnt;
        g.siz.resize(cnt);
        g.cnte.resize(cnt);

        for (int i = 0; i < n; i++)
        {
            g.siz[bel[i]]++;
            for (int j : adj[i])
            {
                if (i >= j) continue;
                int u = bel[i], v = bel[j];
                if (u != v) g.edges.emplace_back(u, v);
                else g.cnte[u]++;
            }
        }
        return g;
    }
};
void moth()
{
    int n, m;
    cin >> n >> m;
    ll sum = 0;
    EBCC e(n);
    vector<tuple<int, int, ll>> edge(m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u;
        --v;
        edge[i] = {u, v, w};
        e.addEdge(u, v);
        sum += w;
    }
    if (m % 2 == 0)
    {
        cout << sum << '\n';
        return;
    }
    ll mn = 1e18;
    auto bel = e.work();
    auto g = e.compress();
    for (auto [u, v, w] : edge)
    {
        if (bel[u] == bel[v]) mn = min(mn, w);
    }
    map<pair<int, int>, ll> mp;
    for (auto [u, v, w] : edge)
    {
        int a = bel[u], b = bel[v];
        if (a == b) continue;
        if (a > b) swap(a, b);
        mp[{a, b}] = w;
    }
    vector<vector<pair<int, ll>>> tr(g.n);
    for (auto [u, v] : g.edges)
    {
        int p = min(u, v), q = max(u, v);
        ll w = mp[{p, q}];
        tr[u].push_back({v, w});
        tr[v].push_back({u, w});
    }
    vector<int> esum(g.n);
    auto dfs = [&](auto &&self, int u, int fa) -> void
    {
        esum[u] = g.cnte[u];
        for (auto [v, w] : tr[u])
        {
            if (v == fa) continue;
            self(self, v, u);
            esum[u] += esum[v] + 1;
            if (esum[v] % 2 == 0) mn = min(mn, w);
        }
    };
    dfs(dfs, 0, -1);
    cout << sum - mn << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}