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
    vector<ll> a(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }
    vector<ll> ans(n + 1);
    for (int i = 2; i <= n - 1; i++)
    {
        int l = i + 1, r = n;
        int R = i;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (a[i - 1] + k * (mid - i) < a[mid])
            {
                R = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        ans[i] = p[R] - p[i] - a[i - 1] * (R - i) - k * (i + 1 + R) * (R - i) / 2 + k * (R - i) * i;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}