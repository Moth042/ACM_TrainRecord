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
    int n, m, s, t, k;
    cin >> n >> m >> s >> t >> k;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<int>> d(n + 1, vector<int>(n + 1, 1e9));
    for (int i = 1; i <= n; i++) d[i][i] = 0;
    auto bfs = [&](int st) -> void
    {
        queue<int> q;
        q.push(st);
        vector<int> vis(n + 1);
        while (q.size())
        {
            int x = q.front();
            q.pop();
            if (vis[x]) continue;
            vis[x] = 1;
            for (auto y : g[x])
            {
                if (!vis[y] && d[st][y] > d[st][x] + 1)
                {
                    d[st][y] = d[st][x] + 1;
                    q.push(y);
                }
            }
        }
    };
    for (int i = 1; i <= n; i++) bfs(i);
    queue<pair<int, int>> q;
    // map<pair<int, int>, int> mp;
    vector<vector<int>> ans(n + 1, vector<int>(n + 1, 1e9));
    ans[s][t] = 0;
    q.push({s, t});
    map<pair<int, int>, int> vis;
    while (q.size())
    {
        auto [s, t] = q.front();
        q.pop();
        // if (vis.count({s, t})) continue;
        // vis[{s, t}] = 1;
        for (auto y : g[s])
        {
            if (y != t && d[y][t] <= k && ans[y][t] > ans[s][t] + 1)
            {
                ans[y][t] = ans[s][t] + 1;
                q.push({y, t});
            }
        }
        for (auto y : g[t])
        {
            if (s != y && d[s][y] <= k && ans[s][y] > ans[s][t] + 1)
            {
                ans[s][y] = ans[s][t] + 1;
                q.push({s, y});
            }
        }
    }
    cout << (ans[t][s] == 1e9 ? -1 : ans[t][s]) << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}