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
struct Edge
{
    ll u, v, w;
};
bool cmp1(const Edge &a, const Edge &b)
{
    return a.w < b.w;
}
bool cmp2(const Edge &a, const Edge &b)
{
    return a.w > b.w;
}
int pre[N];
int root(int x)
{
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}
void moth()
{
    int n, m;
    cin >> n >> m;
    vector<Edge> es;
    for (int i = 1; i <= m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        es.push_back({u, v, w});
    }
    sort(es.begin(), es.end(), cmp1);
    ll ans = 0;
    ll L = 0, R = 0;
    for (int i = 1; i <= n; i++) pre[i] = i;
    for (auto &[u, v, w] : es)
    {
        if (root(u) == root(v)) continue;
        L += w;
        pre[root(u)] = root(v);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (root(i) == i) cnt++;
    if (cnt > 1) ans = -1;
    for (int i = 1; i <= n; i++) pre[i] = i;
    sort(es.begin(), es.end(), cmp2);
    for (auto &[u, v, w] : es)
    {
        if (root(u) == root(v)) continue;
        R += w;
        pre[root(u)] = root(v);
    }
    cnt = 0;
    for (int i = 1; i <= n; i++)
        if (root(i) == i) cnt++;
    if (cnt > 1) ans = -1;
    if (ans != -1) ans = R - L + 1;
    cout << (ans == -1 ? 0 : ans) << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}