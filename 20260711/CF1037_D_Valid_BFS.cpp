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
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dep(n + 1), f(n + 1);
    auto dfs = [&](auto &&self, int u, int fa) -> void
    {
        dep[u] = dep[fa] + 1;
        f[u] = fa;
        for (auto v : g[u])
        {
            if (v == fa) continue;
            self(self, v, u);
        }
    };
    dfs(dfs, 1, 0);
    // for (int i = 1; i <= n; i++) cout << dep[i] << " ";
    // cout << '\n';
    map<int, int> mp;
    for (int i = 1; i <= n; i++) mp[dep[i]]++;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (a[1] != 1)
    {
        cout << "No\n";
        return;
    }
    // map<int, int> mp2;
    // vector<int> cnt(n + 1);
    // for (int i = 1; i <= n; i++)
    // {
    //     if (i == 1) mp2[dep[a[1]]]++;
    //     else
    //     {
    //         if (f[a[i]] != f[a[i - 1]])
    //         {
    //             int fa = f[a[i - 1]];
    //             if (cnt[fa] != g[fa].size() - (fa > 1))
    //             {
    //                 cout << "No\n";
    //                 return;
    //             }
    //         }
    //         if (dep[a[i]] < dep[a[i - 1]])
    //         {
    //             cout << "No\n";
    //             return;
    //         }
    //         if (dep[a[i]] != dep[a[i - 1]] && mp2[dep[a[i - 1]]] != mp[dep[a[i - 1]]])
    //         {
    //             cout << "No\n";
    //             return;
    //         }
    //         mp2[dep[a[i]]]++;
    //         cnt[f[a[i]]]++;
    //     }
    // }
    // cout << "Yes\n";
    // vector<vector<int>> c(n + 1);
    // c[1].push_back(1);
    // for (int i = 2; i <= n; i++)
    // {
    //     if (dep[a[i]] < dep[a[i - 1]])
    //     {
    //         cout << "No\n";
    //         return;
    //     }
    //     c[dep[a[i]]].push_back(a[i]);
    //     if (c[dep[a[i]]].size() == mp[dep[a[i]]])
    //     {
    //         int l = 0, r = 0;
    //         int dd = dep[a[i]];
    //         while (l < c[dd - 1].size() && r < c[dd].size())
    //         {
    //             if (r < c[dd].size() && f[c[dd][r]] == c[dd - 1][l]) r++;
    //             else l++;
    //             if (l < c[dd - 1].size() && (r < c[dd].size() && f[c[dd][r]] != c[dd - 1][l]))
    //             {
    //                 cout << "No\n";
    //                 return;
    //             }
    //         }
    //     }
    // }
    // cout << "Yes\n";
    queue<int> q;
    int st = 2;
    q.push(1);
    vector<int> vis(n + 1);
    vis[1] = 1;
    while (q.size())
    {
        int x = q.front();
        int son = 0;
        if (x == 1) son = g[1].size();
        else son = g[x].size() - 1;
        q.pop();
        int num = 0;
        while (st <= n && f[a[st]] == x)
        {
            q.push(a[st]);
            vis[a[st]] = 1;
            st++;
            num++;
        }
        if (num != son)
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}