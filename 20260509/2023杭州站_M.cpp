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
    vector<ll> a(n + 1), L(n + 1), R(n + 1), dpl(n + 1), dpr(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> idx;
    int t = -1;
    for (int i = 2; i <= n - 1; i++)
    {
        if (a[i] < a[i - 1] && a[i] < a[i + 1])
        {
            t = i;
            break;
        }
    }
    long double ans1 = 1.0 * accumulate(a.begin() + 1, a.end(), 0ll) / n;
    long double ans2 = 1.0 * accumulate(a.begin() + 1, a.begin() + t + 2, 0ll) / (t + 1);
    long double ans3 = 1.0 * accumulate(a.begin() + t - 1, a.end(), 0ll) / (n - t + 2);
    cout << max(ans1, max(ans2, ans3)) << '\n';
}
int main()
{
    // freopen("data.in", "r", stdin);
    // freopen("data1.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cout << fixed << setprecision(20);
    cin >> _;
    while (_--) moth();
    return 0;
}