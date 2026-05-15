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
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<ll, ll>> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    sort(a.begin() + 1, a.end());
    vector<ll> dp(m + 1);

    ll ans = 0;
    priority_queue<ll, vector<ll>, greater<>> q;
    ll num = 0;
    vector<ll> suf(n + 2);
    for (int i = n; i >= 1; i--)
    {
        if (q.size() < k)
        {
            num += a[i].second;
            q.push(a[i].second);
        }
        else if (k > 0 && a[i].second > q.top())
        {
            num -= q.top();
            q.pop();
            num += a[i].second;
            q.push(a[i].second);
        }
        suf[i] = num;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= a[i].first; j--) dp[j] = max(dp[j], dp[j - a[i].first] + a[i].second);
        ans = max(ans, dp[m] + suf[i + 1]);
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