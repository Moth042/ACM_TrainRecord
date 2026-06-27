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
struct Node
{
    int x, y;
    char c;
};
void moth()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<Node> Q(q + 1);
    for (int i = 1; i <= q; i++) cin >> Q[i].x >> Q[i].y >> Q[i].c;
    vector<vector<char>> ans(n + 1, vector<char>(m + 1, 'A'));
    vector<vector<int>> vis(n + 1, vector<int>(m + 1));
    auto dfs = [&](auto &&self, int x, int y, char c) -> void
    {
        if (x < 1 || y < 1 || vis[x][y]) return;
        ans[x][y] = c;
        vis[x][y] = 1;
        self(self, x - 1, y, c);
        self(self, x, y - 1, c);
    };
    for (int i = q; i >= 1; i--) dfs(dfs, Q[i].x, Q[i].y, Q[i].c);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) cout << ans[i][j];
        cout << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}