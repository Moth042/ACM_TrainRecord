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
    vector<int> fa(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n; i++)
    {
        cin >> fa[i];
        g[fa[i]].push_back(i);
    }
    vector<ll> dep(n + 1);
    vector<ll> h(n + 1), sz(n + 1, 1);
    ll ans = 0;
    auto dfs = [&](auto &&self, int u, int fa) -> void
    {
        for (auto v : g[u])
        {
            if (v == fa) continue;
            dep[v] = dep[u] + 1;
            ans += dep[v];
            self(self, v, u);
            sz[u] += sz[v];
        }
    };
    dfs(dfs, 1, 0);
    for (int i = n; i >= 1; i--)
    {
        priority_queue<ll, vector<ll>, greater<>> pqd, pqh;
        for (auto j : g[i]) pqd.push(sz[j]);
        while (pqd.size() > 2)
        {
            ll a = pqd.top();
            pqd.pop();
            ll b = pqd.top();
            pqd.pop();
            ans += (a + b);
            pqd.push(a + b);
        }
        for (auto j : g[i]) pqh.push(h[j]);
        // cout << i << ' ' << pqh.size() << '\n';
        if (pqh.empty()) h[i] = 0;
        else
        {
            while (pqh.size() > 2)
            {
                ll a = pqh.top();
                pqh.pop();
                ll b = pqh.top();
                pqh.pop();
                pqh.push(max(a, b) + 1);
            }
            ll mx = 0;
            while (pqh.size())
            {
                // if (i == 10) cout << pqh.top() << '\n';
                mx = max(mx, pqh.top());
                pqh.pop();
            }
            h[i] = mx + 1;
        }
        // cout << i << ' ' << h[i] << '\n';
    }
    // cout << h[2] << ' ' << h[9] << ' ' << h[13] << '\n';
    cout << h[1] << ' ' << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}