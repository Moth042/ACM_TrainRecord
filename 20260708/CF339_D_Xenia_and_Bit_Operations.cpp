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
struct Segment_Tree
{
    int l, r;
    ll val;
};
void moth()
{
    int n, q;
    cin >> n >> q;
    int sz = 1 << n;
    int cc = log2(sz);
    vector<ll> a(sz + 1);
    vector<Segment_Tree> s(sz * 2 + 10);
    auto pushup = [&](int pos, int ceil) -> void
    {
        if ((cc - ceil) % 2) s[pos].val = s[pos << 1].val | s[pos << 1 | 1].val;
        else s[pos].val = s[pos << 1].val ^ s[pos << 1 | 1].val;
    };
    auto getc = [&](int x) -> int { return log2(x); };
    auto build = [&](auto &&self, int l, int r, int pos) -> void
    {
        s[pos].l = l, s[pos].r = r;
        if (l == r)
        {
            s[pos].val = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        self(self, l, mid, pos << 1);
        self(self, mid + 1, r, pos << 1 | 1);
        pushup(pos, getc(pos));
    };
    auto upd = [&](auto &&self, int x, int pos, ll k) -> void
    {
        if (s[pos].l == x && s[pos].r == x)
        {
            s[pos].val += k;
            return;
        }
        int mid = (s[pos].l + s[pos].r) >> 1;
        if (x <= mid) self(self, x, pos << 1, k);
        if (mid + 1 <= x) self(self, x, pos << 1 | 1, k);
        pushup(pos, getc(pos));
    };
    auto query = [&](auto &&self, int x, int y, int pos) -> ll
    {
        if (x <= s[pos].l && s[pos].r <= y) return s[pos].val;
        ll res = 0;
        int mid = (s[pos].l + s[pos].r) >> 1;
        if (x <= mid)
        {
            if ((cc - getc(pos)) % 2) res |= self(self, x, y, pos << 1);
            else res ^= self(self, x, y, pos << 1);
        }
        if (mid + 1 <= y)
        {
            if ((cc - getc(pos)) % 2) res |= self(self, x, y, pos << 1 | 1);
            else res ^= self(self, x, y, pos << 1 | 1);
        }
        return res;
    };
    for (int i = 1; i <= sz; i++) cin >> a[i];
    build(build, 1, sz, 1);
    while (q--)
    {
        // for (int i = 1; i <= sz * 2 - 1; i++) cout << s[i].val << ' ';
        // cout << '\n';
        int x;
        ll k;
        cin >> x >> k;
        ll t = query(query, x, x, 1);
        upd(upd, x, 1, k - t);
        cout << s[1].val << '\n';
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