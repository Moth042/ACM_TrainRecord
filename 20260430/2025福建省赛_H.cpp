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
    int l, r;
    cin >> l >> r;
    vector<string> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] = " " + a[i];
    }
    vector<vector<vector<int>>> d(n + 1, vector<vector<int>>(m + 1, vector<int>(2, 1e9)));
    vector<vector<vector<int>>> vis(n + 1, vector<vector<int>>(m + 1, vector<int>(2)));
    d[1][1][0] = 0;
    queue<array<int, 3>> q;
    q.push({1, 1, 0});
    vis[1][1][0] = 1;
    auto check = [&](int x, int y, int z) -> bool
    {
        if (x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] == '1' && !vis[x][y][z]) return 1;
        return 0;
    };
    while (q.size())
    {
        auto [x, y, z] = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nx = x + ddx[i], ny = y + ddy[i];
            if (check(nx, ny, z ^ 1))
            {
                d[nx][ny][z ^ 1] = d[x][y][z] + 1;
                q.push({nx, ny, z ^ 1});
                vis[nx][ny][z ^ 1] = 1;
            }
        }
    }
    if (l != r)
    {
        int ans = 1e9;
        if (d[n][m][0] != 1e9) ans = min(ans, (d[n][m][0] + r - 1) / r);
        if (d[n][m][1] != 1e9) ans = min(ans, (d[n][m][1] + r - 1) / r);
        cout << (ans == 1e9 ? -1 : ans) << '\n';
    }
    else
    {
        if (r % 2 == 0)
        {
            if (d[n][m][0] == 1e9) cout << -1 << '\n';
            else cout << (d[n][m][0] + r - 1) / r << '\n';
        }
        else
        {
            int t1 = 1e9, t2 = 1e9;
            if (d[n][m][0] != 1e9) t2 = (d[n][m][0] + r - 1) / r;
            if (d[n][m][1] != 1e9) t1 = (d[n][m][1] + r - 1) / r;
            if (t2 != 1e9 && d[n][m][0] % 2 != t2 % 2) t2++;
            if (t1 != 1e9 && d[n][m][1] % 2 != t1 % 2) t1++;
            int t = min(t1, t2);
            cout << (t == 1e9 ? -1 : t) << '\n';
        }
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