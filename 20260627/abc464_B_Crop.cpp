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
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> visx(n), visy(m);
    int stx1 = -1, sty1 = -1, stx2 = -1, sty2 = -1;
    for (int i = 0; i < n; i++)
    {
        if (stx1 != -1) break;
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '#')
            {
                stx1 = i;
                break;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (stx2 != -1) break;
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '#')
            {
                stx2 = i;
                break;
            }
        }
    }
    for (int j = 0; j < m; j++)
    {
        if (sty1 != -1) break;
        for (int i = 0; i < n; i++)
        {
            if (a[i][j] == '#')
            {
                sty1 = j;
                break;
            }
        }
    }
    for (int j = m - 1; j >= 0; j--)
    {
        for (int i = 0; i < n; i++)
        {
            if (sty2 != -1) break;
            if (a[i][j] == '#')
            {
                sty2 = j;
                break;
            }
        }
    }
    for (int i = stx1; i <= stx2; i++)
    {
        for (int j = sty1; j <= sty2; j++) cout << a[i][j];
        cout << '\n';
    }
    // cout << stx1 << ' ' << stx2 << ' ' << sty1 << ' ' << sty2 << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}