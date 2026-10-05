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
    vector<string> a(3);
    for (int i = 0; i < 3; i++) cin >> a[i];
    vector<int> h(3), l(3);
    int z = 0, f = 0;
    for (int i = 0; i < 3; i++)
    {
        if (a[i][i] == '1') z++;
        if (a[i][2 - i] == '1') f++;
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] == '1')
            {
                h[i]++;
                l[j]++;
            }
        }
    }
    int x = -1, y = -1;
    if (z == 2)
    {
        // cout << "Yes\n";
        for (int i = 0; i < 3; i++)
        {
            if (a[i][i] == '*')
            {
                x = y = i + 1;
                break;
            }
        }
    }
    if (f == 2)
    {
        // cout << "Yes\n";
        for (int i = 0; i < 3; i++)
        {
            if (a[i][2 - i] == '*')
            {
                // cout << i + 1 << ' ' << 2 - i + 1 << '\n';
                x = i + 1;
                y = 2 - i + 1;
                break;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (h[i] == 2)
        {
            // cout << "Yes\n";
            for (int j = 0; j < 3; j++)
            {
                if (a[i][j] == '*')
                {
                    // cout << i + 1 << " " << j + 1 << '\n';
                    x = i + 1, y = j + 1;
                    break;
                }
            }
        }
    }
    for (int j = 0; j < 3; j++)
    {
        if (l[j] == 2)
        {
            for (int i = 0; i < 3; i++)
            {
                if (a[i][j] == '*')
                {
                    // cout << i + 1 << ' ' << j + 1 << '\n';
                    // return;
                    x = i + 1;
                    y = j + 1;
                    break;
                }
            }
        }
    }
    if (x == -1) cout << "No\n";
    else cout << "Yes\n" << x << ' ' << y << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}