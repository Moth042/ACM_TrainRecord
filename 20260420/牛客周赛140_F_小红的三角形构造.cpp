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
map<ll, array<ll, 3>> mp;
void moth()
{
    ll n;
    cin >> n;
    if (n == 1 || n == 2) cout << "No\n";
    else
    {
        cout << "Yes\n";
        if (n % 2 == 0)
        {
            ll b = 1;
            ll nn = n;
            while (nn % 2 == 0)
            {
                nn /= 2;
                b *= 2;
            }
            if (nn == 1) cout << n << ' ' << n / 4 * 3 << ' ' << n / 4 * 5 << '\n';
            else
            {
                ll p = (nn * nn + 1) / 2;
                cout << n << ' ' << p * b << ' ' << (p - 1) * b << '\n';
            }
        }
        else
        {
            ll p = (n * n + 1) / 2;
            cout << n << ' ' << p << ' ' << p - 1 << '\n';
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