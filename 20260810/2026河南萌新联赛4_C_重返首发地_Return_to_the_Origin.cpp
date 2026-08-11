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
    vector<vector<char>> a(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    }
    vector<vector<int>> d(n + 1, vector<int>(m + 1, 1e9));
    vector<vector<int>> vis(n + 1, vector<int>(m + 1));
    deque<pair<int, int>> q;
    // queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 'P')
            {
                q.push_back({i, j});
                // vis[i][j] = 1;
                d[i][j] = 0;
            }
        }
    }
    while (q.size())
    {
        auto [x, y] = q.front();
        // cout << x << ' ' << y << ' ' << z << '\n';
        q.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] != '#' && d[nx][ny] > d[x][y] + (a[x][y] == '1'))
            {
                d[nx][ny] = d[x][y] + (a[x][y] == '1');
                if (a[x][y] == '1') q.push_back({nx, ny});
                else q.push_front({nx, ny});
                // vis[nx][ny] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) cout << (d[i][j] == 1e9 ? -1 : d[i][j]) << " ";
        cout << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}