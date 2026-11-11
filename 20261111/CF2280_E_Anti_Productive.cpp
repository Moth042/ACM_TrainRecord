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
    ll L;
    cin >> n >> L;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    if (L == 1)
    {
        cout << accumulate(a.begin(), a.end(), 0ll) - a[n - 1] << '\n';
        return;
    }
    ll mx = a[n - 1];
    ll mx2 = 1;
    while ((mx2 + 1) * (mx2 + 1) < L) mx2++;
    auto cal = [&](ll x)
    {
        if (x == 0) return 0ll;
        return max(mx - (L - 1) / x, 0ll);
    };
    int st = n - 2;
    ll cur = 0;
    while (st >= 0 && a[st] >= mx2)
    {
        cur += a[st] - mx2;
        st--;
    }
    ll ans = cur + cal(mx2);
    mx2--;
    while (mx2 >= 0)
    {
        cur += n - 2 - st;
        while (st >= 0 && a[st] >= mx2) st--;
        ans = min(ans, cur + cal(mx2));
        mx2--;
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