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
    ll x;
    cin >> n >> k >> x;
    vector<ll> a(n + 1);
    int sz1 = n / 2, sz2 = n - n / 2;
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<unordered_map<ll, ll>>> dp(sz1 + 1, vector<unordered_map<ll, ll>>(k + 1));
    vector<vector<unordered_map<ll, ll>>> dp2(sz2 + 1, vector<unordered_map<ll, ll>>(k + 1));
    dp[0][0][0] = 1;
    for (int i = 0; i <= sz1; i++)
    {
        for (int j = 0; j <= min(k, i); j++)
        {
            for (auto [t, v] : dp[i][j])
            {
                if (i + 1 <= sz1)
                {
                    if (!dp[i + 1][j].count(t)) dp[i + 1][j][t] = dp[i][j][t] % mod;
                    else dp[i + 1][j][t] = (dp[i + 1][j][t] + dp[i][j][t]) % mod;
                    if (j + 1 <= k)
                    {
                        if (!dp[i + 1][j + 1].count(t ^ a[i + 1])) dp[i + 1][j + 1][t ^ a[i + 1]] = dp[i][j][t] % mod;
                        else dp[i + 1][j + 1][t ^ a[i + 1]] = (dp[i + 1][j + 1][t ^ a[i + 1]] + dp[i][j][t]) % mod;
                    }
                }
            }
        }
    }
    dp2[0][0][0] = 1;
    for (int i = 0; i <= sz2; i++)
    {
        for (int j = 0; j <= min(k, i); j++)
        {
            for (auto [t, v] : dp2[i][j])
            {
                if (i + 1 <= sz2)
                {
                    if (!dp2[i + 1][j].count(t)) dp2[i + 1][j][t] = dp2[i][j][t] % mod;
                    else dp2[i + 1][j][t] = (dp2[i + 1][j][t] + dp2[i][j][t]) % mod;
                    if (j + 1 <= k)
                    {
                        if (!dp2[i + 1][j + 1].count(t ^ a[sz1 + i + 1])) dp2[i + 1][j + 1][t ^ a[sz1 + i + 1]] = dp2[i][j][t] % mod;
                        else dp2[i + 1][j + 1][t ^ a[sz1 + i + 1]] = (dp2[i + 1][j + 1][t ^ a[sz1 + i + 1]] + dp2[i][j][t]) % mod;
                    }
                }
            }
        }
    }
    // cout << dp[1][1][1] << '\n';
    ll ans = 0;
    for (int i = 0; i <= k; i++)
    {
        for (auto [s, v] : dp[sz1][i])
        {
            ll t = x ^ s;
            if (dp2[sz2][k - i].count(t))
            {
                ll cur = dp[sz1][i][s] % mod * dp2[sz2][k - i][t] % mod;
                ans = (ans + cur) % mod;
            }
        }
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