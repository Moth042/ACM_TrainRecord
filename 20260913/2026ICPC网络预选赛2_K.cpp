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
    vector<ll> a(n + 1);
    vector<int> cnt1(n + 1), cnt2(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] <= n) cnt1[a[i]]++;
    }
    int mex = 0;
    while (mex <= n && cnt1[mex]) mex++;
    vector<ll> can;
    for (int i = 1; i <= n; i++)
    {
        ll k = mex + a[i];
        if (k <= 1e9) can.push_back(k);
    }
    sort(can.begin(), can.end());
    can.erase(unique(can.begin(), can.end()), can.end());
    int m = can.size();
    vector<ll> sum(m);
    for (int i = 0; i < m; i++)
    {
        ll k = can[i];
        for (int j = 1; j <= n; j++) cnt2[j] = 0;
        for (int j = 1; j <= n; j++)
        {
            ll x = k - a[j];
            if (x >= 0 && x <= n) cnt2[x]++;
        }
        ll cur = n;
        for (int y = mex; y <= n; y++)
        {
            ll z = k - y;
            int now = cnt1[y];
            if (z >= 0 && z != y) now += cnt2[y];
            int need = 1 + (z >= 0 && z < y);
            if (now < need)
            {
                cur = y;
                break;
            }
        }
        sum[i] = cur;
    }
    int q;
    cin >> q;
    ll ans = 0;
    while (q--)
    {
        ll k;
        cin >> k;
        auto it = lower_bound(can.begin(), can.end(), k);
        if (it == can.end() || *it != k) ans ^= mex;
        else ans ^= sum[it - can.begin()];
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