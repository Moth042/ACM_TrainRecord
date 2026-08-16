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
int n, q;
string ss;
struct Segment_Tree
{
    int l, r;
    int col[3];
    int lc, rc;
    int add;
} s[N << 2];
void pushup(int pos)
{
    for (int i = 0; i < 3; i++)
    {
        s[pos].col[i] = s[pos << 1].col[i] + s[pos << 1 | 1].col[i];
        if (s[pos << 1].rc == i && s[pos << 1 | 1].lc == i) s[pos].col[i]--;
    }
    s[pos].lc = s[pos << 1].lc;
    s[pos].rc = s[pos << 1 | 1].rc;
}
void apply(int pos, int k)
{
    k %= 3;
    if (k == 0) return;
    int tmp[] = {0, 0, 0};
    for (int i = 0; i < 3; i++) tmp[(i + k) % 3] = s[pos].col[i];
    for (int i = 0; i < 3; i++) s[pos].col[i] = tmp[i];
    s[pos].lc = (s[pos].lc + k) % 3;
    s[pos].rc = (s[pos].rc + k) % 3;
    s[pos].add = (s[pos].add + k) % 3;
}
void pushdown(int pos)
{
    if (s[pos].add)
    {
        apply(pos << 1, s[pos].add);
        apply(pos << 1 | 1, s[pos].add);
        s[pos].add = 0;
    }
}
void buildTree(int pos, int l, int r)
{
    s[pos].l = l;
    s[pos].r = r;
    s[pos].add = 0;
    for (int i = 0; i < 3; i++) s[pos].col[i] = 0;
    if (l == r)
    {
        int c;
        if (ss[l] == 'A') c = 0;
        else if (ss[l] == 'B') c = 1;
        else c = 2;
        s[pos].col[c] = 1;
        s[pos].lc = s[pos].rc = c;
        return;
    }
    int mid = (l + r) >> 1;
    buildTree(pos << 1, l, mid);
    buildTree(pos << 1 | 1, mid + 1, r);
    pushup(pos);
}
void update(int x, int y, int pos)
{
    if (x <= s[pos].l && s[pos].r <= y)
    {
        apply(pos, 1);
        return;
    }
    int mid = (s[pos].l + s[pos].r) >> 1;
    pushdown(pos);
    if (mid >= x) update(x, y, pos << 1);
    if (mid + 1 <= y) update(x, y, pos << 1 | 1);
    pushup(pos);
}
void moth()
{
    cin >> n >> q >> ss;
    ss = " " + ss;
    buildTree(1, 1, n);
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r;
            cin >> l >> r;
            update(l, r, 1);
        }
        else cout << s[1].col[0] << '\n';
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