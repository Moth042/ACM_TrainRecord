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
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<pair<int, int>> b, g;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'G') g.push_back({i, j});
            if (a[i][j] == 'B') b.push_back({i, j});
        }
    }
    if (g.size() == 0)
    {
        cout << "Yes\n";
        return;
    }
    for (auto [x, y] : b)
    {
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == '.') a[nx][ny] = '#';
        }
    }
    vector<vector<int>> ok(n, vector<int>(m + 1));
    auto bfs = [&](int x, int y) -> void
    {
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m));
        vis[x][y] = 1;
        ok[x][y] = 1;
        q.push({x, y});
        while (q.size())
        {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] != '#' && !vis[nx][ny])
                {
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                    ok[nx][ny] = 1;
                }
            }
        }
    };
    bfs(n - 1, m - 1);
    for (auto [x, y] : g)
    {
        if (!ok[x][y])
        {
            cout << "No\n";
            return;
        }
    }
    for (auto [x, y] : b)
    {
        if (ok[x][y])
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}