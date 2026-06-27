#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int N = 2e5 + 9;
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
struct Node
{
    ll x, w, id;
    bool operator<(const Node &v) const
    {
        return w > v.w;
    }
};

void moth()
{
    int n, m;
    cin >> n >> m;
    vector<ll> d(n + 1, 1e18);
    vector<int> vis(n + 1);
    vector<vector<Node>> g(n + 1);
    vector<ll> a(n + 1), ans(m + 1, 1e9);
    int st = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 0) st = i;
    }
    if (st == -1)
    {
        cout << -1 << '\n';
        return;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back({v, abs(a[u] - a[v]), i});
        g[v].push_back({u, abs(a[u] - a[v]), i});
    }
    auto dijkstra = [&](int st) -> void
    {
        d[st] = 0;
        priority_queue<Node> q;
        q.push({st, d[st], 0});
        while (q.size())
        {
            auto [x, w, id] = q.top();
            q.pop();
            if (vis[x]) continue;
            vis[x] = 1;
            for (auto [y, w2, id2] : g[x])
            {
                if (!vis[y] && d[y] > d[x] + w2)
                {
                    d[y] = d[x] + w2;
                    q.push({y, d[y], id2});
                }
            }
        }
    };
    dijkstra(st);
    for (int i = 1; i <= n; i++)
    {
        if (d[i] != a[i])
        {
            cout << -1 << '\n';
            return;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto j : g[i]) ans[j.id] = j.w;
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}