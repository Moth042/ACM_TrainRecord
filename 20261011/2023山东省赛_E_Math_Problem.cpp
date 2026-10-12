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
    ll n, k, m, a, b;
    cin >> n >> k >> m >> a >> b;
    if (k == 1)
    {
        if (n % m == 0) cout << 0 << '\n';
        else cout << -1 << '\n';
        return;
    }
    ll ans = 1e18;
    for (int i = 0; i <= 70; i++)
    {
        // if (n == 0) break;
        i128 kk = 1;
        for (int j = 0; j <= 70; j++)
        {
            // if (kk * (n + 1) - 1 > 4e18) break;
            i128 L = kk * n, R = kk * (n + 1) - 1;
            if (R / m * m >= L || n == 0)
            {
                // cout << i << ' ' << j << '\n';
                ans = min(ans, b * i + a * j);
                break;
            }
            kk *= k;
        }
        if (n == 0) break;
        n /= k;
    }
    if (ans == 1e18) ans = -1;
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}