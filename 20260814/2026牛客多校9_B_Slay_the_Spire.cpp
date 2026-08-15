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
    ll x, a, b;
    cin >> x >> a >> b;
    if (a == 1)
    {
        ll c = max(a, b);
        cout << (x + c - 1) / c << '\n';
    }
    else
    {
        i128 ans = (x + b - 1) / b;
        ll l = 0, r = 1e5;
        auto check = [&](ll mid) -> bool { return ((i128)a * 2 + (a - 1) * (mid - 1)) * mid / 2 >= x; };
        while (l < r)
        {
            ll mid = (l + r) >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        // cout << l << '\n';
        ans = min(ans, (i128)l);
        for (ll i = 1; i <= l; i++)
        {
            i128 cur = ((i128)a * 2 + (a - 1) * (i - 1)) * i / 2;
            i128 p1 = (i128)a + (a - 1) * (i - 1);
            // cout << i << ' ' << cur << ' ' << p1 << ' ';
            i128 res = max((i128)0, x - cur);
            // cout << res << '\n';
            i128 L = 0, R = min(p1 + b, (i128)10000000);
            while (L < R)
            {
                ll mid = (L + R) >> 1;
                if (((i128)(p1 - 1 + b) + (p1 - mid + b)) * mid / 2 >= res) R = mid;
                else L = mid + 1;
            }
            // cout << L << '\n';
            res -= ((i128)p1 - 1 + b + p1 - L + b) * L / 2;
            res = max(res, (i128)0);
            // cout << i << " " << L << '\n';
            ans = min(ans, (i128)i + L + (res + b - 1) / b);
            // cout << ans << '\n';
            // cout << i << ' ';

            // cout << '\n';
            // ans = min(ans, (i128)i + (res + b - 1) / b);
        }
        // cout << ans << '\n';
        // cout << ans << '\n';
        // cout << check(7) << '\n';
        write(ans);
    }
}
int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}