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
ll a[N], t[N], p[N];
int n, m, k;
struct Segment_Tree
{
    int l, r;
    ll mx, add;
} s[N << 2];
void pushup(int pos)
{
    s[pos].mx = max(s[pos << 1].mx, s[pos << 1 | 1].mx);
}
void buildTree(int l, int r, int pos)
{
    s[pos].l = l;
    s[pos].r = r;
    // 如果涉及乘法运算，要使s[pos].mul=1
    //  多组测试样例时一定一定一定要记得清空！！！
    s[pos].add = 0;
    if (l == r)
    {
        s[pos].mx = a[l];
        return;
    }
    int mid = (s[pos].l + s[pos].r) >> 1;
    buildTree(l, mid, pos << 1);
    buildTree(mid + 1, r, pos << 1 | 1);
    pushup(pos);
}
void pushdown(int pos)
{
    if (s[pos].add != 0)
    {
        s[pos << 1].mx += s[pos].add;
        s[pos << 1].add += s[pos].add; // 累加到懒标记

        s[pos << 1 | 1].mx += s[pos].add;
        s[pos << 1 | 1].add += s[pos].add;

        s[pos].add = 0;
    }
}
void cgAdd(int x, int y, int pos, ll k)
{
    if (x <= s[pos].l && s[pos].r <= y)
    {
        s[pos].mx += k;
        s[pos].add += k;
        return;
    }
    pushdown(pos);
    int mid = (s[pos].l + s[pos].r) >> 1;
    if (mid >= x) cgAdd(x, y, pos << 1, k);
    if (mid + 1 <= y) cgAdd(x, y, pos << 1 | 1, k);
    pushup(pos);
}
ll query(int x, int y, int pos)
{
    if (x <= s[pos].l && y >= s[pos].r) return s[pos].mx;
    pushdown(pos);
    int mid = (s[pos].l + s[pos].r) >> 1;
    ll res = 0;
    if (mid >= x) res = max(res, query(x, y, pos << 1));
    if (mid + 1 <= y) res = max(res, query(x, y, pos << 1 | 1));
    return res;
}
void moth()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
        p[i] = p[i - 1] + t[i];
    }
    for (int i = 1; i <= n - k + 1; i++) a[i] = p[i + k - 1] - p[i - 1];
    buildTree(1, n, 1);
    ll sum = p[n];
    cout << sum - *max_element(a + 1, a + 1 + n) << '\n';
    while (m--)
    {
        ll x, y;
        cin >> x >> y;
        ll df = y - t[x];
        sum += df;
        t[x] = y;
        cgAdd(max(1ll, x - k + 1), x, 1, df);
        cout << sum - query(1, n, 1) << '\n';
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