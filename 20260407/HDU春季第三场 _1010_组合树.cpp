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
        if (c == '-')
            s = -1;
        c = getchar();
    }
    return x * s;
}
// 快写
void write(i128 x)
{
    if (x > 9)
        write(x / 10);
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
        if (w != m.w)
            return w < m.w;
        if (u != m.u)
            return u < m.u;
        return v < m.v;
        // 等价于return w==m.w?(u==m.u?v<m.v:u<m.u):w<m.w;
    }
};
int pre[N];
int root(int x) { return pre[x] = (pre[x] == x ? x : root(pre[x])); }
ll f[N], g[N];
ll ksm(ll a, ll b, ll c)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % c;
        a = a * a % c;
        b >>= 1;
    }
    return res;
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
ll C(ll n, ll m)
{
    if (n < m)
        return 0;
    if (n < 0 || m < 0)
        return 0;
    return f[n] * g[m] % MOD * g[n - m] % MOD;
}
void moth()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin() + 1, a.end());
    ll ans = 0;
    for (int i = 2; i <= n; i++)
    {
        ll t = min(a[1], a[i] - a[i - 1]);
        ans += C(a[i], t);
        ans %= MOD;
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    int _ = 1;
    cin >> _;
    while (_--)
        moth();
    return 0;
}