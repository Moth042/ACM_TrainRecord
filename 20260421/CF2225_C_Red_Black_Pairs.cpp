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
    vector<vector<char>> a(3, vector<char>(n + 1));
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    }
    // vector<vector<int>> vis(3, vector<int>(n + 1));
    // int ans = 0;
    // for (int i = 1; i <= 2; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         if (vis[i][j]) continue;
    //         vis[i][j] = 1;
    //         bool ok = 1;
    //         for (int k = 0; k < 4; k++)
    //         {
    //             int nx = i + dx[k], ny = j + dy[k];
    //             if (nx >= 1 && nx <= 2 && ny >= 1 && ny <= n && !vis[nx][ny])
    //             {
    //                 if (a[nx][ny] == a[i][j])
    //                 {
    //                     vis[nx][ny] = 1;
    //                     ok = 0;
    //                     break;
    //                 }
    //             }
    //         }
    //         if (ok)
    //         {
    //             ans++;
    //             for (int k = 0; k < 4; k++)
    //             {
    //                 int nx = i + dx[k], ny = j + dy[k];
    //                 if (nx >= 1 && nx <= 2 && ny >= 1 && ny <= n && !vis[nx][ny])
    //                 {
    //                     if (a[nx][ny] != a[i][j])
    //                     {
    //                         vis[nx][ny] = 1;
    //                         ok = 0;
    //                         break;
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }
    // cout << ans << '\n';
    vector<int> dp(n + 1);
    dp[1] = (a[1][1] != a[2][1]);
    for (int i = 2; i <= n; i++)
        dp[i] = min(dp[i - 1] + (a[1][i] != a[2][i]), dp[i - 2] + (a[1][i] != a[1][i - 1]) + (a[2][i] != a[2][i - 1]));
    cout << dp[n] << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}