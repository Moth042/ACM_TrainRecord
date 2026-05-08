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
ll ksm(ll a, ll b, ll c)
{
    ll res = 1;
    while (b)
    {
        if (b & 1) res = res * a % c;
        a = a * a % c;
        b >>= 1;
    }
    return res;
}
void moth()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    vector<pair<ll, ll>> v1, v2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++) v1.push_back({a[i], a[j]});
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j) v2.push_back({b[i], b[j]});
        }
    }
    sort(v1.begin(), v1.end(),
         [&](pair<ll, ll> &x, pair<ll, ll> &y) { return x.first * y.second < x.second * y.first; });
    sort(v2.begin(), v2.end(),
         [&](pair<ll, ll> &x, pair<ll, ll> &y) { return x.first * y.second < x.second * y.first; });
    ll cur = 0, ans = 0;
    ll inv1 = ksm(1ll * n, MOD - 2, MOD), inv2 = ksm(1ll * n - 1, MOD - 2, MOD);
    for (int i = 0; i < v1.size(); i++)
    {
        ll ai = v1[i].first, aj = v1[i].second;
        while (cur < v2.size() && ai * v2[cur].second > aj * v2[cur].first) cur++;
        ans += inv1 * inv2 % MOD * cur % MOD;
        ans %= MOD;
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