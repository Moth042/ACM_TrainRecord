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
ull splitmix64(ull x)
{
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
}
struct fenwick
{
    vector<ull> t;
    int n;
    void init(int len)
    {
        n = len;
        t.assign(n + 1, 0);
    }
    int lowbit(int x)
    {
        return x & (-x);
    }
    void add(int x, ull k)
    {
        for (int i = x; i <= n; i += lowbit(i)) t[i] += k;
    }
    ull query(int x)
    {
        ull res = 0;
        for (int i = x; i >= 1; i -= lowbit(i)) res += t[i];
        return res;
    }
    ull query(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};
void moth()
{
    int n, q, k;
    cin >> n >> q >> k;
    vector<int> a(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    fenwick f;
    f.init(n);
    vector<ull> val(k);
    ull sum = 0;
    for (int i = 0; i < k - 1; i++)
    {
        val[i] = rnd();
        sum += val[i];
    }
    val[k - 1] = -sum;
    for (int i = 1; i <= n; i++) f.add(i, splitmix64(a[i]) * val[c[i]]);
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int p, x, C;
            cin >> p >> x >> C;
            f.add(p, -splitmix64(a[p]) * val[c[p]]);
            a[p] = x;
            c[p] = C;
            f.add(p, splitmix64(a[p]) * val[c[p]]);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            if (f.query(l, r) == 0) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}