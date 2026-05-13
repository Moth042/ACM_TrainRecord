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
struct dsu
{
    vector<int> fa, sz;
    int n;
    dsu(int len)
    {
        n = len;
        fa.resize(n + 1);
        sz.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) fa[i] = i;
    }
    int find(int x)
    {
        if (x == fa[x]) return x;
        return fa[x] = find(fa[x]);
    }
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
    bool merge(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        fa[y] = x;
        return true;
    }
};
void moth()
{
    int n, m;
    cin >> n >> m;
    vector<int> vis(m + 1, -1), p(n + 1);
    vector<vector<int>> g(n + 1);
    map<pair<int, int>, int> edge;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        for (int j = 1; j <= p[i]; j++)
        {
            int x;
            cin >> x;
            g[i].push_back(x);
            // if(vis[x]!=-1)edge[{vis[x],i}]++;
            vis[x] = i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto j : g[i])
        {
            if (vis[j] != -1) edge[{i, vis[j]}]++;
        }
    }
    vector<int> ans;
    bool ok = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i + 1 <= n && !ok && !edge.count({i, i + 1}))
        {
            ok = 1;
            ans.push_back(i + 1);
            ans.push_back(i);
            i++;
        }
        else ans.push_back(i);
    }
    if (ok)
    {
        cout << "Yes\n";
        for (auto i : ans) cout << i << " \n"[i == ans.back()];
    }
    else cout << "No\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}