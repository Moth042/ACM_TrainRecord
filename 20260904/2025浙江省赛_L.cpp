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
    vector<int> a(n + 1), vis(n + 1), deg(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i == a[i]) vis[i] = 1;
        else
        {
            g[i].push_back(a[i]);
            g[a[i]].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        sort(g[i].begin(), g[i].end());
        g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
    }
    for (int i = 1; i <= n; i++) deg[i] = g[i].size();
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            for (auto j : g[i])
            {
                if (!vis[j]) deg[j]--;
            }
        }
    }
    int ans = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i]) pq.push({deg[i], i});
    }
    while (pq.size())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (vis[u] || d != deg[u]) continue;
        vector<int> cur;
        cur.push_back(u);
        vis[u] = 1;
        ans++;
        for (auto v : g[u])
        {
            if (!vis[v])
            {
                cur.push_back(v);
                vis[v] = 1;
            }
        }
        for (auto x : cur)
        {
            for (auto y : g[x])
            {
                if (!vis[y])
                {
                    deg[y]--;
                    pq.push({deg[y], y});
                }
            }
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}