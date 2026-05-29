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
    int n, k;
    cin >> n >> k;
    ll res1 = 0, res2 = 1;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        res1 += x;
        res1 %= MOD;
        res2 *= x;
        res2 %= MOD;
    }
    string s;
    cin >> s;
    s = " " + s;
    ll st, ans;
    if (s[k] == 's') st = res1;
    else st = res2;
    for (int i = k - 1; i >= 1; i--)
    {
        if (s[i] == 's')
        {
            ll df = st * n % MOD;
            st = df;
            st %= MOD;
        }
        else
        {
            ll df = ksm(st, n, MOD);
            st = df;
            st %= MOD;
        }
    }
    cout << st << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}