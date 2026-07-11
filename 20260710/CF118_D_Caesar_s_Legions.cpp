#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int N = 1e5 + 9;
const int mod = 1e8;
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
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    vector<vector<vector<ll>>> dp(n1 + 1, vector<vector<ll>>(n2 + 1, vector<ll>(2, -1)));
    auto dfs = [&](auto &&self, int x1, int x2, int cur) -> ll
    {
        if (x1 == 0 && x2 == 0) return 1;
        if (dp[x1][x2][cur] != -1) return dp[x1][x2][cur];
        ll ans = 0;
        if (cur == 0)
        {
            for (int i = 1; i <= min(k1, x1); i++) ans = (ans + self(self, x1 - i, x2, 1)) % mod;
        }
        else
        {
            for (int i = 1; i <= min(k2, x2); i++) ans = (ans + self(self, x1, x2 - i, 0)) % mod;
        }
        dp[x1][x2][cur] = ans;
        return ans;
    };
    ll ans = dfs(dfs, n1, n2, 0) + dfs(dfs, n1, n2, 1);
    ans %= mod;
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