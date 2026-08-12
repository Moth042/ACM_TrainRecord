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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n * 2 + 1);
    for (int i = 1; i <= n * 2; i++) cin >> a[i];
    for (int i = 2; i <= n; i++)
    {
        if (a[2 * i - 1] > a[2 * i]) swap(a[2 * i - 1], a[2 * i]);
    }
    auto b = a, c = a;
    ll mx = 0, mn = 0;
    if (b[1] + m < b[2]) mn++;
    for (int i = 2; i <= n; i++)
    {
        if (b[2 * i] > b[1] + m && b[2 * i - 1] > b[1] + m) mn += 2;
        else if (b[2 * i] > b[1] + m) mn++;
        else
        {
            ll mm = m;
            ll df = min(m, b[1] + m - b[2 * i - 1]);
            b[2 * i - 1] += df;
            
            mm -= df;
            b[2 * i] += mm;
            if (b[2 * i] > b[1] + m) mn++;
        }
    }
    if (c[2] + m > c[1]) mx++;
    for (int i = 2; i <= n; i++)
    {
        if (c[2 * i] > c[1] && c[2 * i - 1] > c[1]) mx += 2;
        else if (c[2 * i] > c[1])
        {
            mx++;
            if (c[2 * i - 1] + m > c[1]) mx++;
        }
        else
        {
            // ll mm = m;
            // ll df = min(m, a[1] - a[2 * i]);
            c[2 * i] += m;
            if (c[2 * i] > c[1])
            {
                mx++;
                if (c[2 * i - 1] + (c[2 * i] - c[1]) > c[1]) mx++;
            }
        }
        // cout << mx << '\n';
    }
    cout << mn << ' ' << mx << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}