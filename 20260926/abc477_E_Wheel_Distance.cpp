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
    int n, q;
    cin >> n >> q;
    vector<ll> a(n + 2), b(n + 2), p(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i], p[i] = p[i - 1] + a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    vector<vector<pair<ll, ll>>> g(n + 2);
    for (int i = 1; i <= n; i++)
    {
        g[i].push_back({(i % n) + 1, a[i]});
        g[(i % n) + 1].push_back({i, a[i]});
        g[i].push_back({n + 1, b[i]});
        g[n + 1].push_back({i, b[i]});
    }
    vector<ll> d(n + 2, 1e18);
    auto dijkstra = [&](int st) -> void
    {
        for (int i = 1; i <= n + 1; i++) d[i] = 1e18;
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
    dijkstra(n + 1);
    while (q--)
    {
        int s, t;
        cin >> s >> t;
        if (t == n + 1) cout << d[s] << '\n';
        else cout << min({p[t - 1] - p[s - 1], p[n] - p[t - 1] + p[s - 1], d[s] + d[t]}) << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}