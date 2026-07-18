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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> id(n + 1, vector<int>(m + 1));
    vector<int> fa(4 * q + 10), sz(4 * q + 10), mx(4 * q + 10), a(4 * q + 10);
    auto find = [&](auto &&self, int x) -> int
    {
        if (x == fa[x]) return x;
        int y = self(self, fa[x]);
        mx[x] = max(mx[x], mx[fa[x]]);
        return fa[x] = y;
    };
    int cnt = 0, lst = 0;
    while (q--)
    {
        int op, x, y;
        cin >> op >> x >> y;
        x ^= lst;
        y ^= lst;
        if (op == 1)
        {
            int w;
            cin >> w;
            int u = ++cnt;
            a[u] = w;
            id[x][y] = u;
            sz[u] = 1;
            fa[u] = u;
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && id[nx][ny])
                {
                    int v = id[nx][ny];
                    int fu = find(find, u), fv = find(find, v);
                    if (fu != fv)
                    {
                        int rt = ++cnt;
                        sz[rt] = sz[fu] + sz[fv];
                        fa[rt] = fa[fu] = fa[fv] = rt;
                        mx[fu] = w - sz[fu] + 1;
                        mx[fv] = w - sz[fv] + 1;
                    }
                }
            }
            lst = sz[find(find, u)] - 1;
            cout << sz[find(find, u)] - 1 << '\n';
        }
        else
        {
            find(find, id[x][y]);
            lst = max(mx[id[x][y]] - a[id[x][y]], 0);
            cout << max(mx[id[x][y]] - a[id[x][y]], 0) << '\n';
        }
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