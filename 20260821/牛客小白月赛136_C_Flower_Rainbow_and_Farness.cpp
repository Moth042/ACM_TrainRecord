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
    ll n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    string s;
    cin >> s;
    int l, r, u, d;
    l = r = u = d = 0;
    for (auto i : s)
    {
        if (i == 'L') l++;
        else if (i == 'R') r++;
        else if (i == 'U') u++;
        else d++;
    }
    ll ans = 0;
    int st = 0;
    ll nx1 = x1, nx2 = x2, ny1 = y1, ny2 = y2;
    ll D = 0;
    // ld
    nx1 -= l;
    ny1 -= d;
    nx2 += r;
    ny2 += u;
    D = abs(nx1 - nx2) + abs(ny1 - ny2);
    if (D > ans)
    {
        ans = D;
        st = 1;
    }
    // rd
    nx1 = x1, nx2 = x2, ny1 = y1, ny2 = y2;
    D = 0;
    nx1 += r;
    ny1 -= d;
    nx2 -= l;
    ny2 += u;
    D = abs(nx1 - nx2) + abs(ny1 - ny2);
    if (D > ans)
    {
        ans = D;
        st = 2;
    }
    // lu
    nx1 = x1, nx2 = x2, ny1 = y1, ny2 = y2;
    D = 0;
    nx1 -= l;
    ny1 += u;
    nx2 += r;
    ny2 -= d;
    D = abs(nx1 - nx2) + abs(ny1 - ny2);
    if (D > ans)
    {
        ans = D;
        st = 3;
    }
    // ru
    nx1 = x1, nx2 = x2, ny1 = y1, ny2 = y2;
    D = 0;
    nx1 += r;
    ny1 += u;
    nx2 -= l;
    ny2 -= d;
    D = abs(nx1 - nx2) + abs(ny1 - ny2);
    if (D > ans)
    {
        ans = D;
        st = 4;
    }
    cout << ans << '\n';
    if (st == 1)
    {
        for (auto i : s)
        {
            if (i == 'L' || i == 'D') cout << "A";
            else cout << "B";
        }
    }
    else if (st == 2)
    {
        for (auto i : s)
        {
            if (i == 'R' || i == 'D') cout << "A";
            else cout << "B";
        }
    }
    else if (st == 3)
    {
        for (auto i : s)
        {
            if (i == 'L' || i == 'U') cout << "A";
            else cout << "B";
        }
    }
    else
    {
        for (auto i : s)
        {
            if (i == 'R' || i == 'U') cout << "A";
            else cout << "B";
        }
    }
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}