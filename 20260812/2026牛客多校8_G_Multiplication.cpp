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
    int a, b, c;
    cin >> a >> b >> c;
    int mx = max(a, b);
    if (mx == 1) cout << 17 << ' ' << 13 << ' ' << 17 << ' ' << 13 << '\n';
    else
    {
        string x1 = "1", y1 = "1", x2 = "1", y2 = "1";
        for (int i = 1; i <= mx - 1; i++)
        {
            x1 += '9';
            x2 += '9';
            y1 += '0';
            y2 += '0';
        }
        x1 += '9';
        x2 += '0';
        y1 += '9';
        y2 += '0';
        cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
        // cout << stoll(x1) * stoll(y1) << ' ' << stoll(x2) * stoll(y2) << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}