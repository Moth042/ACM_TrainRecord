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
ll f[N], g[N];
ll ksm(ll a, ll b, ll c)
{
    ll res = 1;
    while (b)
    {
        if (b & 1) res = res * a % c;
        a = a * a % c;
        b >>= 1;
    }
    return res;
}
void init()
{
    f[0] = g[0] = 1;
    for (int i = 1; i < N; i++)
    {
        f[i] = f[i - 1] * i % MOD;
        g[i] = g[i - 1] * ksm(i, MOD - 2, MOD) % MOD;
    }
}
ll C(ll n, ll m)
{
    if (n < m) return 0;
    if (n < 0 || m < 0) return 0;
    return f[n] * g[m] % MOD * g[n - m] % MOD;
}
void moth()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector<int> cnt(n * m + 1);
    vector<vector<pair<int, int>>> col(n * m + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            cnt[a[i][j]]++;
        }
    }
    int b = sqrt(n * m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (cnt[a[i][j]] <= b) col[a[i][j]].push_back({i, j});
        }
    }
    ll ans = 0;
    for (int o = 1; o <= n * m; o++)
    {
        if (cnt[o] <= b)
        {
            sort(col[o].begin(), col[o].end());
            vector<ll> dp(cnt[o]);
            ll cur = 0;
            for (int i = 0; i < cnt[o]; i++)
            {
                auto [xi, yi] = col[o][i];
                dp[i] = C(xi + yi - 2, xi - 1);
                for (int j = 0; j < i; j++)
                {

                    auto [xj, yj] = col[o][j];
                    if (xj <= xi && yj <= yi) dp[i] = (dp[i] - dp[j] % MOD * C(xi - xj + yi - yj, xi - xj) % MOD + MOD) % MOD;
                }
                cur = (cur + dp[i] % MOD * C(n - xi + m - yi, n - xi) % MOD) % MOD;
            }
            ans += cur;
            ans %= MOD;
        }
        else
        {
            vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
            dp[1][0] = 1;
            ll cur = 0;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    dp[i][j] = dp[i - 1][j] * (a[i - 1][j] != o) + dp[i][j - 1] * (a[i][j - 1] != o);
                    dp[i][j] %= MOD;
                    if (a[i][j] == o) cur = (cur + dp[i][j] % MOD * C(n - i + m - j, n - i) % MOD) % MOD;
                }
            }
            ans += cur;
            ans %= MOD;
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    init();
    cin >> _;
    while (_--) moth();
    return 0;
}