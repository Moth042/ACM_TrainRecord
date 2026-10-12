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
struct dsu
{
    vector<int> fa, sz;
    int n;
    dsu(int len)
    {
        n = len;
        fa.assign(n + 1, 0);
        sz.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) fa[i] = i;
    }
    int find(int x)
    {
        if (x == fa[x]) return x;
        return fa[x] = find(fa[x]);
    }
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
    bool merge(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        fa[y] = x;
        return true;
    }
};
void moth()
{
    int n, m, q;
    ll v;
    cin >> n >> m >> q >> v;
    vector<array<ll, 3>> e(m + 1);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < 3; j++) cin >> e[i][j];
    }
    vector<pair<int, int>> Q(q + 1);
    for (int i = 1; i <= q; i++) cin >> Q[i].first >> Q[i].second;
    vector<int> ans(q + 1);
    bool ok = 0;
    ll s = 0;
    for (int bit = 59; bit >= 0; bit--)
    {
        // cout << s << '\n';
        if (ok) s -= (1ll << (bit + 1));
        s += (1ll << bit);
        if ((v >> bit) & 1)
        {
            ok = 0;
            continue;
        }
        else ok = 1;
        dsu dsu(n + 1);
        for (int i = 1; i <= m; i++)
        {
            if ((e[i][2] & s) == s) dsu.merge(e[i][0], e[i][1]);
        }
        for (int i = 1; i <= q; i++) ans[i] |= (dsu.same(Q[i].first, Q[i].second));
    }
    dsu dsu(n + 1);
    for (int i = 1; i <= m; i++)
    {
        if ((e[i][2] & v) == v) dsu.merge(e[i][0], e[i][1]);
    }
    for (int i = 1; i <= q; i++) ans[i] |= (dsu.same(Q[i].first, Q[i].second));
    for (int i = 1; i <= q; i++)
    {
        if (ans[i]) cout << "Yes\n";
        else cout << "No\n";
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}