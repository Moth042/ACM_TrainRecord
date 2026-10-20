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
struct Edge
{
    ll u, v, w;
    bool operator<(const Edge &m) const
    {
        if (w != m.w) return w < m.w;
        if (u != m.u) return u < m.u;
        return v < m.v;
        // 等价于return w==m.w?(u==m.u?v<m.v:u<m.u):w<m.w;
    }
};
int pre[N];
int root(int x)
{
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}
void moth()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> ts(n + 1);
    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        ts[x] = 1;
    }
    vector<Edge> es, ess;
    map<pair<int, int>, ll> mp;
    for (int i = 1; i <= m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        if (u > v) swap(u, v);
        // es.push_back({u, v, w});
        if (mp.count({u, v})) mp[{u, v}] = min(mp[{u, v}], w);
        else mp[{u, v}] = w;
        // if (!ts[u] && !ts[v]) ess.push_back({u, v, w});
    }
    if (n == 2 && k == 2)
    {
        ll mn = 1e18;
        for (auto [k, w] : mp)
        {
            int u = k.first, v = k.second;
            if (u == v) continue;
            mn = min(mn, w);
        }
        if (mn == 1e18) cout << -1 << '\n';
        else cout << mn << '\n';
        return;
    }
    for (auto [k, w] : mp)
    {
        int u = k.first, v = k.second;
        es.push_back({u, v, w});
        if (!ts[u] && !ts[v]) ess.push_back({u, v, w});
    }
    sort(ess.begin(), ess.end());
    ll ans = 0;
    for (int i = 1; i <= n; i++) pre[i] = i;
    for (auto &[u, v, w] : ess)
    {
        if (root(u) == root(v)) continue;
        ans += w;
        pre[root(u)] = root(v);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (!ts[i] && root(i) == i) cnt++;
    // cout << cnt << '\n';
    if (cnt > 1)
    {
        cout << -1 << '\n';
        return;
    }
    // queue<int> q;
    vector<ll> d(n + 1, 1e18);

    vector<vector<pair<ll, ll>>> g(n + 1);
    for (auto [u, v, w] : es)
    {
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    // vector<ll> d(n + 1, 1e18);
    auto dijkstra = [&]() -> void
    {
        using PLL = pair<ll, int>;
        priority_queue<PLL, vector<PLL>, greater<PLL>> q;
        for (int i = 1; i <= n; i++)
        {
            if (!ts[i])
            {
                q.emplace(0, i);
                d[i] = 0;
            }
        }
        while (q.size())
        {
            auto [w, x] = q.top();
            q.pop();
            if (ts[x]) continue;
            if (d[x] != w) continue;
            for (auto [y, w2] : g[x])
            {
                if (d[y] > d[x] + w2)
                {
                    d[y] = d[x] + w2;
                    q.emplace(d[y], y);
                }
            }
        }
    };
    dijkstra();
    for (int i = 1; i <= n; i++)
    {
        if (!ts[i]) continue;
        if (d[i] == 1e18)
        {
            cout << -1 << '\n';
            return;
        }
        ans += d[i];
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