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
vector<int> p, vis;
void sieve(int n)
{
    vis.assign(n + 1, 0);
    p.clear();
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i]) p.push_back(i);
        for (auto j : p)
        {
            if (i * j > n) break;
            vis[i * j] = 1; // 被标记的不是素数
            if (i % j == 0) break;
        }
    }
}
void moth()
{
    ll a, b, q;
    cin >> a >> b >> q;
    if (a == b)
    {
        for (int i = 1; i <= q; i++)
        {
            ll k;
            cin >> k;
            cout << 1 << ' ' << 1 << '\n';
        }
        return;
    }
    vector<pair<ll, ll>> ans;
    vector<ll> T;
    ans.push_back({a, b});
    T.push_back(0);
    vector<ll> fac;
    ll d = abs(a - b);
    ll curd = d;
    for (auto i : p)
    {
        if (curd % i == 0)
        {
            fac.push_back(i);
            while (curd % i == 0) curd /= i;
        }
    }
    ll now = 0;
    if (curd > 1) fac.push_back(curd);
    while (d > 1)
    {
        ll cur = 1e18;
        for (auto i : fac)
        {
            if (d % i == 0) cur = min(cur, i - a % i);
        }
        a += cur;
        b += cur;
        now += cur;
        ll g = __gcd(a, b);
        a /= g;
        b /= g;
        d /= g;
        T.push_back(now);
        ans.push_back({a, b});
    }
    while (q--)
    {
        ll k;
        cin >> k;
        int pos = upper_bound(T.begin(), T.end(), k) - T.begin() - 1;
        ll res = k - T[pos];
        cout << ans[pos].first + res << ' ' << ans[pos].second + res << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    sieve(1000000);
    cin >> _;
    while (_--) moth();
    return 0;
}