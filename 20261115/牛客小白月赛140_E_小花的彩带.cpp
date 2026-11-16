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
    int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    s = " " + s;
    array<int, 2> lst = {0, 0};
    vector<array<int, 2>> pos(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1') lst[1] = i;
        else if (s[i] == '0') lst[0] = i;
        pos[i][0] = lst[1];
        pos[i][1] = lst[0];
    }
    vector<array<ll, 2>> dp(n + 1), pre(n + 1);
    // dp[0][0] = dp[0][1] = 1;
    pre[0][0] = pre[0][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            int L = max(0, max(i - r, pos[i][1 - j]));
            int R = i - l;
            if (R >= 0 && L <= R) dp[i][j] = (pre[R][1 - j] - (L > 0 ? pre[L - 1][1 - j] : 0) + MOD) % MOD;
            pre[i][j] = (pre[i - 1][j] + dp[i][j]) % MOD;
        }
    }
    cout << (dp[n][0] + dp[n][1]) % MOD << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}