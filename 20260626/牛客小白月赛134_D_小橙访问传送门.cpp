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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ans = 0;
    ll mn1 = 1e18, mn2 = 1e18, mn3 = 1e18;
    auto it = lower_bound(a.begin(), a.end(), 0);
    if (it != a.end()) mn1 = min(mn1, abs(*it));
    if (it != a.begin()) mn1 = min(mn1, abs(*(it - 1)));
    auto it2 = lower_bound(b.begin(), b.end(), 0);
    if (it2 != b.end()) mn2 = min(mn2, abs(*it2));
    if (it2 != b.begin()) mn2 = min(mn2, abs(*(it2 - 1)));
    for (int i = 0; i < n; i++)
    {
        auto it3 = lower_bound(b.begin(), b.end(), a[i]);
        if (it3 != b.end()) mn3 = min(mn3, abs(a[i] - *it3));
        if (it3 != b.begin()) mn3 = min(mn3, abs(a[i] - *(it3 - 1)));
    }
    ll mn4 = 1e18;
    for (int i = 0; i < m; i++)
    {
        auto it4 = lower_bound(a.begin(), a.end(), b[i]);
        if (it4 != a.end()) mn4 = min(mn4, abs(b[i] - *it4));
        if (it4 != a.begin()) mn4 = min(mn4, abs(b[i] - *(it4 - 1)));
    }
    mn3 = min(mn3, mn4);

    // cout << mn1 << ' ' << mn2 << ' ' << mn3 << '\n';
    // ans += mn1 + mn2 + mn3;
    if (mn1 != 1e18) ans += mn1;
    if (mn2 != 1e18) ans += mn2;
    if (mn3 != 1e18) ans += mn3;
    ans = min(ans, (mn2 + mn3) * 2);
    ans = min(ans, (mn1 + mn3) * 2);
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