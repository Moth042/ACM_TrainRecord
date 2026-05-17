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
    int n;
    cin >> n;
    vector<vector<pair<ll, ll>>> g(n + 1);
    vector<ll> h(n + 1), f(n + 1), w(n + 1);
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 2; i <= n; i++) cin >> f[i];
    for (int i = 2; i <= n; i++) cin >> w[i];
    for (int i = 2; i <= n; i++) g[f[i]].push_back({w[i], i});
    ll cur = 0;
    vector<ll> now(n + 1), ans(n + 1);
    auto dfs = [&](auto &&self, int u, int fa) -> void
    {
        if (g[u].size() == 0)
        {
            cur += h[u];
            ans[u] = cur;
            now[u] = h[u];
            return;
        }
        // if(now[u]==h[u])
        // {
        //     ans[u]=cur;
        //     return;
        // }
        sort(g[u].begin(), g[u].end());
        for (int i = 0; i < g[u].size(); i++)
        {
            auto [w, v] = g[u][i];
            if (i == 0) now[u] += w, cur += w;
            else now[u] += (w - g[u][i - 1].first), cur += (w - g[u][i - 1].first);
            self(self, v, u);
        }
        cur += (h[u] - now[u]);
        now[u] = h[u];
        ans[u] = cur;
    };
    dfs(dfs, 1, 0);
    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}