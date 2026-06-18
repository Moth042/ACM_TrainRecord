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
ll a[N];
int n, q;
struct Segment_Tree
{
    int l, r;
    ll sum, add, mul;
} s[N << 2];
void pushup(int pos)
{
    s[pos].sum = (s[pos << 1].sum + s[pos << 1 | 1].sum) % MOD;
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
        ll val = ksm(mod, a[l], MOD);
        if (l % 2 == 0) s[pos].sum = val;
        else s[pos].sum = (MOD - val) % MOD;
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
        s[pos << 1].mul %= MOD;
        s[pos << 1].add %= MOD;
        s[pos << 1].sum %= MOD;

        s[pos << 1 | 1].mul *= s[pos].mul;
        s[pos << 1 | 1].add *= s[pos].mul;
        s[pos << 1 | 1].sum *= s[pos].mul;
        s[pos << 1 | 1].mul %= MOD;
        s[pos << 1 | 1].add %= MOD;
        s[pos << 1 | 1].sum %= MOD;

        s[pos].mul = 1;
    }
    // 再处理加法标记
    if (s[pos].add != 0)
    {
        s[pos << 1].sum += s[pos].add * (s[pos << 1].r - s[pos << 1].l + 1) % MOD;
        s[pos << 1].add += s[pos].add; // 累加到懒标记
        s[pos << 1].sum %= MOD;
        s[pos << 1].add %= MOD;

        s[pos << 1 | 1].sum += s[pos].add * (s[pos << 1 | 1].r - s[pos << 1 | 1].l + 1) % MOD;
        s[pos << 1 | 1].add += s[pos].add;
        s[pos << 1 | 1].sum %= MOD;
        s[pos << 1 | 1].add %= MOD;

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
        s[pos].mul = (s[pos].mul * k) % MOD;
        s[pos].add = (s[pos].add * k) % MOD;
        s[pos].sum = (s[pos].sum * k) % MOD;
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
    if (x <= s[pos].l && y >= s[pos].r) return s[pos].sum % MOD;
    pushdown(pos);
    int mid = (s[pos].l + s[pos].r) >> 1;
    ll res = 0;
    if (mid >= x) res += query(x, y, pos << 1), res %= MOD;
    if (mid + 1 <= y) res += query(x, y, pos << 1 | 1), res %= MOD;
    return res;
}
void moth()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    buildTree(1, n, 1);
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 0)
        {
            ll l, r, v;
            cin >> l >> r >> v;
            ll val = ksm(mod, v, MOD);
            cgMul(l, r, 1, val);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            ll t = query(l, r, 1);
            if (t == 0) cout << "YES\n";
            else cout << "NO\n";
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