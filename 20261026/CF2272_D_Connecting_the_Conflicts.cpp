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
    int k;
    cin >> k;
    vector<vector<vector<int>>> g(k + 1);
    vector<int> sz(k + 1);
    for (int i = 1; i <= k; i++)
    {
        cin >> sz[i];
        g[i].assign(sz[i] + 1, {});
        for (int j = 1; j < sz[i]; j++)
        {
            int u, v;
            cin >> u >> v;
            g[i][u].push_back(v);
            g[i][v].push_back(u);
        }
    }
    int t = 1, c = 1;
    for (int i = 1; i <= k; i++)
    {
        if (sz[i] >= 2)
        {
            for (int j = 1; j <= sz[i]; j++)
            {
                if (g[i][j].size() == 1)
                {
                    t = i;
                    c = g[i][j][0];
                    break;
                }
            }
            break;
        }
    }
    for (int i = 1; i <= k; i++)
    {
        if (i == t) continue;
        cout << i << ' ' << 1 << ' ' << t << ' ' << c << '\n';
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