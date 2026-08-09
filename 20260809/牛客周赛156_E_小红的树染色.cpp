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
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // vector<int> d(n + 1);
    // int mx = 0, mxx = 0;
    // auto dfs = [&](auto &&self, int u, int fa) -> void
    // {
    //     for (auto v : g[u])
    //     {
    //         if (v == fa) continue;
    //         d[v] = d[u] + 1;
    //         if (s[v] == '1')
    //         {
    //             if (d[v] > mx)
    //             {
    //                 mxx = mx;
    //                 mx = d[v];
    //             }
    //             else if (d[v] > mxx) mxx = d[v];
    //         }
    //         self(self, v, u);
    //     }
    // };
    // dfs(dfs, 1, 0);
    // cout << mx << " " << mxx << '\n';
    auto bfs = [&](int u) -> vector<int>
    {
        queue<int> q;
        vector<int> vis(n + 1), d(n + 1);
        vis[u] = 1;
        q.push(u);
        while (q.size())
        {
            int x = q.front();
            q.pop();
            for (auto y : g[x])
            {
                if (!vis[y])
                {
                    vis[y] = 1;
                    d[y] = d[x] + 1;
                    q.push(y);
                }
            }
        }
        return d;
    };
    auto d1 = bfs(1);
    int mx1 = 0, mx2 = 0;
    int u = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1' && d1[i] > mx1)
        {
            mx1 = d1[i];
            u = i;
        }
    }
    auto du = bfs(u);
    int v = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1' && du[i] > mx2)
        {
            mx2 = du[i];
            v = i;
        }
    }
    auto dv = bfs(v);
    // cout << du[v] << '\n';
    for (int i = 1; i <= n; i++)
    {
        int ans = mx2;
        ans = max(ans, du[i]);
        ans = max(ans, dv[i]);
        cout << ans << '\n';
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