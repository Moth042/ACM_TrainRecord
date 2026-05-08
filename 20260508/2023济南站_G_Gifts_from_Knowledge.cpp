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
        fa.resize(n + 1);
        sz.resize(n + 1, 1);
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
void moth()
{
    int n, m;
    cin >> n >> m;
    dsu dsu(2 * n);
    vector<string> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] = " " + a[i];
    }
    for (int j = 1; j <= m; j++)
    {
        vector<int> cur1, cur2;
        for (int i = 1; i <= n; i++)
            if (a[i][j] == '1') cur1.push_back(i);
        for (int i = 1; i <= n; i++)
            if (a[i][m - j + 1] == '1') cur2.push_back(i);
        if (j == m - j + 1)
        {
            if (cur1.size() >= 2)
            {
                cout << 0 << '\n';
                return;
            }
        }
        else
        {
            if (cur1.size() + cur2.size() > 2)
            {
                cout << 0 << '\n';
                return;
            }
            if (cur1.size() == 2)
            {
                int x = cur1[0], y = cur1[1];
                dsu.merge(x, y + n);
                dsu.merge(y, x + n);
            }
            else if (cur2.size() == 2)
            {
                int x = cur2[0], y = cur2[1];
                dsu.merge(x, y + n);
                dsu.merge(y, x + n);
            }
            else if (cur1.size() == 1 && cur2.size() == 1)
            {
                int x = cur1[0], y = cur2[0];
                dsu.merge(x, y);
                dsu.merge(x + n, y + n);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dsu.same(i, i + n))
        {
            cout << 0 << '\n';
            return;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n * 2; i++)
    {
        if (dsu.fa[i] == i) ans++;
    }
    cout << ksm(2, ans / 2, mod) << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}