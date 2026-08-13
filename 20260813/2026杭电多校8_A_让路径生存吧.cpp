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
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int, int>> edge(m + 1);
    vector<int> vis(n + 1), Q(q + 1);
    vector<vector<int>> nb(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 1, u, v; i <= m; i++)
    {
        cin >> u >> v;
        edge[i] = {u, v};
        // g[u].push_back(v);
        nb[u].push_back(v);
    }
    for (int i = 1, x; i <= q; i++)
    {
        cin >> x;
        Q[i] = x;
        vis[x] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        auto [u, v] = edge[i];
        if (!vis[u]) g[u].push_back(v);
    }
    int l = 0, r = q;
    auto check = [&](int x) -> bool
    {
        for (int i = x + 1; i <= q; i++)
        {
            for (auto j : nb[Q[i]]) g[Q[i]].push_back(j);
        }
        queue<int> qq;
        qq.push(1);
        bool ok = 0;
        vector<int> vis(n + 1);
        vis[1] = 1;
        while (qq.size())
        {
            int y = qq.front();
            qq.pop();
            if (y == n)
            {
                ok = 1;
                break;
            }
            for (auto v : g[y])
            {
                if (!vis[v])
                {
                    qq.push(v);
                    vis[v] = 1;
                }
            }
        }
        for (int i = x + 1; i <= q; i++) g[Q[i]].clear();
        return ok;
    };
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    if (check(l))
    {
        if (l == q) cout << "YES\n";
        else cout << l << '\n';
    }
    else cout << "NO\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}