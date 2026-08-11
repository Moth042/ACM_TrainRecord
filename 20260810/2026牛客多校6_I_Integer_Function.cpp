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
    ll n, d;
    cin >> n >> d;
    vector<ll> dp(16);
    dp[0] = 1;
    for (int i = 0; i <= 60; i++)
    {
        vector<ll> ndp(16);
        int ni = n >> i & 1, di = d >> i & 1;
        for (int s = 0; s < 16; s++)
        {
            for (int x = 0; x < 2; x++)
            {
                int a = s & 1, b = s >> 1 & 1, c = s >> 2 & 1, e = s >> 3;
                int y = x + di + b, na = 0;
                if (ni - x - a < 0) na = 1;
                for (int u = 0; u <= (x && !c); u++)
                {
                    for (int v = 0; v <= ((y & 1) && !e); v++)
                    {
                        int ns = na | (y >> 1) << 1 | (c | u) << 2 | (e | v) << 3;
                        ndp[ns] += dp[s];
                        ndp[ns] %= MOD;
                    }
                }
            }
        }
        dp = move(ndp);
    }
    cout << dp[12] << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}