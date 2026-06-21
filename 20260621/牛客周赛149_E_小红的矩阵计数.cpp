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
    vector<vector<ll>> dp(n + 1, vector<ll>(4));
    vector<vector<char>> a(3, vector<char>(n + 1));
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    }
    if (a[1][1] != '?' && a[2][1] != '?')
    {
        int t = (a[1][1] - '0') * 2 + (a[2][1] - '0');
        for (int j = 0; j <= 3; j++)
        {
            if (j != t) dp[1][j] = -1;
        }
    }
    else if (a[1][1] != '?')
    {
        if (a[1][1] == '0') dp[1][2] = dp[1][3] = -1;
        else dp[1][0] = dp[1][1] = -1;
    }
    else if (a[2][1] != '?')
    {
        if (a[2][1] == '0') dp[1][1] = dp[1][3] = -1;
        else dp[1][2] = dp[1][0] = -1;
    }
    else dp[1][0] = dp[1][1] = dp[1][2] = dp[1][3] = 1;
    for (int i = 0; i <= 3; i++)
    {
        if (dp[1][i] != -1) dp[1][i] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        if (a[1][i] != '?' && a[2][i] != '?')
        {
            int t = (a[1][i] - '0') * 2 + (a[2][i] - '0');
            for (int j = 0; j <= 3; j++)
            {
                if (j != t) dp[i][j] = -1;
            }
        }
        else if (a[1][i] != '?')
        {
            if (a[1][i] == '0') dp[i][2] = dp[i][3] = -1;
            else dp[i][0] = dp[i][1] = -1;
        }
        else if (a[2][i] != '?')
        {
            if (a[2][i] == '0') dp[i][1] = dp[i][3] = -1;
            else dp[i][2] = dp[i][0] = -1;
        }
        // else dp[i][0] = dp[1][1] = dp[1][2] = dp[1][3] = 1;
        for (int j = 0; j <= 3; j++)
        {
            if (dp[i][j] == -1) continue;
            if (j == 0)
            {
                for (int k = 1; k <= 3; k++)
                {
                    if (dp[i - 1][k] != -1) dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                }
            }
            else if (j == 3)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (dp[i - 1][k] != -1) dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                }
            }
            else
            {
                for (int k = 0; k <= 3; k++)
                {
                    if (dp[i - 1][k] != -1) dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= 3; i++)
    {
        if (dp[n][i] != -1)
        {
            ans += dp[n][i];
            ans %= MOD;
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j <= 3; j++) cout << dp[i][j] << " ";
    //     cout << '\n';
    // }
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