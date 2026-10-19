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
    int n, m, a, b, s, t;
    cin >> n >> m >> a >> b >> s >> t;
    vector<vector<int>> g(n + 1);
    vector<pair<int, int>> e;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        e.push_back({u, v});
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto bfs = [&](int s) -> vector<ll>
    {
        vector<ll> d(n + 1, 1e18);
        queue<int> q;
        q.push(s);
        d[s] = 0;
        vector<int> vis(n + 1);
        vis[s] = 1;
        while (q.size())
        {
            int x = q.front();
            q.pop();
            for (auto y : g[x])
            {
                if (!vis[y] && d[y] > d[x] + 1)
                {
                    vis[y] = 1;
                    d[y] = d[x] + 1;
                    q.push(y);
                }
            }
        }
        return d;
    };
    auto d1 = bfs(a), d2 = bfs(b);
    vector<ll> val(n + 1);
    for (int i = 1; i <= n; i++) val[i] = abs(d1[i] - d2[i]);
    // for (int i = 1; i <= n; i++) cout << val[i] << " \n"[i == n];
    vector<ll> d(n + 1, 1e18);
    vector<vector<pair<int, ll>>> gg(n + 1);
    for (auto [u, v] : e)
    {
        gg[u].push_back({v, val[v]});
        gg[v].push_back({u, val[u]});
    }
    auto dijkstra = [&](int st) -> void
    {
        using PLL = pair<ll, int>;
        priority_queue<PLL, vector<PLL>, greater<PLL>> q;
        q.emplace(val[st], st);
        d[st] = val[st];
        while (q.size())
        {
            auto [w, x] = q.top();
            q.pop();
            if (d[x] != w) continue;
            for (auto [y, w2] : gg[x])
            {
                if (d[y] > max(d[x], w2))
                {
                    d[y] = max(d[x], w2);
                    q.emplace(d[y], y);
                }
            }
        }
    };
    dijkstra(s);
    cout << d[t];
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}