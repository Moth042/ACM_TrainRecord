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
    ll n, m, k;
    cin >> n >> m >> k;
    auto check = [&](ll mid) -> bool
    {
        ll cnt = 0;
        for (ll i = 1; i <= n; i++)
        {
            ll l = 1, r = m;
            while (l < r)
            {
                ll midd = (l + r + 1) >> 1;
                if (i * i - midd * midd >= mid) l = midd;
                else r = midd - 1;
            }
            if (i * i - l * l >= mid) cnt += l;
        }
        return cnt >= k;
    };
    ll l = 1 - m * m, r = n * n - 1;
    while (l < r)
    {
        ll mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    ll numk = l;
    // cout << numk << '\n';
    ll ans = 0, cnt = 0;
    for (ll i = 1; i <= n; i++)
    {
        l = 1, r = m;
        while (l < r)
        {
            ll mid = (l + r + 1) >> 1;
            if (i * i - mid * mid > numk) l = mid;
            else r = mid - 1;
        }
        ll cur = l;
        // cout << i << ' ' << cur << '\n';
        if (i * i - cur * cur > numk)
        {
            cnt += cur;
            ans += cur * i * i - cur * (cur + 1) * (cur * 2 + 1) / 6;
        }
    }
    ans += (k - cnt) * numk;
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}