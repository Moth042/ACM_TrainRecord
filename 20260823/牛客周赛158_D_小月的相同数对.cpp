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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<ll> cnt(n + 1);
    ll sum = 0;
    int ans = 1e8;
    int r = 1;
    for (int l = 1; l <= n && r <= n;)
    {
        while (r <= n && sum < k)
        {
            sum -= cnt[a[r]] * (cnt[a[r]] - 1) / 2;
            cnt[a[r]]++;
            sum += cnt[a[r]] * (cnt[a[r]] - 1) / 2;
            r++;
        }
        // cout << l << ' ' << r << ' ' << sum << '\n';
        if (sum >= k && l <= n && r - 1 <= n) ans = min(ans, r - l);
        while (l <= r && sum >= k)
        {
            sum -= cnt[a[l]] * (cnt[a[l]] - 1) / 2;
            cnt[a[l]]--;
            sum += cnt[a[l]] * (cnt[a[l]] - 1) / 2;
            l++;
            if (sum >= k && l <= r && r - 1 <= n) ans = min(ans, r - l);
        }
    }
    cout << (ans == 1e8 ? -1 : ans) << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}