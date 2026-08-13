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
// ull a[N];
// int n, q;
struct Segment_Tree
{
    int l, r;
    ull sum, add, mul;
};
void pushup(int pos, vector<Segment_Tree> &s)
{
    s[pos].sum = s[pos << 1].sum + s[pos << 1 | 1].sum;
}
void buildTree(int l, int r, int pos, vector<Segment_Tree> &s)
{
    s[pos].l = l;
    s[pos].r = r;
    // s[pos].mul = 1;
    // 如果涉及乘法运算，要使s[pos].mul=1
    //  多组测试样例时一定一定一定要记得清空！！！
    s[pos].add = 0;
    if (l == r)
    {
        s[pos].sum = 0;
        return;
    }
    int mid = (s[pos].l + s[pos].r) >> 1;
    buildTree(l, mid, pos << 1, s);
    buildTree(mid + 1, r, pos << 1 | 1, s);
    pushup(pos, s);
}
void pushdown(int pos, vector<Segment_Tree> &s)
{
    // 先处理乘法标记
    // if (s[pos].mul != 1)
    // {
    //     s[pos << 1].mul *= s[pos].mul;
    //     s[pos << 1].add *= s[pos].mul; // 注意：加法标记也要乘
    //     s[pos << 1].sum *= s[pos].mul;

    //     s[pos << 1 | 1].mul *= s[pos].mul;
    //     s[pos << 1 | 1].add *= s[pos].mul;
    //     s[pos << 1 | 1].sum *= s[pos].mul;

    //     s[pos].mul = 1;
    // }
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
void cgAdd(int x, int y, int pos, ull k, vector<Segment_Tree> &s)
{
    if (x <= s[pos].l && s[pos].r <= y)
    {
        s[pos].sum += k * (s[pos].r - s[pos].l + 1);
        s[pos].add += k;
        return;
    }
    pushdown(pos, s);
    int mid = (s[pos].l + s[pos].r) >> 1;
    if (mid >= x) cgAdd(x, y, pos << 1, k, s);
    if (mid + 1 <= y) cgAdd(x, y, pos << 1 | 1, k, s);
    pushup(pos, s);
}

ull query(int x, int y, int pos, vector<Segment_Tree> &s)
{
    if (x <= s[pos].l && y >= s[pos].r) return s[pos].sum;
    pushdown(pos, s);
    int mid = (s[pos].l + s[pos].r) >> 1;
    ull res = 0;
    if (mid >= x) res += query(x, y, pos << 1, s);
    if (mid + 1 <= y) res += query(x, y, pos << 1 | 1, s);
    return res;
}
void moth()
{
    int n, m;
    cin >> n >> m;
    vector<ull> a(n + 1), b(n + 1), pa(n + 1), pb(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        pa[i] = pa[i - 1] + a[i];
        pb[i] = pb[i - 1] + b[i];
    }
    vector<Segment_Tree> s1(n * 4 + 1), s2(n * 4 + 1);
    buildTree(1, n, 1, s1);
    buildTree(1, n, 1, s2);
    for (int i = 1; i <= m; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r;
            ull x;
            cin >> l >> r >> x;
            cgAdd(l, r, 1, x, s1);
            cgAdd(l, r, 1, x * i, s2);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << (pa[r] - pa[l - 1]) + (pb[r] - pb[l - 1]) * i + query(l, r, 1, s1) * i - query(l, r, 1, s2) << '\n';
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