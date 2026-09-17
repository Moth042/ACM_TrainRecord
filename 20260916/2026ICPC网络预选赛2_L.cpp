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
    cin >> n;
    vector<ll> a(n), c1(n), c2(n), p1(n), p2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        // if (i + 1 < n) c1[i + 1] = a[i] + a[i + 1];
    }
    if (n == 1)
    {
        cout << a[0] << '\n';
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        c1[i + 1] = a[i] + a[i + 1];
        c2[i + 1] = a[(n - i) % n] + a[((n - i) % n - 1 + n) % n];
    }
    for (int i = 1; i <= n - 1; i++)
    {
        p1[i] = p1[i - 1] + c1[i];
        p2[i] = p2[i - 1] + c2[i];
    }
    ll ans = 1e18;
    for (int i = 1; i <= n - 1; i++)
    {
        ans = min(ans, a[0] + p1[i - 1] + c1[i] * (n - i));
        ans = min(ans, a[0] + p2[i - 1] + c2[i] * (n - i));
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