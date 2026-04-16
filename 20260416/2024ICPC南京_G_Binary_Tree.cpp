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
int query(int x, int y)
{
    cout << "? " << x << ' ' << y << endl;
    cout.flush();
    int t;
    cin >> t;
    return t;
}
void answer(int x)
{
    cout << "! " << x << endl;
    cout.flush();
}
void moth()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        if (l) g[i].push_back(l), g[l].push_back(i);
        if (r) g[i].push_back(r), g[r].push_back(i);
    }
    int s = 1;
    while (1)
    {
        vector<int> sz(n + 1), mx(n + 1);
        auto dfs = [&](auto &&self, int u, int fa) -> void
        {
            sz[u] = 1;
            for (auto v : g[u])
            {
                if (v == fa) continue;
                self(self, v, u);
                sz[u] += sz[v];
                mx[u] = max(mx[u], sz[v]);
            }
        };
        dfs(dfs, s, 0);
        int w = -1, tot = sz[s];
        for (int i = 1; i <= n; i++)
        {
            mx[i] = max(mx[i], tot - sz[i]);
            if (sz[i] && mx[i] * 2 <= tot) w = i;
        }
        if (g[w].size() == 0)
        {
            answer(w);
            return;
        }
        if (g[w].size() == 1)
        {
            int t = query(w, g[w][0]);
            if (t == 0) answer(w);
            else answer(g[w][0]);
            return;
        }
        sort(g[w].begin(), g[w].end(), [&](const int &u, const int &v) { return mx[u] < mx[v]; });
        int u = g[w][0], v = g[w][1];
        int t = query(u, v);
        if (t == 0)
        {
            s = u;
            g[s].erase(find(g[s].begin(), g[s].end(), w));
        }
        else if (t == 2)
        {
            s = v;
            g[s].erase(find(g[s].begin(), g[s].end(), w));
        }
        else
        {
            s = w;
            g[s].erase(g[s].begin());
            g[s].erase(g[s].begin());
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