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
    // for (int i = 1; i <= 200; i++)
    // {
    //     int ans = 0;
    //     for (int j = 1; j <= i; j++)
    //     {
    //         for (int k = 1; k <= i; k++)
    //         {
    //             if (j % k + 1 == j % (k + 1)) ans++;
    //         }
    //     }
    //     cout << i << ' ' <<ans << '\n';
    // }
    ll n;
    cin >> n;
    // for (int i = 1; i <= n; i++) cout << i << " " << cnt[i] << "\n";
    ll ans = 0;
    for (ll j = 1; j * j <= n; j++)
    {
        ll cnt = n / (j * (j + 1));
        ll p = n % (j * (j + 1));
        ll sum = 0;
        // cout << cnt << " " << p << '\n';
        if (p >= j * j)
        {
            ll x1 = (cnt)*j * (j + 1) + j * j;
            sum += cnt * j;
            sum += min(j, n - x1 + 1);
        }
        else
        {
            sum += (cnt - 1) * j;
            ll x1 = (cnt - 1) * j * (j + 1) + j * j;
            sum += min(n - x1 + 1, j);
        }
        // cout << j << " " << sum << '\n';
        ans += sum;
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}