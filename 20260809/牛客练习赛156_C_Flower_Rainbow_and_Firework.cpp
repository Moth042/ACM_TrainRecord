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
    int n, d, k;
    cin >> n >> d >> k;
    vector<vector<int>> dot;
    int h = 1;
    int st = 2;
    dot.push_back({1});
    vector<int> cur;
    while (st <= n)
    {
        cur.push_back(st);
        st++;
        if (h == 1)
        {
            if (cur.size() == dot.back().size() * k)
            {
                dot.push_back(cur);
                cur.clear();
                h++;
            }
        }
        else
        {
            if (cur.size() == dot.back().size() * (k - 1))
            {
                dot.push_back(cur);
                cur.clear();
                h++;
            }
        }
    }
    if (cur.size()) dot.push_back(cur), h++;
    // cout << dot.size() << '\n';
    // cout << h << '\n';
    vector<vector<int>> g(n + 1);
    int bian = 0;
    vector<pair<int, int>> ans;
    for (int i = 0; i < h - 1; i++)
    {
        int idx = 0;
        int du = 0;
        for (int j = 0; j < dot[i + 1].size(); j++)
        {
            if (du < (i == 0 ? k : k - 1))
            {
                // cout << dot[i][idx] << " " << dot[i + 1][j] << '\n';
                g[dot[i][idx]].push_back(dot[i + 1][j]);
                g[dot[i + 1][j]].push_back(dot[i][idx]);
                du++;
                ans.push_back({dot[i][idx], dot[i + 1][j]});
            }
            if (du == (i == 0 ? k : k - 1))
            {
                idx++;
                du = 0;
                // break;
            }
        }
    }
    if (ans.size() != n - 1)
    {
        cout << -1 << '\n';
        return;
    }
    auto bfs = [&](int u) -> vector<int>
    {
        vector<int> dis(n + 1, 0);
        queue<int> q;
        q.push(u);
        vector<int> vis(n + 1);
        vis[u] = 1;
        while (q.size())
        {
            int x = q.front();
            q.pop();
            for (auto y : g[x])
            {
                if (!vis[y])
                {
                    dis[y] = dis[x] + 1;
                    vis[y] = 1;
                    q.push(y);
                }
            }
        }
        return dis;
    };
    auto d1 = bfs(1);
    int u = 1;
    for (int i = 1; i <= n; i++)
    {
        if (d1[i] > d1[u]) u = i;
    }
    // cout << u << '\n';
    auto du = bfs(u);
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        if (du[i] > mx) mx = du[i];
    }
    // cout << mx << '\n';

    if (mx <= k)
    {
        for (auto [x, y] : ans) cout << x << ' ' << y << '\n';
    }
    else cout << -1 << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}