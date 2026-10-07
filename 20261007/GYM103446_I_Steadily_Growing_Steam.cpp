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
    int n, k;
    cin >> n >> k;
    vector<ll> v(n + 1), t(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) cin >> v[i] >> t[i], sum += t[i];
    vector<vector<ll>> dp(k + 1, vector<ll>(sum * 4 + 1, -1e18));
    dp[0][sum * 2] = 0;
    for (int i = 1; i <= n; i++)
    {
        auto ndp = dp;
        for (int j = 0; j <= k; j++)
        {
            for (int p = -sum * 2; p <= sum * 2; p++)
            {
                if (p + sum * 2 - t[i] >= 0) ndp[j][p + sum * 2] = max(ndp[j][p + sum * 2], dp[j][p + sum * 2 - t[i]] + v[i]);
                if (p + sum * 2 + t[i] <= sum * 4) ndp[j][p + sum * 2] = max(ndp[j][p + sum * 2], dp[j][p + sum * 2 + t[i]] + v[i]);
                if (j >= 1)
                {
                    if (p + sum * 2 - t[i] * 2 >= 0) ndp[j][p + sum * 2] = max(ndp[j][p + sum * 2], dp[j - 1][p + sum * 2 - t[i] * 2] + v[i]);
                    if (p + sum * 2 + t[i] * 2 <= sum * 4) ndp[j][p + sum * 2] = max(ndp[j][p + sum * 2], dp[j - 1][p + sum * 2 + t[i] * 2] + v[i]);
                }
            }
        }
        dp = move(ndp);
    }
    ll ans = -1e18;
    for (int i = 0; i <= k; i++) ans = max(ans, dp[i][sum * 2]);
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