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
    vector<string> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] = " " + a[i];
    }
    vector<vector<int>> vis(n + 1, vector<int>(m + 1));
    auto bfs1 = [&](int x, int y) -> int
    {
        queue<pair<int, int>> q;
        q.push({x, y});
        vis[x][y] = 1;
        int sz = 0;
        while (q.size())
        {
            auto [x, y] = q.front();
            q.pop();
            sz++;
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny] && a[nx][ny] == '1')
                {
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
        return sz;
    };
    auto bfs2 = [&](int x, int y) -> int
    {
        queue<pair<int, int>> q;
        q.push({x, y});
        vis[x][y] = 1;
        int sz = 0;
        while (q.size())
        {
            auto [x, y] = q.front();
            q.pop();
            sz++;
            for (int i = 0; i < 8; i++)
            {
                int nx = x + ddx[i], ny = y + ddy[i];
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny] && a[nx][ny] == '1')
                {
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
        return sz;
    };
    int c4 = 0, c8 = 0, s4 = 0, s8 = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!vis[i][j] && a[i][j] == '1') s4 = max(s4, bfs1(i, j)), c4++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) vis[i][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!vis[i][j] && a[i][j] == '1') c8++, s8 = max(s8, bfs2(i, j));
        }
    }
    cout << c4 - c8 << ' ' << s4 << ' ' << s8 << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}