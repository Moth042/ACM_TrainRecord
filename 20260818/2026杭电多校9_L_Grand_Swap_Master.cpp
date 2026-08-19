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
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n <= 2)
    {
        cout << 0 << '\n';
        return;
    }
    ll ans = 0;
    if ((a[1] + a[2] - a[3] * 2) * (a[1] - a[2]) > 0) ans++;
    if ((a[n - 2] * 2 - a[n - 1] - a[n]) * (a[n - 1] - a[n]) > 0) ans++;
    if ((a[n] - a[1]) * (a[n - 1] - a[2]) * 2 > 0) ans++;
    for (int j = 3; j <= n - 1; j++)
    {
        if ((a[1] - a[j]) * (a[2] * 2 + a[1] + a[j] - a[j - 1] * 2 - a[j + 1] * 2) > 0) ans++;
    }
    for (int i = 2; i <= n - 2; i++)
    {
        if ((a[i - 1] - a[n]) * (a[i - 1] - a[n]) - (a[i - 1] - a[i]) * (a[i - 1] - a[i]) + (a[n] - a[i + 1]) * (a[n] - a[i + 1]) - (a[i] - a[i + 1]) * (a[i] - a[i + 1]) +
                (a[n - 1] - a[i]) * (a[n - 1] - a[i]) - (a[n - 1] - a[n]) * (a[n - 1] - a[n]) >
            0)
            ans++;
    }
    for (int i = 2; i <= n - 2; i++)
    {
        if ((a[i - 1] - a[i + 1]) * (a[i - 1] - a[i + 1]) - (a[i - 1] - a[i]) * (a[i - 1] - a[i]) + (a[i] - a[i + 2]) * (a[i] - a[i + 2]) - (a[i + 1] - a[i + 2]) * (a[i + 1] - a[i + 2]) > 0) ans++;
    }
    fenwick f;
    vector<ll> Y(n + 1), v;
    vector<int> id;
    for (int i = 2; i <= n - 1; i++) id.push_back(i);
    sort(id.begin(), id.end(), [&](int x, int y) { return a[x] < a[y]; });
    for (int i = 2; i <= n - 1; i++)
    {
        Y[i] = a[i - 1] + a[i + 1];
        v.push_back(Y[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    auto get = [&](ll x) -> int { return lower_bound(v.begin(), v.end(), x) - v.begin() + 1; };
    f.init(v.size());
    for (int l = 0; l < id.size();)
    {
        int r = l;
        while (r < id.size() && a[id[l]] == a[id[r]]) ++r;
        for (int i = l; i < r; i++)
        {
            int idx = id[i];
            int pos = get(Y[idx]);
            ans += f.query(pos - 1);
        }
        for (int i = l; i < r; i++)
        {
            int idx = id[i];
            int pos = get(Y[idx]);
            f.add(pos, 1);
        }
        l = r;
    }
    for (int i = 2; i <= n - 2; i++)
    {
        if ((a[i] - a[i + 1]) * (Y[i] - Y[i + 1]) > 0) ans--;
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}