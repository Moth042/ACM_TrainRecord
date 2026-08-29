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
ll ksm(ll a, ll b, ll c)
{
    ll res = 1;
    while (b)
    {
        if (b & 1) res = res * a % c;
        a = a * a % c;
        b >>= 1;
    }
    return res;
}
void moth()
{
    ll n, m;
    cin >> n >> m;
    map<ll, ll> mp;
    for (int i = 1; i <= n; i++)
    {
        ll a, b;
        cin >> a >> b;
        mp[b] += a;
    }
    vector<ll> w;
    for (auto [k, v] : mp) w.push_back(k);
    sort(w.begin(), w.end(), greater());
    ll ans = 0, sum = 0, lst = w[0];
    for (auto x : w)
    {
        if (sum)
        {
            ll cnt = 0, st = sum;
            while (st)
            {
                st >>= 1;
                cnt++;
            }
            if (cnt + lst - x >= 50) break;
            sum *= (1ll << (lst - x));
        }
        lst = x;
        if (sum >= mp[x])
        {
            sum -= mp[x];
            continue;
        }
        mp[x] -= sum;
        ll need = (mp[x] + m - 1) / m;
        ans = (ans + (need % MOD * ksm(2, x, MOD) % MOD)) % MOD;
        sum = need * m - mp[x];
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