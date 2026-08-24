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
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    fenwick f;
    f.init(n);
    for (int i = 2; i <= n - 1; i++)
    {
        if (a[i] * 2 < a[i - 1] + a[i + 1]) f.add(i, 1);
    }
    while (q--)
    {
        ll op, l, r;
        cin >> op >> l >> r;
        if (op == 1)
        {
            if (l != 1 && l != n)
            {
                if (a[l] * 2 < a[l - 1] + a[l + 1] && r * 2 >= a[l - 1] + a[l + 1]) f.add(l, -1);
                else if (a[l] * 2 >= a[l - 1] + a[l + 1] && r * 2 < a[l - 1] + a[l + 1]) f.add(l, 1);

                if (l - 1 != 1)
                {
                    if (a[l - 1] * 2 < a[l - 2] + a[l] && a[l - 1] * 2 >= a[l - 2] + r) f.add(l - 1, -1);
                    else if (a[l - 1] * 2 >= a[l - 2] + a[l] && a[l - 1] * 2 < a[l - 2] + r) f.add(l - 1, 1);
                }
                if (l + 1 != n)
                {
                    if (a[l + 1] * 2 < a[l + 2] + a[l] && a[l + 1] * 2 >= a[l + 2] + r) f.add(l + 1, -1);
                    else if (a[l + 1] * 2 >= a[l + 2] + a[l] && a[l + 1] * 2 < a[l + 2] + r) f.add(l + 1, 1);
                }
            }
            else if (l == 1)
            {
                if (l + 1 != n)
                {
                    if (a[l + 1] * 2 < a[l + 2] + a[l] && a[l + 1] * 2 >= a[l + 2] + r) f.add(l + 1, -1);
                    else if (a[l + 1] * 2 >= a[l + 2] + a[l] && a[l + 1] * 2 < a[l + 2] + r) f.add(l + 1, 1);
                }
            }
            else
            {
                if (l - 1 != 1)
                {
                    if (a[l - 1] * 2 < a[l - 2] + a[l] && a[l - 1] * 2 >= a[l - 2] + r) f.add(l - 1, -1);
                    else if (a[l - 1] * 2 >= a[l - 2] + a[l] && a[l - 1] * 2 < a[l - 2] + r) f.add(l - 1, 1);
                }
            }
            a[l] = r;
        }
        else cout << f.query(l, r) - f.query(l, l) - f.query(r, r) << '\n';
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