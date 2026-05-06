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
void moth()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1), f(n + 1, 1), invf(n + 1, 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    f[0] = 1, invf[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        f[i] = f[i - 1] * i % MOD;
        invf[i] = invf[i - 1] * ksm(1ll * i, MOD - 2, MOD) % MOD;
    }
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> mx(n + 1), mn(n + 1), ans(n + 1);
    auto dfs = [&](auto &&self, int u, int fa) -> void
    {
        mx[u] = mn[u] = a[u];
        ans[u] = 1;
        ll k = 0;
        vector<pair<ll, ll>> son;
        for (auto v : g[u])
        {
            if (v == fa) continue;
            self(self, v, u);
            k++;
            if (ans[v] == 0) ans[u] = 0;
            son.push_back({mn[v], mx[v]});
            if (ans[u]) ans[u] = ans[u] * ans[v] % MOD;
        }
        if (k == 0 || ans[u] == 0) return;
        sort(son.begin(), son.end());
        if (a[u] > son[0].first)
        {
            ans[u] = 0;
            return;
        }
        for (int i = 0; i < k - 1; i++)
        {
            if (son[i].second > son[i + 1].first)
            {
                ans[u] = 0;
                return;
            }
        }
        ll ways = 1, cnt = 1;
        for (int i = 1; i < k; i++)
        {
            if (son[i] == son[i - 1])
            {
                cnt++;
                ways = ways * cnt % MOD;
            }
            else cnt = 1;
        }
        ans[u] = ans[u] * ways % MOD * invf[k] % MOD;
        mx[u] = son[k - 1].second;
    };
    dfs(dfs, 1, 0);
    cout << ans[1] << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}