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
    vector<vector<char>> a(4, vector<char>(n + 1));
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    }
    if (n > 8)
    {
        cout << 0 << '\n';
        return;
    }
    n = min(n, 8);
    vector<vector<int>> cur(4);
    vector<set<int>> curr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 3; j++) cur[j].clear();
        for (int j = 1; j <= 3; j++)
        {
            if (a[j][i] == '?')
            {
                cur[j].push_back(0);
                cur[j].push_back(1 << (j - 1));
            }
            else if (a[j][i] == '1') cur[j].push_back(1 << (j - 1));
            else cur[j].push_back(0);
        }

        for (int p = 0; p < cur[1].size(); p++)
        {
            for (int q = 0; q < cur[2].size(); q++)
            {
                for (int s = 0; s < cur[3].size(); s++)
                {
                    int ans = cur[1][p] + cur[2][q] + cur[3][s];
                    curr[i].insert(ans);
                }
            }
        }
    }
    int ans = 0;
    vector<int> vis(8);
    auto dfs = [&](auto &&self, int i) -> void
    {
        if (i == n + 1)
        {
            ans++;
            return;
        }
        for (auto j : curr[i])
        {
            if (!vis[j])
            {
                vis[j] = 1;
                self(self, i + 1);
                vis[j] = 0;
            }
        }
    };
    dfs(dfs, 1);
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