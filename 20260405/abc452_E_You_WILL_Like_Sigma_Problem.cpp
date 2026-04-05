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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    vector<ll> p1(n + 1), p2(n + 1);
    for (int i = 1; i <= n; i++)
    {
        p1[i] = (p1[i - 1] + a[i]) % MOD;
        p2[i] = (p2[i - 1] + a[i] * i) % MOD;
    }
    ll ans = 0;
    for (int j = 1; j <= m; j++)
    {
        for (int k = 0; k <= n / j; k++)
        {
            int l = j * k, r = min(j * (k + 1) - 1, n);
            ll sum1, sum2;
            if (l == 0)
            {
                sum1 = b[j] * p2[r] % MOD;
                sum2 = b[j] * j % MOD * k % MOD * p1[r] % MOD;
            }
            else
            {
                sum1 = b[j] * (p2[r] - p2[l - 1] + MOD) % MOD;
                sum2 = b[j] * j % MOD * k % MOD * (p1[r] - p1[l - 1] + MOD) % MOD;
            }
            ans = (ans + (sum1 - sum2 + MOD) % MOD) % MOD;
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--)
        moth();
    return 0;
}