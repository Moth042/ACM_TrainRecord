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
    int n, m;
    cin >> n >> m;
    vector<int> p(11, 1 % m);
    for (int i = 1; i < 11; i++) p[i] = p[i - 1] * 10 % m;
    vector<int> a(n + 1), len(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        len[i] = to_string(a[i]).size();
    }
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m, vector<int>(m)));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++) dp[0][i][j] = -1;
    }
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (dp[i - 1][j][k] == -1) continue;
                int nj = (j + a[i]) % m, nk = (k * p[len[i]] + a[i]) % m;
                dp[i][nj][nk] = max(dp[i][nj][nk], dp[i - 1][j][k] + 1);
            }
        }
    }
    int mx = 0, cur = -1;
    for (int i = 0; i < m; i++)
    {
        if (mx < dp[n][i][i])
        {
            mx = dp[n][i][i];
            cur = i;
        }
    }
    int S = cur, C = cur;
    auto find = [&](int i, int S, int C) -> pair<int, int>
    {
        for (int s = 0; s < m; s++)
        {
            for (int c = 0; c < m; c++)
            {
                if ((s + a[i]) % m == S && (c * p[len[i]] + a[i]) % m == C && dp[i - 1][s][c] + 1 == dp[i][S][C]) return {s, c};
            }
        }
        return {-1, -1};
    };
    vector<int> ans;
    for (int i = n; i >= 1; i--)
    {
        if (dp[i][S][C] == dp[i - 1][S][C]) continue;
        auto [ps, pc] = find(i, S, C);
        ans.push_back(i);
        S = ps, C = pc;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto i : ans) cout << a[i] << ' ';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}