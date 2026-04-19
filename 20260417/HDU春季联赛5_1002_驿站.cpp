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
    int n, m;
    cin >> n >> m;
    vector<vector<Node>> g(n + 1);
    for (int i = 1; i <= m; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back({v, max(u, v)});
    }
    vector<ll> d(n + 1, 1e18);
    d[1] = 1;
    priority_queue<Node> q;
    q.push({1, d[1]});
    vector<int> vis(n + 1);
    while (q.size())
    {
        auto [x, w] = q.top();
        q.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        for (auto [y, ww] : g[x])
        {
            if (!vis[y] && d[y] > max(d[x], ww))
            {
                d[y] = max(d[x], ww);
                q.push({y, d[y]});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 1e18) cout << -1 << " ";
        else cout << d[i] << " ";
    }
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}