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
    string s;
    cin >> s;
    s = " " + s;
    // vector<int> p1(n + 2), s0(n + 2);
    // for (int i = 1; i <= n; i++) p1[i] = p1[i - 1] + (s[i] == '1' || s[i] == '?');
    // for (int i = n; i >= 1; i--) s0[i] = s0[i + 1] + (s[i] == '0' || s[i] == '?');
    // ll ans = 0;
    // for (int i = 0; i <= n; i++) ans = max(ans, 1ll * p1[i] * s0[i + 1]);
    // cout << ans << '\n';
    vector<ll> p1(n + 1);    // 前缀中1的个数
    vector<ll> cnt01(n + 1); // 每个0前面1的个数
    vector<ll> cnt02(n + 1); // 每个0前面？的个数
    vector<ll> p0(n + 1);    // 前缀0个数
    vector<ll> p2(n + 1);    // 前缀？个数
    vector<ll> cnt21(n + 1); // 每个？前面1的个数
    vector<ll> p01(n + 1), p02(n + 1), p21(n + 1);
    for (int i = 1; i <= n; i++)
    {
        p1[i] = p1[i - 1] + (s[i] == '1');
        p0[i] = p0[i - 1] + (s[i] == '0');
        p2[i] = p2[i - 1] + (s[i] == '?');
    }
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '0')
        {
            cnt01[i] = p1[i];
            cnt02[i] = p2[i];
        }
        if (s[i] == '?') cnt21[i] = p1[i];
        p01[i] = p01[i - 1] + cnt01[i];
        p02[i] = p02[i - 1] + cnt02[i];
        p21[i] = p21[i - 1] + cnt21[i];
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ll x1 = p02[i] + p01[i];
        ll x2 = (p0[n] - p0[i] + p2[n] - p2[i]) * p2[i];
        ll x3 = p01[n] - p01[i] + p21[n] - p21[i];
        ans = max(ans, x1 + x2 + x3);
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