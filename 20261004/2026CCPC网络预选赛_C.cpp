#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
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
const long double eps = 1e-8;
void moth()
{
    ll w, x1, x2, yc, u, v;
    cin >> w >> x1 >> x2 >> yc >> u >> v;
    if (yc > w)
    {
        // cout << 1 << '\n';
        cout << 1.0 * w / v << '\n';
        return;
    }
    if (x2 * v + yc * u <= 0 || x1 * v + yc * u >= 0)
    {
        cout << (ld)w / v << '\n';
        return;
    }
    if (v * v == u * u)
    {
        // cout << 3 << '\n';
        ld mn = 1e18;
        if (x1 * u)
        {
            ld t1 = -(1.0 * x1 * x1 + yc * yc) / (x1 * u * 2);
            if (t1 > eps && t1 - mn < eps) mn = t1;
        }
        if (x2 * u)
        {
            ld t2 = -(1.0 * x2 * x2 + yc * yc) / (x2 * u * 2);
            if (t2 > eps && t2 - mn < eps) mn = t2;
        }
        cout << mn + 1.0 * (w - yc) / v << '\n';
    }
    else
    {
        // cout << 4 << '\n';
        i128 dt1 = (i128)4 * x1 * x1 * u * u + (i128)4 * (v * v - u * u) * (yc * yc + x1 * x1);
        i128 dt2 = (i128)4 * x2 * x2 * u * u + (i128)4 * (v * v - u * u) * (yc * yc + x2 * x2);
        ld mn = 1e18;
        if (dt1 >= 0)
        {
            ld tz1 = (1.0 * x1 * u * 2 + sqrtl((ld)dt1)) / ((v * v - u * u) * 2), tf1 = (1.0 * x1 * u * 2 - sqrtl((ld)dt1)) / ((v * v - u * u) * 2);
            if (tz1 > eps && tz1 - mn < eps) mn = tz1;
            if (tf1 > eps && tf1 - mn < eps) mn = tf1;
        }
        if (dt2 >= 0)
        {
            ld tz2 = (1.0 * x2 * u * 2 + sqrtl((ld)dt2)) / ((v * v - u * u) * 2), tf2 = (1.0 * x2 * u * 2 - sqrtl((ld)dt2)) / ((v * v - u * u) * 2);
            if (tz2 > eps && tz2 - mn < eps) mn = tz2;
            if (tf2 > eps && tf2 - mn < eps) mn = tf2;
        }
        cout << mn + 1.0 * (w - yc) / v << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cout << fixed << setprecision(10);
    cin >> _;
    while (_--) moth();
    return 0;
}