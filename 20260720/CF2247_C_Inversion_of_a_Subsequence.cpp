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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int x0 = 0, x1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] && !b[i]) x0++;
        if (!a[i] && b[i]) x1++;
    }
    if (x0 == 0)
    {
        if (x1 == 0) cout << 0 << '\n';
        else
        {
            bool ok0 = 0, ok1 = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] == b[i])
                {
                    if (a[i] == 1) ok1 = 1;
                    else ok0 = 1;
                }
            }
            if (ok0 && ok1) cout << 2 << '\n';
            else cout << -1 << '\n';
        }
    }
    else
    {
        if (x1 == 0)
        {
            if (x0 % 2) cout << 1 << '\n';
            else cout << 2 << '\n';
        }
        else
        {
            if (x0 % 2) cout << 1 << '\n';
            else cout << 2 << '\n';
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}