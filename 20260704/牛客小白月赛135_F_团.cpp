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
struct fenwick
{
    vector<ll> t;
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
    void add(int x, ll k)
    {
        for (int i = x; i <= n; i += lowbit(i)) t[i] += k;
    }
    ll query(int x)
    {
        ll res = 0;
        for (int i = x; i >= 1; i -= lowbit(i)) res += t[i];
        return res;
    }
    ll query(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};
void moth()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    fenwick f0, f1, f4, f7;
    f0.init(n), f1.init(n), f4.init(n), f7.init(n);
    auto upd = [&](int i, int x, int k) -> void
    {
        if (x == 0) f0.add(i, k);
        if (x == 1) f1.add(i, k);
        if (x == 4) f4.add(i, k);
        if (x == 7) f7.add(i, k);
    };
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] *= a[i];
        a[i] %= 9;
        upd(i, a[i], 1);
    }
    while (q--)
    {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1)
        {
            upd(l, a[l], -1);
            a[l] = r;
            a[l] *= a[l];
            a[l] %= 9;
            upd(l, a[l], 1);
        }
        else
        {
            if ((r - l + 1) % 3)
            {
                cout << "No\n";
                continue;
            }
            int a = f0.query(l, r), b = f1.query(l, r), c = f4.query(l, r), d = f7.query(l, r);
            auto check = [&](int x) -> bool { return x % 9 == 0 && x >= 0; };
            if (a % 3 == 0 && check(4 * b - 2 * c + d) && check(b + 4 * c - 2 * d) && check(c - 2 * b + 4 * d)) cout << "Yes\n";
            else cout << "No\n";
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