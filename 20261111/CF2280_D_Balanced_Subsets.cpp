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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> c;
    c.push_back(1);
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1] + 1) c.push_back(1);
        else if (a[i] == a[i - 1] + 2)
        {
            c.push_back(0);
            c.push_back(1);
        }
        else
        {
            c.push_back(0);
            c.push_back(0);
            c.push_back(1);
        }
    }
    c.push_back(0);
    int m = c.size();
    ll ans = 1ll * n * (n + 1) / 2 % MOD;
    vector<ll> dp1(m + 1, 1), dp2(m + 1);
    for (int i = 1; i < m; i++)
    {
        if (c[i - 1]) dp2[i + 1] = 1;
        if (i >= 2 && c[i - 1] && c[i - 2])
        {
            dp1[i + 1] += dp1[i - 2];
            dp2[i + 1] += dp2[i - 2];
        }
        if (i >= 3 && c[i - 1] && c[i - 2] && c[i - 3])
        {
            dp1[i + 1] += dp1[i - 3];
            dp2[i + 1] += dp2[i - 3];
        }
        dp1[i + 1] %= MOD;
        dp2[i + 1] %= MOD;
        ans += dp1[i + 1] - 1 + dp2[i + 1];
        ans %= MOD;
    }
    for (int i = 1; i < m; i++)
    {
        if (c[i - 1]) ans += dp1[i - 1] + dp2[i - 1];
        ans %= MOD;
    }
    cout << ans << '\n';
    c.push_back(0);
    c.push_back(0);
    for (int i = 0; i < m; i++)
    {
        if (c[i]) ans -= 2;
        if (c[i] && c[i + 1]) ans--;
        if (c[i] && c[i + 2]) ans--;
        ans = (ans + MOD) % MOD;
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