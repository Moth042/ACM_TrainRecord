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
    ll s;
    cin >> n >> s;
    vector<ll> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    auto check = [&](int k) -> bool
    {
        vector<vector<array<ll, 2>>> dp(n + 1, vector<array<ll, 2>>(k + 1, {(ll)1e18, (ll)1e18}));
        vector<vector<array<ll, 2>>> dp2(n + 2, vector<array<ll, 2>>(k + 1, {(ll)1e18, (ll)1e18}));
        dp[0][0][0] = 0;
        dp2[n + 1][0][0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1]);
                if (j > 0) dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j - 1][0]) + a[i];
            }
        }
        for (int i = n; i >= 1; i--)
        {
            for (int j = 0; j <= k; j++)
            {
                dp2[i][j][0] = min(dp2[i + 1][j][0], dp2[i + 1][j][1]);
                if (j > 0) dp2[i][j][1] = min(dp2[i][j][1], dp2[i + 1][j - 1][0]) + b[i];
            }
        }
        ll mn = 1e18;
        for (int i = 0; i <= n; i++)
        {
            mn = min(mn, dp[i][k][0] + min(dp2[i + 1][k][0], dp2[i + 1][k][1]));
            mn = min(mn, dp[i][k][1] + dp2[i + 1][k][0]);
        }
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 0; j <= k; j++)
        //     {
        //         for (int p = 0; p <= 1; p++)
        //         {
        //             cout << i << ' ' << j << ' ' << p << ' ' << dp[i][j][p] << ' ' << dp2[i][j][p] << '\n';
        //         }
        //     }
        // }
        return mn <= s;
    };
    // cout << check(2);
    int l = 0, r = n / 2;
    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
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