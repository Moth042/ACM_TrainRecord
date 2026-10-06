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
void moth()
{
    ll x, y, s, m, k;
    cin >> x >> y >> s >> m >> k;
    int n;
    cin >> n;
    vector<pair<ll, int>> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i].first;
    for (int i = 1; i <= n; i++) cin >> a[i].second;
    sort(a.begin() + 1, a.end(),
         [&](pair<ll, int> &x, pair<ll, int> &y)
         {
             if (x.second == y.second) return x.first > y.first;
             return x.second < y.second;
         });
    ll ans = 0;
    int cnt0 = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].second == 0) cnt0++;
        else break;
    }
    vector<ll> p(cnt0 + 1), p2(n - cnt0 + 1);
    for (int i = 1; i <= cnt0; i++) p[i] = p[i - 1] + a[i].first;
    for (int i = cnt0 + 1; i <= n; i++) p2[i - cnt0] = p2[i - cnt0 - 1] + a[i].first;
    for (int i = 0; i <= n - cnt0; i++)
    {
        ll res = s - y * i;
        ll num = min(res / x, m);
        if (num < k * i) continue;
        // cout << p2[i] + p[min(1ll * cnt0, num - k * i)] << '\n';
        ans = max(ans, p2[i] + p[min(1ll * cnt0, (num - k * i) / k)]);
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