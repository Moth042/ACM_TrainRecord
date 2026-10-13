#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int N = 5e5 + 9;
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
ll f[N], g[N];
ll ksm(ll a, ll b, ll c)
{
    ll res = 1;
    while (b)
    {
        if (b & 1) res = res * a % c;
        a = a * a % c;
        b >>= 1;
    }
    return res;
}
void init()
{
    f[0] = g[0] = 1;
    for (int i = 1; i < N; i++)
    {
        f[i] = f[i - 1] * i % mod;
        g[i] = g[i - 1] * ksm(i, mod - 2, mod) % mod;
    }
}
ll C(ll n, ll m)
{
    if (n < m) return 0;
    if (n < 0 || m < 0) return 0;
    return f[n] * g[m] % mod * g[n - m] % mod;
}
void moth()
{
    int n;
    string s;
    cin >> n >> s;
    s = " " + s;
    vector<int> num(n * 2 + 1), F(n + 1, -1);
    int idx = 1;
    vector<vector<int>> g(n + 1);
    vector<pair<char, int>> stk;
    for (int i = 1; i <= n * 2; i++)
    {
        if (s[i] == '(')
        {
            if (stk.empty())
            {
                g[0].push_back(idx);
                g[idx].push_back(0);
                F[idx] = 0;
            }
            else
            {
                int fa = stk.back().second;
                F[idx] = fa;
                g[fa].push_back(idx);
                g[idx].push_back(fa);
            }
            stk.push_back({s[i], idx});
            idx++;
        }
        else stk.pop_back();
    }
    // for (int i = 1; i <= n; i++) cout << F[i] << ' ';
    vector<int> sz(n + 1);
    auto dfs = [&](auto &&self, int u, int fa) -> void
    {
        sz[u] = 1;
        for (auto v : g[u])
        {
            if (v == fa) continue;
            self(self, v, u);
            sz[u] += sz[v];
        }
    };
    dfs(dfs, 0, -1);
    ll h = 1;
    for (int i = 1; i <= n; i++) h = h * sz[i] % mod;
    cout << f[n] * ksm(h, mod - 2, mod) % mod << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    init();
    cin >> _;
    while (_--) moth();
    return 0;
}