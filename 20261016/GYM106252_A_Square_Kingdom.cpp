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
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    i128 l = 0, r = 1e20;
    auto check = [&](i128 x) -> bool
    {
        i128 ans = 0;
        for (ll d = 1; d * d <= k * 2; d++)
        {
            i128 cur = (x - (i128)a * d * d - b * d * 2) / (a * d * 2);
            ans += max((i128)0, min((i128)n - d, cur));
        }
        return ans >= k;
    };
    i128 res = 0;
    while (l <= r)
    {
        i128 mid = (l + r) >> 1;
        if (check(mid))
        {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    i128 g = __gcd(res, (i128)a);
    // cout << res / g << ' ' << a / g << '\n';
    write(res / g);
    putchar(' ');
    write(a / g);
}
int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}