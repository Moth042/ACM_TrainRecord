#include <bits/stdc++.h>
using namespace std;
#define int long long
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
    vector<int> a(n + 1), cnt(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] % 4)
        {
            cout << 0 << '\n';
            return;
        }
    }
    int s = 0, to4 = 0;
    vector<int> c(n + 1);
    vector<int> cur;
    vector<vector<int>> ans;
    for (int i = 1; i <= n; i++)
    {
        if (c[a[i]] == 0)
        {
            s++;
            cur.push_back(a[i]);
        }
        c[a[i]]++;
        if (c[a[i]] == 4)
        {
            to4++;
            if (s == to4)
            {
                ans.push_back(cur);
                to4 = s = 0;
                cur.clear();
                c.assign(n + 1, 0);
            }
        }
        else if (c[a[i]] > 4)
        {
            cout << 0 << '\n';
            return;
        }
    }
    int l = 0;
    int m = ans.size();
    vector<int> dp(m + 1), sum(m + 1), pos(n + 1);
    dp[0] = sum[0] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (auto j : ans[i - 1])
        {
            l = max(l, pos[j]);
            pos[j] = i;
        }
        dp[i] = (sum[i - 1] - (l == 0 ? 0 : sum[l - 1]) + MOD) % MOD;
        sum[i] = (sum[i - 1] + dp[i]) % MOD;
    }
    cout << dp[m] << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}