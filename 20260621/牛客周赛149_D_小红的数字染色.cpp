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
    vector<ll> a(n + 1), p(n + 1), p2(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i], p[i] = p[i - 1] + a[i], p2[i] = p[i] * 2;
    ll sum = p[n];
    i128 ans = 0;
    ll abss = 1e18;
    ll x = -1;
    for (int i = 1; i <= n; i++)
    {
        ll cur = sum + p2[i - 1];
        auto it = lower_bound(p2.begin() + i, p2.end(), cur);
        if (it != p2.end())
        {
            // ll x = *it / 2 - p[i - 1];
            // ans = max(ans, (i128)sum * x - x * x);
            if (abs(sum - (*it - p2[i - 1])) < abss) abss = abs(sum - (*it - p2[i - 1])), x = *it / 2 - p[i - 1];
        }
        if (it != p2.begin())
        {
            // ll x = *(it - 1) / 2 - p[i - 1];
            // ans = max(ans, (i128)sum * x - x * x);
            if (abs(sum - (*(it - 1) - p2[i - 1])) < abss) abss = abs(sum - (*(it - 1) - p2[i - 1])), x = *(it - 1) / 2 - p[i - 1];
        }
    }
    ans = (((i128)sum % MOD * x % MOD - (i128)x % MOD * x % MOD) % MOD + MOD) % MOD;
    write(ans);
}

int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}