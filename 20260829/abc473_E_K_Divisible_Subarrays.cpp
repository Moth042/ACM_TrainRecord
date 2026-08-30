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
    vector<ll> a(n + 1), p(n + 1), dp(n + 1), mx(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }
    // dp[0] = 1;

    map<ll, ll> mp;
    // if (a[1] == 0)
    // {
    //     dp[1] = 1;
    //     mp[0] = 1;
    // }
    mp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = max(dp[i], dp[i - 1]);
        ll mo = p[i] % k;
        // if (mo == 0) dp[i] = max(dp[i],mx[i - 1] + 1);
        // else
        // {
        if (mp.count(mo)) dp[i] = max(dp[i], mp[mo] + 1);
        // else if (mo == 0)
        // {
        //     dp[i] = dp[i - 1] + 1;
        //     mp[mo] = dp[i];
        // }
        // }
        mx[i] = max(mx[i - 1], dp[i]);
        if (mp.count(mo)) mp[mo] = max(mp[mo], dp[i]);
        else mp[mo] = dp[i];
    }
    // for (int i = 1; i <= n; i++) cout << dp[i] << ' ';
    cout << dp[n] << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}