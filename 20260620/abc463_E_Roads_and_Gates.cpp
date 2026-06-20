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
struct Node
{
    ll x, w;
    bool operator<(const Node &v) const
    {
        return w > v.w;
    }
};
void moth()
{
    ll n, m, y;
    cin >> n >> m >> y;
    vector<vector<Node>> g(n + 2);
    vector<ll> d(n + 2, 1e18);
    vector<int> vis(n + 2);
    for (int i = 1; i <= m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        g[i].push_back({n + 1, x + y});
        g[n + 1].push_back({i, x});
    }
    d[1] = 0;
    priority_queue<Node> q;
    q.push({1, 0});
    while (q.size())
    {
        auto [x, w] = q.top();
        q.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        for (auto [y, w2] : g[x])
        {
            if (!vis[y] && d[y] > d[x] + w2)
            {
                d[y] = d[x] + w2;
                q.push({y, d[y]});
            }
        }
    }
    for (int i = 2; i <= n; i++) cout << d[i] << ' ';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}