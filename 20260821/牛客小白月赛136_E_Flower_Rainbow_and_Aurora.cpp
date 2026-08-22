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
    string s;
};
void moth()
{
    int n, m;
    string s;
    cin >> n >> m >> s;
    auto R = [&](string s) -> string
    {
        string ss;
        ss += s[2];
        ss += s[0];
        ss += s[1];
        return ss;
    };
    vector<vector<char>> a(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    }
    queue<Node> q;
    vector<vector<map<string, int>>> d(n + 1, vector<map<string, int>>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) d[i][j][s] = d[i][j][R(s)] = d[i][j][R(R(s))] = 1e9;
    }
    d[n][m][s] = d[n][m][R(s)] = d[n][m][R(R(s))] = 0;
    q.push({n, m, s});
    q.push({n, m, R(s)});
    q.push({n, m, R(R(s))});
    while (q.size())
    {
        auto [x, y, curs] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            for (int j = 1; j <= 3; j++)
            {
                int nx = x + j * dx[i], ny = y + j * dy[i];
                if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                string nxs = R(curs);
                if (nxs[j - 1] != a[x][y]) continue;
                if (d[nx][ny][nxs] > d[x][y][curs] + 1)
                {
                    d[nx][ny][nxs] = d[x][y][curs] + 1;
                    q.push({nx, ny, nxs});
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (d[i][j][s] == 1e9) cout << -1 << " ";
            else cout << d[i][j][s] << " ";
        }
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