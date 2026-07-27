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
struct Node
{
    ll a, b;
    int u;
    bool operator<(const Node &v) const
    {
        return a * v.b < v.a * b;
    }
};
void moth()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1);
    vector<int> f(n + 1), p(n + 1), vis(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    priority_queue<Node> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i];
        p[i] = i;
        q.push({a[i], b[i], i});
    }
    auto find = [&](auto &&self, int x) -> int
    {
        if (x == p[x]) return x;
        return p[x] = self(self, p[x]);
    };
    ll ans = 0;
    while (q.size())
    {
        auto [A, B, u] = q.top();
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        if (f[u])
        {
            int v = find(find, f[u]);
            ans += b[v] * a[u];
            a[v] += a[u];
            b[v] += b[u];
            p[u] = v;
            q.push({a[v], b[v], v});
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