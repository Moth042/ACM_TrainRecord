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
    ll x, y;
    cin >> x >> y;
    set<ll> en1, en2;
    for (ll i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            en1.insert(i);
            if (i != x / i) en1.insert(x / i);
        }
    }
    for (ll i = 1; i * i <= y; i++)
    {
        if (y % i == 0)
        {
            en2.insert(i);
            if (i != y / i) en2.insert(y / i);
        }
    }
    map<ll, int> mp;
    i128 ans = 0;
    for (auto i : en1)
    {
        if (!mp.count(i))
        {
            mp[i]++;
            ans += (i128)1 * ksm(i % mod, i % (mod - 1) + (mod - 1), mod) % mod;
            // ans += ksm(i % mod, i % mod, mod) % mod;
            ans % mod;
        }
        for (auto j : en2)
        {
            if (!mp.count(j))
            {
                mp[j]++;
                ans += (i128)1 * ksm(j % mod, j % (mod - 1) + (mod - 1), mod) % mod;
                // ans += ksm(j % mod, j % mod, mod) % mod;
                ans % mod;
            }
            if (!mp.count(i * j))
            {
                ll t = i * j;
                mp[t]++;
                ans += (i128)1 * ksm(t % mod, t % (mod - 1) + (mod - 1), mod) % mod;
                // ans += ksm(i * j % mod, i * j % mod, mod) % mod;
                ans %= mod;
            }
        }
    }
    // cout << ans << '\n';
    write(ans);
    // for (auto [x, y] : mp) cout << x << ' ';
}
int main()
{
    // freopen("data.in", "r", stdin);
    // freopen("data1.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}