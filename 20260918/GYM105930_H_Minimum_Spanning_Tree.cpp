#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int N = 2e5 + 9;
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
    int idx;
    bool operator<(const Edge &m) const
    {
        if (w != m.w) return w < m.w;
        if (u != m.u) return u < m.u;
        return v < m.v;
        // 等价于return w==m.w?(u==m.u?v<m.v:u<m.u):w<m.w;
    }
};
int pre[N];
int root(int x)
{
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}
void moth()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<Edge> es;
    for (int i = 1; i <= m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        es.push_back({u, v, w, i});
    }
    sort(es.begin(), es.end());
    ll ans = 0;
    vector<Edge> can;
    for (int i = 1; i <= n; i++) pre[i] = i;
    for (auto &[u, v, w, idx] : es)
    {
        if (root(u) == root(v)) continue;
        // ans += w;
        can.push_back({u, v, w, idx});
        pre[root(u)] = root(v);
    }
    // cout << ans << '\n';
    sort(can.begin(), can.end());
    int st = can.size() - 1, cnt = 0;
    while (st >= 0 && cnt < k && can[st].w > 1)
    {
        st--;
        cnt++;
    }
    // cout << st << '\n';
    for (int i = 1; i <= n; i++) pre[i] = i;
    vector<pair<int, int>> add;
    int cur = m;
    vector<int> num;
    for (int i = 0; i <= st; i++)
    {
        auto [u, v, w, idx] = can[i];
        if (root(u) == root(v)) continue;
        ans += w;
        pre[root(u)] = root(v);
        num.push_back(idx);
    }
    for (int i = 1; i < n; i++)
    {
        if (root(i) == root(i + 1)) continue;
        add.push_back({i, i + 1});
        pre[root(i)] = root(i + 1);
        num.push_back(++cur);
        ans++;
    }
    cout << add.size() << '\n';
    for (auto [x, y] : add) cout << x << ' ' << y << '\n';
    cout << ans << '\n';
    for (auto i : num) cout << i << ' ';
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