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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    // for (int i = 30000; i >= 0; i--)
    // {
    //     if (i % 2 && (b == 0 || d == 0)) continue;
    //     // int aa = a, bb = b, cc = c, dd = d;
    //     int sum1 = i, sum2 = i;
    //     int tyin = i / 2;
    //     sum1 -= min(tyin, a) * 2;
    //     if (sum1 > b) continue;
    //     int tyang = i / 2;
    //     sum2 -= min(tyang, c) * 2;
    //     if (sum2 > d) continue;
    //     cout << i * 2 << '\n';
    //     break;
    // }
    int ou1 = 0, ou2 = 0, ji1 = 0, ji2 = 0;
    if (b % 2 == 0)
    {
        ou1 = 2 * a + b;
        if (b) ji1 = ou1 - 1;
    }
    else
    {
        ji1 = 2 * a + b;
        ou1 = ji1 - 1;
    }
    if (d % 2 == 0)
    {
        ou2 = 2 * c + d;
        if (d) ji2 = ou2 - 1;
    }
    else
    {
        ji2 = 2 * c + d;
        ou2 = ji2 - 1;
    }
    cout << 2 * max(min(ou1, ou2), min(ji1, ji2)) << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}