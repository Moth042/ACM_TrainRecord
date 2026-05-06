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
vector<int> p, vis;
void sieve(int n)
{
    vis.assign(n + 1, 0);
    p.clear();
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i]) p.push_back(i);
        for (auto j : p)
        {
            if (i * j > n) break;
            vis[i * j] = 1; // 被标记的不是素数
            if (i % j == 0) break;
        }
    }
}
void moth()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> dp(n + 1, vector<int>(4, 1e9));
    // 0:不变1:改为1 2:改为偶数 3:改为非1奇数
    dp[1][0] = 0;
    dp[1][1] = dp[1][2] = dp[1][3] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[a[i] + a[i - 1]]) dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        if (!vis[a[i] + 1]) dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        if (a[i] % 2) dp[i][0] = min(dp[i][0], dp[i - 1][2]);
        else dp[i][0] = min(dp[i][0], dp[i - 1][3]);

        if (!vis[1 + a[i - 1]]) dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
        dp[i][1] = min(dp[i][1], dp[i - 1][1] + 1);
        dp[i][1] = min(dp[i][1], dp[i - 1][2] + 1);

        if (a[i - 1] % 2) dp[i][2] = min(dp[i][2], dp[i - 1][0] + 1);
        dp[i][2] = min(dp[i][2], dp[i - 1][1] + 1);
        dp[i][2] = min(dp[i][2], dp[i - 1][3] + 1);

        if (a[i - 1] % 2 == 0) dp[i][3] = min(dp[i][3], dp[i - 1][0] + 1);
        dp[i][3] = min(dp[i][3], dp[i - 1][2] + 1);
    }
    cout << *min_element(dp[n].begin(), dp[n].end()) << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    sieve(1e6);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}