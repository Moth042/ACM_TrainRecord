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
    ll n, k;
    cin >> n >> k;
    vector<ll> c(200002);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x <= 200001) c[x]++;
    }
    ll ans = 0;
    vector<ll> p1(200002), p2(200002, 1);
    for (int i = 1; i <= 200001; i++)
    {
        p1[i] = p1[i - 1] + c[i];
        ll df = (ksm(2, c[i], MOD) % MOD - 1 + MOD) % MOD;
        p2[i] = p2[i - 1] * df % MOD;
    }
    for (int i = 1; i <= 200001; i++)
    {
        ll mi = n - p1[i];
        ll sum = p2[i - 1];
        ll cnt = ksm(2, mi, MOD) % MOD * sum % MOD;
        ans = (ans + cnt % MOD * ksm(i, k, MOD) % MOD) % MOD;
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}