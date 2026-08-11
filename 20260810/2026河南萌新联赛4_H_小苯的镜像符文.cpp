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
const int B = 13331;
void moth()
{
    ll n, k;
    string s;
    cin >> n >> k >> s;
    vector<ll> a(26);
    for (int i = 0; i < 26; i++) cin >> a[i];
    auto isPrime = [&](int x) -> bool
    {
        if (x <= 1) return false;
        for (int i = 2; i * i <= x; i++)
        {
            if (x % i == 0) return false;
        }
        return true;
    };
    auto findPrime = [&](int n) -> int
    {
        while (!isPrime(n)) n++;
        return n;
    };
    const int P = findPrime(rnd() % 900000000 + 100000000);
    vector<int> h(n + 1), p(n + 1), hr(n + 1);
    for (int i = 0; i < n; i++) h[i + 1] = (1LL * h[i] * B + s[i]) % P;
    for (int i = n - 1; i > 0; i--) hr[i - 1] = (1LL * hr[i] * B + s[i]) % P;
    p[0] = 1;
    for (int i = 0; i < n; i++) p[i + 1] = 1LL * p[i] * B % P;
    auto get = [&](int l, int r) { return (h[r] + 1LL * (P - h[l]) * p[r - l]) % P; };
    auto get2 = [&](int l, int r) { return (hr[l] + 1LL * (P - hr[r]) * p[r - l]) % P; };
    vector<ll> dp(n + 1, 1e18);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i + 1] = dp[i] + a[s[i] - 'a'];
        for (int j = 0; j < i; j++)
        {
            if ((i - j) % 2 && get(j, i) == get2(j, i)) dp[i + 1] = min(dp[i + 1], dp[i + 1 - (i - j + 1) / 2] + k);
        }
        // cout << dp[i + 1] << " ";
    }
    cout << dp[n] << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}