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
    ll n, m, x, y;
    cin >> x >> y >> n >> m;
    ll mx = x * y;
    vector<ll> a(n + 1), b(m + 1);
    vector<ll> z, f;
    if (y >= 0) z.push_back(y);
    else f.push_back(y);
    a[0] = x;
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] += x;
    for (int i = 1; i <= m; i++)
    {
        ll t;
        cin >> t;
        b[i] = t;
        if (y + t >= 0) z.push_back(y + t);
        else f.push_back(y + t);
    }
    // sort(z.begin(), z.end());
    // sort(f.begin(), f.end());
    ll mxz, mxf, mnz, mnf;
    if (z.size()) mxz = *max_element(z.begin(), z.end()), mnz = *min_element(z.begin(), z.end());
    if (f.size()) mxf = *max_element(f.begin(), f.end()), mnf = *min_element(f.begin(), f.end());
    for (int i = 0; i <= n; i++)
    {
        if (a[i] >= 0)
        {
            if (z.size()) mx = max(mx, a[i] * mxz);
            if (f.size()) mx = max(mx, a[i] * mxf);
        }
        else
        {
            if (z.size()) mx = max(mx, a[i] * mnz);
            if (f.size()) mx = max(mx, a[i] * mnf);
        }
        if (x >= 0)
        {
            if (z.size()) mx = max(mx, x * mxz);
            if (f.size()) mx = max(mx, x * mxf);
        }
        else
        {
            if (z.size()) mx = max(mx, x * mnz);
            if (f.size()) mx = max(mx, x * mnf);
        }
    }
    // for (int i = 1; i <= m; i++)
    // {
    // }
    cout << mx << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}