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
ll ksm(ll a, ll b, ll c)
{
    ll res = 1;
    while (b)
    {
        if (b & 1) res = res * a % c;
        a = a * a % c;
        b >>= 1;
    }
    return res;
}
ll inv(ll x)
{
    return ksm(x, MOD - 2, MOD) % MOD;
}
void moth()
{
    int n, m, t;
    string s;
    cin >> n >> m >> t >> s;
    s = " " + s;
    vector<vector<pair<int, ll>>> g(n + 1);
    vector<int> deg(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        g[v].push_back({u, w});
        deg[u]++;
    }
    vector<ll> d(n + 1, 1e18);
    auto dijkstra = [&](int st) -> void
    {
        using PLL = pair<ll, int>;
        priority_queue<PLL, vector<PLL>, greater<PLL>> q;
        q.emplace(0, st);
        d[st] = 0;
        while (q.size())
        {
            auto [w, x] = q.top();
            q.pop();
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
    dijkstra(t);
    vector<int> cnt(n + 1);
    cnt[t] = 1;
    vector<ll> ans(n + 1);
    queue<int> q;
    q.push(t);
    auto deg2 = deg;
    vector<int> order;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (auto [v, w] : g[u])
        {
            if (d[u] + w == d[v]) cnt[v] = (cnt[u] + cnt[v]) % MOD;
            if (--deg2[v] == 0) q.push(v);
        }
    }
    for (auto u : order)
    {
        for (auto [v, w] : g[u])
        {
            if (s[v] == '0')
            {
                ans[v] += (ans[u] + w) * inv(deg[v]) % MOD;
                ans[v] %= MOD;
            }
            else if (d[u] + w == d[v])
            {
                ans[v] += cnt[u] * (ans[u] + w) % MOD * inv(cnt[v]) % MOD;
                ans[v] %= MOD;
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}