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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1);
    vector<vector<int>> g(n + 1), c(51);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c[a[i]].push_back(i);
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    bool ok = 1;
    for (int col = 1; col <= 50 && ok; col++)
    {
        if (c[col].size() == 0) continue;
        queue<pair<int, int>> q;
        vector<int> f1(n + 1, -1), d1(n + 1, 1e9), f2(n + 1, -1), d2(n + 1, 1e9);
        for (auto x : c[col])
        {
            d1[x] = 0;
            f1[x] = x;
            q.push({x, x});
        }
        while (q.size() && ok)
        {
            auto [u, st] = q.front();
            q.pop();
            int curd;
            if (f1[u] == st) curd = d1[u];
            else if (f2[u] == st) curd = d2[u];
            else continue;
            for (auto v : g[u])
            {
                int nd = curd + 1;
                if (a[v] == col && st != v && nd < k)
                {
                    ok = 0;
                    break;
                }
                if (f1[v] == st) continue;
                if (nd < d1[v])
                {
                    d2[v] = d1[v];
                    f2[v] = f1[v];
                    d1[v] = nd;
                    f1[v] = st;
                    q.push({v, st});
                }
                else if (nd < d2[v])
                {
                    d2[v] = nd;
                    f2[v] = st;
                    q.push({v, st});
                }
            }
        }
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}