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
        for (int i = x; i <= n; i += lowbit(i)) t[i] = max(k, t[i]);
    }
    ll query(int x)
    {
        ll res = 0;
        for (int i = x; i >= 1; i -= lowbit(i)) res = max(t[i], res);
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
    vector<pair<ll, ll>> a(n + 1);
    vector<ll> X;
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second, X.push_back(a[i].second);
    vector<array<ll, 3>> Q(q + 1);
    for (int i = 1; i <= q; i++) cin >> Q[i][0] >> Q[i][1], Q[i][2] = i, X.push_back(Q[i][1]);
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    sort(a.begin() + 1, a.end(), greater());
    sort(Q.begin() + 1, Q.end(), greater());
    int st = 1;
    fenwick f;
    f.init(X.size());
    auto get = [&](ll r) -> ll { return lower_bound(X.begin(), X.end(), r) - X.begin() + 1; };
    vector<ll> ans(q + 1);
    for (int i = 1; i <= q; i++)
    {
        while (st <= n && a[st].first >= Q[i][0])
        {
            f.add(get(a[st].second), a[st].second - a[st].first + 1);
            st++;
        }
        ans[Q[i][2]] = f.query(get(Q[i][1]));
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << "\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}