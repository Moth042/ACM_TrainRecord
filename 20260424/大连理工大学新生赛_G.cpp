#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int N = 1e6 + 9;
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
ll c, d;
struct dsu
{
    vector<int> fa, sz, belong;
    vector<ll> sum;
    vector<vector<int>> land;
    int n;
    dsu(int len, vector<ll> &a)
    {
        n = len;
        fa.resize(n + 1);
        sz.resize(n + 1, 1);
        sum.resize(n + 1, 0);
        land.resize(n + 1);
        belong.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            fa[i] = i;
            sum[i] = a[i];
            land[i].push_back(i);
            belong[i] = i;
        }
    }
    int find(int x)
    {
        if (x == fa[x]) return x;
        return fa[x] = find(fa[x]);
    }
    bool adj(int u, int v)
    {
        u = find(u), v = find(v);
        if (u == v) return false;
        if (land[u].size() < land[v].size()) swap(u, v);
        for (auto i : land[v])
        {
            if ((i > 1 && belong[i - 1] == u) || (i < n && belong[i + 1] == u)) return true;
        }
        return false;
    }
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
    bool merge(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y) return false;
        bool isadj = adj(x, y);
        if (land[x].size() < land[y].size()) swap(x, y);
        for (auto i : land[y])
        {
            belong[i] = x;
            land[x].push_back(i);
        }
        sum[x] += sum[y];
        if (isadj) sum[x] -= d;
        else sum[x] += c;
        fa[y] = x;
        return true;
    }
};
void moth()
{
    int n;
    cin >> n >> c >> d;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    dsu dsu(n, a);
    int m;
    cin >> m;
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int u, v;
            cin >> u >> v;
            if (!dsu.same(u, v)) dsu.merge(u, v);
        }
        else
        {
            int x;
            cin >> x;
            cout << dsu.sum[dsu.find(x)] << '\n';
        }
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