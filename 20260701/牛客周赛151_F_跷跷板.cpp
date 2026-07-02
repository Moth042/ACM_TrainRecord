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
    i128 n, l, W;
    // cin >> n >> l >> W;
    n = read(), l = read(), W = read();
    vector<i128> x(n + 1), w(n + 1);
    i128 answ = 0, ansxw = 0;
    for (int i = 1; i <= n; i++)
    {
        x[i] = read();
        w[i] = read();
        answ += w[i];
        ansxw += x[i] * w[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        i128 x1 = 2 * (ansxw - x[i] * w[i]) + W * l, x2 = 2 * (answ - w[i]) + 2 * W;
        if (x1 % x2 == 0)
        {
            i128 p = x1 / x2;
            if (p >= 0 && p <= l) ans++;
        }
    }
    cout << ans << '\n';
}
int main()
{
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}