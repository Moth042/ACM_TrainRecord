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
    vector<pair<int, int>> e;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e.push_back({u, v});
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> c, p;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'C') c.push_back(i);
        if (s[i] == 'P') p.push_back(i);
    }
    vector<ll> cp(n + 1), cs(n + 1), pc(n + 1);
    for (auto i : p)
    {
        for (auto j : g[i])
        {
            if (s[j] == 'C') pc[i]++;
        }
    }
    for (auto i : c)
    {
        for (auto j : g[i])
        {
            if (s[j] == 'P') cp[i] += 1ll * (pc[j] - 1);
            if (s[j] == 'S') cs[i]++;
        }
    }
    ll ans = 0;
    for (auto [u, v] : e)
    {
        if (s[u] == 'C' && s[v] == 'C')
        {
            // u->S
            ans += 1ll * cs[u] * cp[v];
            ans += 1ll * cs[v] * cp[u];
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}