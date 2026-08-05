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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<ll>> d(n + 1, vector<ll>(2, 1e18));
    vector<vector<int>> vis(n + 1, vector<int>(2));
    d[1][0] = 0;
    vis[1][0] = 1;
    queue<array<ll, 3>> q;
    q.push({1, 0, 0});
    while (q.size())
    {
        auto [x, y, z] = q.front();
        q.pop();
        for (auto s : g[x])
        {
            if (!vis[s][y ^ 1] && d[s][y ^ 1] > d[x][y] + 1)
            {
                d[s][y ^ 1] = d[x][y] + 1;
                q.push({s, y ^ 1, d[s][y ^ 1]});
                vis[s][y ^ 1] = 1;
            }
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     if (d[i][0] != 1e18) cout << d[i][0] << " ";
    //     else cout << -1 << " ";
    //     if (d[i][1] != 1e18) cout << d[i][1] << '\n';
    //     else cout << -1 << '\n';
    // }
    vector<ll> ans(n + 1);
    for (int i = 2; i <= n; i++)
    {
        ll ji = 1e18, ou = 1e18;
        if (d[i][0] != 1e18)
        {
            if (d[i][0] % k == 0)
            {
                ou = d[i][0];
            }
            else
            {
                ll s = (d[i][0] / k + 1) * k;
                if (s % 2) s += k;
                ou = s;
            }
        }
        if (d[i][1] != 1e18)
        {
            if (d[i][1] % k == 0) ji = d[i][1];
            else
            {
                ll s = (d[i][1] / k + 1) * k;
                if (s % 2 == 0)
                {
                    if ((s + k) % 2)
                    {
                        s += k;
                        ji = s;
                    }
                    else ji = 1e18;
                }
                else ji = s;
            }
        }
        ll mn = min(ou, ji);
        if (mn == 1e18) ans[i] = -1;
        else ans[i] = mn;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}