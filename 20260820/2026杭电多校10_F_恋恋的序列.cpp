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
struct Node
{
    int lv, rv, sum, tag;
};
void moth()
{
    int n, q;
    cin >> n >> q;
    vector<Node> s(n * 4 + 1);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    auto pushup = [&](int pos) -> void
    {
        s[pos].lv = s[pos << 1].lv;
        s[pos].rv = s[pos << 1 | 1].rv;
        s[pos].sum = s[pos << 1].sum + s[pos << 1 | 1].sum + (s[pos << 1].rv != s[pos << 1 | 1].lv);
    };
    auto buildTree = [&](auto &&self, int pos, int l, int r) -> void
    {
        s[pos].tag = -1;
        if (l == r)
        {
            s[pos].lv = s[pos].rv = a[l];
            s[pos].sum = 0;
            return;
        }
        int mid = (l + r) >> 1;
        self(self, pos << 1, l, mid);
        self(self, pos << 1 | 1, mid + 1, r);
        pushup(pos);
    };
    auto apply1 = [&](int pos, int x) -> void
    {
        s[pos].lv = s[pos].rv = x;
        s[pos].sum = 0;
        s[pos].tag = x;
    };
    auto apply2 = [&](int pos) -> void
    {
        s[pos].lv ^= 1;
        s[pos].rv ^= 1;
        if (s[pos].tag == 0) s[pos].tag = 1;
        else if (s[pos].tag == 1) s[pos].tag = 0;
        else if (s[pos].tag == 2) s[pos].tag = -1;
        else s[pos].tag = 2;
    };
    auto pushdown = [&](int pos) -> void
    {
        if (s[pos].tag == -1) return;
        int tg = s[pos].tag;
        if (tg == 0 || tg == 1)
        {
            apply1(pos << 1, s[pos].tag);
            apply1(pos << 1 | 1, s[pos].tag);
        }
        else if (tg == 2)
        {
            apply2(pos << 1);
            apply2(pos << 1 | 1);
        }
        s[pos].tag = -1;
    };
    auto upd1 = [&](auto &&self, int pos, int l, int r, int x, int y, int val) -> void
    {
        if (x <= l && r <= y)
        {
            apply1(pos, val);
            return;
        }
        pushdown(pos);
        int mid = (l + r) >> 1;
        if (mid >= x) self(self, pos << 1, l, mid, x, y, val);
        if (mid + 1 <= y) self(self, pos << 1 | 1, mid + 1, r, x, y, val);
        pushup(pos);
    };
    auto upd2 = [&](auto &&self, int pos, int l, int r, int x, int y) -> void
    {
        if (x <= l && r <= y)
        {
            apply2(pos);
            return;
        }
        pushdown(pos);
        int mid = (l + r) >> 1;
        if (mid >= x) self(self, pos << 1, l, mid, x, y);
        if (mid + 1 <= y) self(self, pos << 1 | 1, mid + 1, r, x, y);
        pushup(pos);
    };
    auto query = [&](auto &&self, int pos, int l, int r, int x, int y) -> Node
    {
        if (x <= l && r <= y) return s[pos];
        pushdown(pos);
        int mid = (l + r) >> 1;
        if (y <= mid) return self(self, pos << 1, l, mid, x, y);
        if (x > mid) return self(self, pos << 1 | 1, mid + 1, r, x, y);
        Node L = self(self, pos << 1, l, mid, x, y), R = self(self, pos << 1 | 1, mid + 1, r, x, y);
        Node res;
        res.lv = L.lv, res.rv = R.rv;
        res.sum = L.sum + R.sum + (L.rv != R.lv);
        return res;
    };
    buildTree(buildTree, 1, 1, n);
    while (q--)
    {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1)
        {
            int x;
            cin >> x;
            upd1(upd1, 1, 1, n, l, r, x);
        }
        else if (op == 2) upd2(upd2, 1, 1, n, l, r);
        else cout << query(query, 1, 1, n, l, r).sum << '\n';
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