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
    // for (ll i = 1; i <= 32; i <<= 1)
    // {
    //     ll ans = 0;
    //     for (int j = 1; j <= 10; j++)
    //     {
    //         ans ^= i * j;
    //         cout << ans << ' ';
    //     }
    //     cout << '\n';
    // }
    ll l, r, x;
    cin >> l >> r >> x;
    auto cal = [&](ll p) -> i128
    {
        ll b = p / x;
        if (b % 4 == 0) return (i128)x * b;
        if (b % 4 == 3) return 0;
        if (b % 4 == 2) return (i128)x * (b + 1);
        return x;
    };
    i128 ans = cal(r) ^ cal(l - 1);
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