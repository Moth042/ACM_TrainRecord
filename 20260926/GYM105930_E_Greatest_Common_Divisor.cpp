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
    ll k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    ll s = 0;
    ll M = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s += a[i];
        M = max(M, a[i]);
        // cnt[a[i]]++;
    }
    vector<ll> cnt(M + 1), psum(M + 1), pcnt(M + 1);
    for (int i = 1; i <= n; i++) cnt[a[i]]++;
    for (int i = 1; i <= M; i++)
    {
        psum[i] = psum[i - 1] + 1ll * cnt[i] * i;
        pcnt[i] = pcnt[i - 1] + cnt[i];
    }
    auto check = [&](ll i) -> bool
    {
        ll d = 0;
        if (i >= M) d = i * n - s;
        else
        {
            for (ll j = 1; j * i <= M; j++)
            {
                ll sum = psum[i * j] - psum[i * (j - 1)], num = pcnt[i * j] - pcnt[i * (j - 1)];
                d += j * i * num - sum;
            }
            ll sum = psum[M] - psum[M / i * i], num = pcnt[M] - pcnt[M / i * i];
            d += (M / i + 1) * i * num - sum;
        }
        // cout << i << ' ' << d << '\n';
        if (d <= k && (k - d) % i == 0) return 1;
        return 0;
    };
    vector<ll> v;
    for (ll i = 1; i * i <= s + k; i++)
    {
        if ((s + k) % i == 0)
        {
            v.push_back(i);
            if (i != (s + k) / i) v.push_back((s + k) / i);
        }
    }
    sort(v.rbegin(), v.rend());
    for (auto i : v)
    {
        if (check(i))
        {
            cout << i << '\n';
            return;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}