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
    vector<vector<int>> a(n + 1, vector<int>(m + 1)), d(n + 10, vector<int>(m + 10));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    }
    auto cal = [&](int x1, int y1, int x2, int y2, int v) -> void
    {
        x1 = max(x1, 1);
        y1 = max(y1, 1);
        x2 = min(x2, n);
        y2 = min(y2, m);
        if (x1 > x2 || y1 > y2) return;
        d[x1][y1] += v;
        d[x1][y2 + 1] -= v;
        d[x2 + 1][y1] -= v;
        d[x2 + 1][y2 + 1] += v;
    };
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int t = a[i][j];
            cal(i - t, j - t, i + t, j + t, 1);
            if (t) cal(i - t + 1, j - t + 1, i + t - 1, j + t - 1, -1);
        }
    }
    vector<vector<int>> ans(n + 1, vector<int>(m + 1));
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ans[i][j] = ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1] + d[i][j];
            mx = max(mx, ans[i][j]);
        }
    }
    cout << n * m - mx << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}