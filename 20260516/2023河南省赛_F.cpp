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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n + 1), d(n);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    for (int i = 1; i < n; i++) d[i] = a[i + 1] - a[i];
    int LOG = __lg(n) + 1;
    vector<vector<ll>> st(n, vector<ll>(LOG + 1));
    for (int i = 1; i < n; i++) st[i][0] = d[i];
    vector<ll> lg2(n, 0);
    for (int i = 2; i < n; i++) lg2[i] = lg2[i >> 1] + 1;
    for (int j = 1; j <= LOG; j++)
    {
        for (int i = 1; i + (1 << j) - 1 < n; i++) st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
    auto getMin = [&](int l, int r) -> ll
    {
        ll k = lg2[r - l + 1];
        return min(st[l][k], st[r - (1 << k) + 1][k]);
    };
    ll ans = 1e18;
    for (int i = 1; i <= n - k + 1; i++)
    {
        ll mx = a[i + k - 1] - a[i];
        ll mn = getMin(i, i + k - 2);
        ans = min(ans, mx * mn);
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