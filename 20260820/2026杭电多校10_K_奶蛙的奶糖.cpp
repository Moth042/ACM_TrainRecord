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
    ll x;
    cin >> x;
    // cout << __builtin_popcount(135) << ' ' << (135 >> 1) << '\n';
    for (ll i = 1; i <= 40; i++)
    {
        ll cur = i * i * i * 2;
        ll t = __builtin_popcount(cur), t2 = __builtin_popcount(cur + 1);
        if (t == i && cur >= x && cur <= 1e9)
        {
            cout << cur << '\n';
            return;
        }
        if (t2 == i && cur + 1 >= x && cur + 1 <= 1e9)
        {
            cout << cur + 1 << '\n';
            return;
        }
        // cout << t << ' ' << i << '\n';
        // if (t > i) continue;
        // else if (t == i)
        // {
        //     if (cur >= x && cur <= 1e9)
        //     {
        //         cout << cur << '\n';
        //         return;
        //     }
        // }
        // else
        // {
        //     // cout << 3 << '\n';
        //     for (ll j = 0; j < 32; j++)
        //     {
        //         if (t == i) break;
        //         if (((cur >> j) & 1) == 0)
        //         {
        //             cur |= (1ll << j);
        //             t++;
        //         }
        //     }
        //     if (t == i && cur >= x && cur <= 1e9)
        //     {
        //         cout << cur << '\n';
        //         return;
        //     }
        // }
    }

    cout << -1 << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}