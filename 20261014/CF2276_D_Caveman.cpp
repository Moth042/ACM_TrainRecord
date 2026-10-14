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
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> C(n + 1, -1);
    vector<vector<int>> cnt(2, vector<int>(n + 1));
    // bool ok = 1;
    auto dfs = [&](auto &&self, int u, int col) -> void
    {
        C[u] = col;
        // cnt[col]++;

        for (int v : g[u])
        {
            if (C[v] == -1) self(self, v, col ^ 1);
            // else if (C[v] == col) ok = 0;
        }
    };
    for (int i = 1; i <= n; i++)
    {
        if (g[i].size() == 0)
        {
            cout << "Brain Melt\n";
            return;
        }
    }
    int cc = 0;
    for (int i = 1; i <= n; i++)
    {
        if (C[i] == -1) dfs(dfs, i, 0), cc++;
    }
    if (cc >= 2)
    {
        cout << "Many\n";
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto j : g[i]) cnt[C[j]][i]++; // i邻居有 C[j]颜色
    }
    // for (int i = 1; i <= n; i++) cout << C[i] << " ";
    // cout << '\n';
    int ok = 0;
    for (int i = 1; i <= n; i++)
    {
        // if (g[i].size()>=2&&cnt[C[i]]) ok = 1;
        if (g[i].size() < 2) continue;
        for (auto j : g[i])
        {
            if (cnt[C[i]][j] > 1) ok = 1;
        }
    }
    if (ok) cout << "Many\n";
    else cout << 2 << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}