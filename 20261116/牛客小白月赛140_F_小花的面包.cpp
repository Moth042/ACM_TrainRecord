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
    if (n < m) return 0;
    if (n < 0 || m < 0) return 0;
    ll res = 1;
    for (ll i = n; i >= n - m + 1; i--) res = res * (i % MOD) % MOD;
    res = res * g[m] % MOD;
    return res;
}
void moth()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m + 1), b(m / 2 + 1);
    for (int i = 1; i <= m; i++) cin >> a[i];
    if (m % 2 == 0 && n % 2)
    {
        cout << 0 << '\n';
        return;
    }
    for (int i = 1; i <= m / 2; i++) b[i] = min(a[i], a[m + 1 - i]);
    ll L, R;
    if (m % 2 == 0) L = R = n / 2;
    else
    {
        L = (n - a[(m + 1) / 2] + 1) / 2;
        R = (n - 1) / 2;
    }
    auto f = [&](ll x) -> ll
    {
        ll res = 0;
        for (ll p = 0; p < (1 << m / 2); p++)
        {
            int sz = __builtin_popcount(p);
            ll cur = 0;
            for (int j = 0; j < m / 2; j++)
            {
                if (p >> j & 1) cur += b[j + 1];
            }
            res = (res + C(x - cur, m / 2) * (sz % 2 ? -1 : 1)) % MOD;
        }
        return res;
    };
    cout << (f(R) - f(L - 1) + MOD) % MOD << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}