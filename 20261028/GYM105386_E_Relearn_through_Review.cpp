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
    ll sum, add, mul;
} s[N << 2];
void pushup(int pos)
{
    s[pos].sum = __gcd(s[pos << 1].sum, s[pos << 1 | 1].sum);
}
void buildTree(int l, int r, int pos)
{
    s[pos].l = l;
    s[pos].r = r;
    s[pos].mul = 1;
    // 如果涉及乘法运算，要使s[pos].mul=1
    //  多组测试样例时一定一定一定要记得清空！！！
    s[pos].add = 0;
    if (l == r)
    {
        s[pos].sum = a[l];
        return;
    }
    int mid = (s[pos].l + s[pos].r) >> 1;
    buildTree(l, mid, pos << 1);
    buildTree(mid + 1, r, pos << 1 | 1);
    pushup(pos);
}
void pushdown(int pos)
{
    // 先处理乘法标记
    if (s[pos].mul != 1)
    {
        s[pos << 1].mul *= s[pos].mul;
        s[pos << 1].add *= s[pos].mul; // 注意：加法标记也要乘
        s[pos << 1].sum *= s[pos].mul;

        s[pos << 1 | 1].mul *= s[pos].mul;
        s[pos << 1 | 1].add *= s[pos].mul;
        s[pos << 1 | 1].sum *= s[pos].mul;

        s[pos].mul = 1;
    }
    // 再处理加法标记
    if (s[pos].add != 0)
    {
        s[pos << 1].sum += s[pos].add * (s[pos << 1].r - s[pos << 1].l + 1);
        s[pos << 1].add += s[pos].add; // 累加到懒标记

        s[pos << 1 | 1].sum += s[pos].add * (s[pos << 1 | 1].r - s[pos << 1 | 1].l + 1);
        s[pos << 1 | 1].add += s[pos].add;

        s[pos].add = 0;
    }
}
void cgAdd(int x, int y, int pos, ll k)
{
    if (x <= s[pos].l && s[pos].r <= y)
    {
        s[pos].sum += k * (s[pos].r - s[pos].l + 1);
        s[pos].add += k;
        return;
    }
    pushdown(pos);
    int mid = (s[pos].l + s[pos].r) >> 1;
    if (mid >= x) cgAdd(x, y, pos << 1, k);
    if (mid + 1 <= y) cgAdd(x, y, pos << 1 | 1, k);
    pushup(pos);
}
void cgMul(int x, int y, int pos, ll k)
{
    if (x <= s[pos].l && s[pos].r <= y)
    {
        s[pos].mul = (s[pos].mul * k);
        s[pos].add = (s[pos].add * k);
        s[pos].sum = (s[pos].sum * k);
        return;
    }
    pushdown(pos);
    int mid = (s[pos].l + s[pos].r) >> 1;
    if (x <= mid) cgMul(x, y, pos << 1, k);
    if (mid + 1 <= y) cgMul(x, y, pos << 1 | 1, k);
    pushup(pos);
}
ll query(int x, int y, int pos)
{
    if (x <= s[pos].l && y >= s[pos].r) return s[pos].sum;
    pushdown(pos);
    int mid = (s[pos].l + s[pos].r) >> 1;
    ll res = 0;
    if (mid >= x) res = __gcd(res, query(x, y, pos << 1));
    if (mid + 1 <= y) res = __gcd(res, query(x, y, pos << 1 | 1));
    return res;
}
void moth()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1), p(n + 1), d(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p[i] = __gcd(p[i - 1], a[i]);
        d[i] = abs(a[i] - a[i - 1]);
    }
    ll g = p[n];
    vector<ll> s(n + 2);
    for (int i = n; i >= 1; i--) s[i] = __gcd(s[i + 1], a[i]);
    for (int i = 1; i <= n; i++)
    {
        if (p[i] != p[i - 1])
        {
            vector<ll> p2(n + 1);
            for (int j = i + 1; j <= n; j++) p2[j] = __gcd(p2[j - 1], d[j]);
            for (int j = i; j <= n; j++)
            {
                // if (i == 2 && j == 4) cout << p[i - 1] << ' ' << s[j + 1] << ' ' << a[j] + k << ' ' << p2[j] << '\n';
                ll cur = __gcd(p[i - 1], __gcd(s[j + 1], __gcd(p2[j], a[j] + k)));
                g = max(g, cur);
            }
        }
    }
    cout << g << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}