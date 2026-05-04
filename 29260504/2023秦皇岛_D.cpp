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
ll a[N];
int n, q;
struct Segment_Tree
{
    int l, r;
    ll sum, add, mnidx;
} s[N << 2];
void pushup(int pos)
{
    s[pos].sum = min(s[pos << 1].sum, s[pos << 1 | 1].sum);
    if (s[pos << 1].sum < s[pos << 1 | 1].sum) s[pos].mnidx = s[pos << 1].mnidx;
    else s[pos].mnidx = s[pos << 1 | 1].mnidx;
}
void buildTree(int l, int r, int pos)
{
    s[pos].l = l;
    s[pos].r = r;
    s[pos].mnidx = 0;
    // 如果涉及乘法运算，要使s[pos].mul=1
    //  多组测试样例时一定一定一定要记得清空！！！
    s[pos].add = 0;
    if (l == r)
    {
        s[pos].sum = a[l];
        s[pos].mnidx = l;
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
        s[pos << 1].sum += s[pos].add;
        s[pos << 1].add += s[pos].add; // 累加到懒标记

        s[pos << 1 | 1].sum += s[pos].add;
        s[pos << 1 | 1].add += s[pos].add;

        s[pos].add = 0;
    }
}
void cgAdd(int x, int y, int pos, ll k)
{
    if (x <= s[pos].l && s[pos].r <= y)
    {
        s[pos].sum += k;
        s[pos].add += k;
        return;
    }
    pushdown(pos);
    int mid = (s[pos].l + s[pos].r) >> 1;
    if (mid >= x) cgAdd(x, y, pos << 1, k);
    if (mid + 1 <= y) cgAdd(x, y, pos << 1 | 1, k);
    pushup(pos);
}
pair<ll, ll> query(int x, int y, int pos)
{
    if (x <= s[pos].l && y >= s[pos].r) return {s[pos].sum, s[pos].mnidx};
    pushdown(pos);
    int mid = (s[pos].l + s[pos].r) >> 1;
    ll res = 1e18;
    ll idx = 0;
    if (mid >= x)
    {
        auto [sum, mnidx] = query(x, y, pos << 1);
        if (res > sum)
        {
            res = sum;
            idx = mnidx;
        }
    }
    if (mid + 1 <= y)
    {
        auto [sum, mnidx] = query(x, y, pos << 1 | 1);
        if (res > sum)
        {
            res = sum;
            idx = mnidx;
        }
    }
    return {res, idx};
}
void moth()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    buildTree(1, n, 1);
    vector<pair<ll, ll>> b(m + 1);
    for (int i = 1; i <= m; i++) cin >> b[i].first >> b[i].second;
    sort(b.begin() + 1, b.end());
    for (int i = 1; i <= m; i++)
    {
        auto [x, y] = b[i];
        auto [sum, idx] = query(1, x, 1);

        idx = min(idx, 1ll * n);
        // cout << x << ' ' << y << ' ' << sum << ' ' << idx << '\n';
        cgAdd(idx, idx, 1, -y);
        // for(int j=1;j<=n;j++)cout<<query(j,j,1).first<<" \n"[j==n];
    }
    for (int i = 1; i <= n; i++) a[i] = query(i, i, 1).first;
    sort(a + 1, a + 1 + n);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += a[i];
        cout << ans << " \n"[i == n];
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