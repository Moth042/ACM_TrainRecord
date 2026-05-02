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
    string s;
    cin >> s;
    int n = s.length();
    s = " " + s;
    vector<vector<ll>> dp(n + 1, vector<ll>(27));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 26; j++)
        {
            dp[i][j] = (s[i] == (char)(j + 96)) + dp[i - 1][j];
            if ((char)(j + 96) == s[i])
            {
                for (int k = 1; k <= 26; k++)
                {
                    if (k != j) dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                }
            }
        }
    }
    // cout<<dp[3][2]<<'\n';
    ll ans = 0;
    for (int i = 1; i <= 26; i++)
    {
        ans += dp[n][i];
        ans %= MOD;
    }
    cout << ans << '\n';
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=26;j++)cout<<dp[i][j]<<" \n"[j==26];
    // }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}