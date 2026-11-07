#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int N = 5e3 + 9;
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
ll f[N], g[N], b[N], dp[N];
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
    return f[n] * g[m] % MOD * g[n - m] % MOD;
}
void bell()
{
    b[0] = 1;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++) b[i] = (b[i] + C(i - 1, j) * b[i - 1 - j] % MOD) % MOD;
    }
}
void moth()
{
    int n;
    string s;
    cin >> n >> s;
    s = " " + s;
    vector<int> len;
    int c0 = 0, c1 = 0;
    for (int i = 1; i <= n;)
    {
        int r = i + 1;
        while (r <= n && s[r] != s[r - 1]) r++;
        if (r - i != 1) len.push_back(r - i);
        else
        {
            if (s[i] == '0') c0++;
            else c1++;
        }
        i = r;
        r++;
    }

    ll sum = c0 + c1 + (n - c0 - c1) * 2;
    ll ans = b[c0] % MOD * b[c1] % MOD;
    for (auto i : len) ans = ans * dp[i] % MOD;
    cout << sum << ' ' << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    init();
    bell();
    dp[0] = 1;
    for (int i = 1; i < N; i++)
    {
        if (i >= 2) dp[i] = (dp[i] + dp[i - 2]) % MOD;
        if (i >= 3) dp[i] = (dp[i] + dp[i - 3]) % MOD;
    }
    cin >> _;
    while (_--) moth();
    return 0;
}