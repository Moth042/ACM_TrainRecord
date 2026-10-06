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
ll f[N], g[N];
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
void init()
{
    f[0] = g[0] = 1;
    for (int i = 1; i < N; i++)
    {
        f[i] = f[i - 1] * i % MOD;
        g[i] = g[i - 1] * ksm(i, MOD - 2, MOD) % MOD;
    }
}
void moth()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> G(n + 1);
    map<pair<int, int>, int> id;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        id[{u, v}] = id[{v, u}] = i;
    }
    vector<ll> sz(n + 1), cnt(n + 1, 1), cntp(n + 1, 1), ans(n);
    auto dfs = [&](auto &&self, int u, int fa) -> void
    {
        sz[u] = 1;
        for (auto v : G[u])
        {
            if (v == fa) continue;
            self(self, v, u);
            sz[u] += sz[v];
            cnt[u] = (cnt[u] * cnt[v]) % MOD;
        }
        if (fa) cnt[u] = (cnt[u] * sz[u]) % MOD;
    };
    dfs(dfs, 1, 0);
    auto dfs2 = [&](auto &&self, int u, int fa) -> void
    {
        if (!fa) cntp[u] = inv(cnt[u]);
        else
        {
            cntp[u] = cntp[fa] * sz[u] % MOD * inv(n - sz[u]) % MOD;
            ans[id[{u, fa}]] = f[n - 2] * (cntp[fa] * sz[u] % MOD + cntp[u] * (n - sz[u]) % MOD) % MOD;
        }
        for (auto v : G[u])
        {
            if (v == fa) continue;
            self(self, v, u);
        }
    };
    dfs2(dfs2, 1, 0);
    while (q--)
    {
        int x;
        cin >> x;
        cout << ans[x] << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    init();
    // cin >> _;
    while (_--) moth();
    return 0;
}