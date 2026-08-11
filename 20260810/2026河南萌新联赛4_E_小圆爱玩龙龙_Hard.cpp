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
    ll n, W, k;
    cin >> n >> W >> k;
    vector<pair<ll, ll>> a(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second, sum += a[i].second;
    sort(a.begin() + 1, a.end(), greater());
    priority_queue<ll, vector<ll>, greater<>> pq;
    vector<ll> free(n + 1), buy(n + 1);
    ll cur = 0;
    for (int i = 1; i <= n; i++)
    {
        cur += a[i].second;
        pq.push(a[i].second);
        if (pq.size() > k)
        {
            cur -= pq.top();
            pq.pop();
        }
        free[i] = cur;
    }
    vector<ll> dp(sum + 1, 1e18);
    dp[0] = 0;
    ll curr = 0, best = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        ll w = a[i + 1].first, v = a[i + 1].second;
        for (int j = curr; j >= 0; j--)
        {
            if (dp[j] == 1e18) continue;
            ll nv = v + j, nw = dp[j] + w;
            if (dp[nv] > nw)
            {
                dp[nv] = nw;
                if (nw <= W) best = max(best, nv);
            }
        }
        buy[i] = best;
        curr += v;
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) ans = max(ans, free[i] + buy[i]);
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