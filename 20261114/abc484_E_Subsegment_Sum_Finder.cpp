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
    int n;
    ll L, R;
    cin >> n >> L >> R;
    vector<ll> a(n + 1), p(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }
    fenwick f;
    f.init(n + 1);
    vector<ll> v;
    for (int i = 0; i <= n; i++) v.push_back(p[i]);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    auto get = [&](ll x) { return lower_bound(v.begin(), v.end(), x) - v.begin() + 1; };
    f.add(get(p[0]), 1);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = get(p[i] - R);
        int r = upper_bound(v.begin(), v.end(), p[i] - L) - v.begin();
        ans += f.query(l, r);
        f.add(get(p[i]), 1);
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}