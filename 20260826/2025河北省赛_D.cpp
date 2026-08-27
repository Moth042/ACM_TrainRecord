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
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    // a.erase(unique(a.begin(), a.end()), a.end());
    ll l = 0, r = 1e8;
    ll ans = -1;
    // n = a.size();
    auto check = [&](ll x) -> bool
    {
        ll cnt = 0;
        ll l = 0, r = 0;
        while (l < n && r < n)
        {
            while (r < n && a[r] - a[l] <= x) r++;
            cnt += r - l - 1;
            // cout << l << ' ' << r << '\n';
            // else cnt += r - l;
            l++;
        }
        while (l < n) cnt += r - l - 1, l++;
        return cnt >= k;
    };
    // cout << check(10);
    while (l <= r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid))
        {
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    }
    // cout << ans << '\n';
    l = 0, r = 0;
    ull sum = 0;
    vector<ull> p(n + 1);
    for (int i = 0; i < n; i++) p[i + 1] = p[i] + a[i];
    ll cnt = 0;
    while (l < n && r < n)
    {
        while (r < n && a[r] - a[l] <= ans) r++;
        sum += p[r] - p[l + 1] - 1ull * a[l] * (r - l - 1);
        cnt += (r - l - 1);
        // else sum += p[r + 1] - p[l + 1] - a[l] * (r - l + 1);
        // cout << l << ' ' << r << '\n';
        l++;
    }
    cout << sum << '\n';
    while (l < n)
    {
        sum += p[r] - p[l + 1] - 1ull * a[l] * (r - l - 1);
        cnt += r - l - 1;
        l++;
    }
    sum -= (cnt - k) * ans;
    cout << sum << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}