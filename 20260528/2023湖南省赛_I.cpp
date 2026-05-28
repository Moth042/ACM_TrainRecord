#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int N = 2e5 + 9;
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
int dp[N][10][2][2];
void moth()
{
    int n, A;
    string s1, s2;
    cin >> n >> s1 >> s2 >> A;
    vector<int> a(n + 1), b(n + 1);
    reverse(s1.begin(), s1.end());
    s1 = " " + s1;
    reverse(s2.begin(), s2.end());
    s2 = " " + s2;
    for (int i = 1; i <= n; i++)
    {
        a[i] = s1[i] - '0';
        b[i] = s2[i] - '0';
    }
    vector<int> tot(10);
    auto dfs = [&](auto &&self, int n, int sum, int up, int down) -> int
    {
        if (sum > A) return 0;
        if (n == 0)
        {
            if (sum == A) return 1;
            return 0;
        }
        if (dp[n][sum][up][down]) return dp[n][sum][up][down];
        int l = 0, r = 9;
        if (up) r = b[n];
        if (down) l = a[n];
        int res = 0;
        for (int i = l; i <= r; i++)
        {
            if (tot[i])
            {
                tot[i]++;
                res += self(self, n - 1, sum, up & (i == b[n]), down & (i == a[n]));
                res %= mod;
                tot[i]--;
            }
            else
            {
                tot[i]++;
                res += self(self, n - 1, sum + 1, up & (i == b[n]), down & (i == a[n]));
                res %= mod;
                tot[i]--;
            }
        }
        return dp[n][sum][up][down] = res;
    };
    cout << dfs(dfs, n, 0, 1, 1) % mod;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}