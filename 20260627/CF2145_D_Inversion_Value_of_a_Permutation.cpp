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
    int n, k;
    cin >> n >> k;
    int sum = n * (n - 1) / 2;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1)), p(n + 1, vector<int>(sum + 1));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (dp[i][j] == 0) continue;
            for (int s = 1; s + i <= n; s++)
            {
                int t = s * (s - 1) / 2;
                dp[i + s][j + t] = 1;
                p[i + s][j + t] = s;
            }
        }
    }
    sum -= k;
    int cur1 = n, cur2 = sum;
    if (sum >= 0 && dp[n][sum])
    {
        vector<int> ans1, ans2;
        while (cur1 > 0)
        {
            int y = p[cur1][cur2];
            ans1.push_back(y);
            cur1 -= y;
            cur2 -= y * (y - 1) / 2;
        }
        reverse(ans1.begin(), ans1.end());
        int st = n;
        for (auto i : ans1)
        {
            for (int j = st - i + 1; j <= st; j++) ans2.push_back(j);
            st -= i;
        }
        for (auto i : ans2) cout << i << ' ';
        cout << '\n';
    }
    else cout << 0 << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}