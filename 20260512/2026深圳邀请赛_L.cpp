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
    ll n, m;
    cin >> n >> m;
    vector<array<ll, 3>> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
    vector<vector<double>> dp(n + 1, vector<double>(m + 1));
    sort(a.begin() + 1, a.end(), [&](array<ll, 3> &x, array<ll, 3> &y) { return x[1] < y[1]; });
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i][2])
                dp[i][j] =
                    max(dp[i][j], dp[i - 1][j - a[i][2]] * 1.0 * (100 - a[i][0]) / 100 + 1.0 * a[i][0] / 100 * a[i][1]);
        }
    }
    cout << dp[n][m] << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cout << fixed << setprecision(18);
    cin >> _;
    while (_--) moth();
    return 0;
}