#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int N = 1e6 + 9;
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
ll f[N];
void init()
{
    f[0] = f[1] = 1;
    for (int i = 2; i < N; i++) f[i] = f[i - 1] * i % MOD;
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
    int n;
    cin >> n;
    vector<int> a(n * 2 + 1);
    vector<int> vis(n * 2 + 1);
    for (int i = 1; i <= n * 2; i++)
    {
        cin >> a[i];
        if (a[i]) vis[a[i]] = 1;
    }
    vector<int> apr, dpr;
    int d = 0;
    for (int i = 1; i <= n * 2; i += 2)
    {
        if (a[i] && a[i + 1]) continue;
        else if (a[i] || a[i + 1]) apr.push_back(a[i] ? a[i] : a[i + 1]);
        else d++;
    }
    for (int i = 1; i <= n * 2; i++)
    {
        if (!vis[i]) dpr.push_back(i);
    }
    sort(apr.begin(), apr.end());
    sort(dpr.rbegin(), dpr.rend());
    int p = 0;
    int s = apr.size();
    while (p < s && dpr[d + p] > apr[p]) ++p;
    cout << f[d + p] * f[d + s - p] % MOD * ksm(2ll, d, MOD) % MOD << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    init();
    cin >> _;
    while (_--) moth();
    return 0;
}