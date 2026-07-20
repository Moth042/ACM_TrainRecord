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
    vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(2)));
    int stx = -1, sty = -1, edx = -1, edy = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'S')
            {
                stx = i;
                sty = j;
            }
            if (a[i][j] == 'T')
            {
                edx = i;
                edy = j;
            }
        }
    }
    // cout << stx << ' ' << sty << ' ' << edx << ' ' << edy << '\n';
    queue<array<int, 4>> q;
    q.push({stx, sty, 0, 0});
    while (q.size())
    {
        auto [x, y, z, stp] = q.front();
        // cout << x << ' ' << y << ' ' << z << ' ' << stp << '\n';
        q.pop();
        if (x == edx && y == edy)
        {
            cout << stp << '\n';
            return;
        }
        if (vis[x][y][z]) continue;
        vis[x][y][z] = 1;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (a[nx][ny] != '#' && !vis[nx][ny][z]) q.push({nx, ny, z, stp + 1});
                if (a[nx][ny] == '#' && z == 0 && !vis[nx][ny][1]) q.push({nx, ny, 1, stp + 1});
            }
        }
    }
    cout << -1 << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}