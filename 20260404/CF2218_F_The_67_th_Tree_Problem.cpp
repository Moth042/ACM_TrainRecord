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
        if (c == '-')
            s = -1;
        c = getchar();
    }
    return x * s;
}
// 快写
void write(i128 x)
{
    if (x > 9)
        write(x / 10);
    putchar(x % 10 | 48);
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int randint(int l, int r)
{
    return uniform_int_distribution{l, r}(rnd);
}
void moth()
{
    int x, y;
    cin >> x >> y;
    if (x > y)
        cout << "NO\n";
    // else if (x == y)
    // {
    //     if (x == 1)
    //     {
    //         cout << "YES\n";
    //         cout << 1 << ' ' << 2 << '\n';
    //     }
    //     else
    //         cout << "NO\n";
    // }
    else
    {
        if (x == 0 && y % 2 == 0)
            cout << "NO\n";
        else
        {
            cout << "YES\n";
            int t = (x + y) % 2;
            int n = x + y;
            if (t == 1)
                y--;
            else
                x--;

            // cout << x << '\n';
            if (x)
            {
                for (int i = n; i >= n - (x - 1) * 2; i -= 2)
                {
                    cout << i << ' ' << i - 1 << '\n';
                    cout << 1 << ' ' << i - 1 << '\n';
                }
            }
            // cout << n - x * 2 << '\n';
            for (int i = n - x * 2; i >= 2; i--)
                cout << 1 << ' ' << i << '\n';
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--)
        moth();
    return 0;
}