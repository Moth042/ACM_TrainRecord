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
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    vector<int> d0(n + 1, 1e9), d1(n + 1, 1e9), col(n + 1, -1);
    d0[1] = 0;
    queue<array<int, 3>> q;
    q.push({1, 0, -1});
    while (q.size())
    {
        auto [x, d, c] = q.front();
        q.pop();
        for (auto [y, nc] : g[x])
        {
            if (nc == c) continue;
            if (d0[y] == 1e9)
            {
                d0[y] = d + 1;
                col[y] = nc;
                q.push({y, d + 1, nc});
            }
            else if (nc != col[y] && d1[y] == 1e9)
            {
                d1[y] = d + 1;
                q.push({y, d + 1, nc});
            }
        }
    }
    cout << (d0[n] >= 1e9 ? -1 : d0[n]) << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}