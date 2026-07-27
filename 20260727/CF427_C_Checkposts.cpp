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
struct SCC
{
    int n;
    vector<std::vector<int>> adj;
    vector<int> stk;
    vector<int> dfn, low, bel;
    int cur, cnt;

    SCC()
    {
    }
    SCC(int n)
    {
        init(n);
    }

    void init(int n)
    {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.resize(n);
        bel.assign(n, -1);
        stk.clear();
        cur = cnt = 0;
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    void dfs(int x)
    {
        dfn[x] = low[x] = cur++;
        stk.push_back(x);

        for (auto y : adj[x])
        {
            if (dfn[y] == -1)
            {
                dfs(y);
                low[x] = min(low[x], low[y]);
            }
            else if (bel[y] == -1)
            {
                low[x] = min(low[x], dfn[y]);
            }
        }

        if (dfn[x] == low[x])
        {
            int y;
            do
            {
                y = stk.back();
                bel[y] = cnt;
                stk.pop_back();
            } while (y != x);
            cnt++;
        }
    }

    vector<int> work()
    {
        for (int i = 0; i < n; i++)
        {
            if (dfn[i] == -1)
            {
                dfs(i);
            }
        }
        return bel;
    }
};
void moth()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    SCC scc(n);
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        scc.addEdge(u, v);
    }
    auto bel = scc.work();
    vector<vector<int>> cnt(scc.cnt);
    vector<int> mn(scc.cnt);
    for (int i = 0; i < n; i++) cnt[bel[i]].push_back(i);
    ll ans1 = 0, ans2 = 1;
    // cout << scc.cnt << '\n';
    for (int i = 0; i < scc.cnt; i++)
    {
        ll mnn = 1e18;
        for (auto j : cnt[i]) mnn = min(mnn, a[j]);
        for (auto j : cnt[i])
        {
            if (a[j] == mnn) mn[i]++;
        }
        ans1 += mnn;
        ans2 = (ans2 * mn[i]) % mod;
    }
    cout << ans1 << ' ' << ans2 << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}