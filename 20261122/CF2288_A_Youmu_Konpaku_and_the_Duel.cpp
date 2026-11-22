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
    int x;
    cin >> x;
    int l = 1, r = x;
    int ans = 1e9;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if ((mid + 1) * mid / 2 >= x)
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    // cout << ans << '\n';
    int sum=1e9;
    for (int i = ans; i <= x; i++)
    {
        int cur = i - 1;
        // if (i == 3) cout << cur << '\n';
        int t = 0;
        int l = 0, r = i - 1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if ((i * 2 - mid) * (mid + 1) / 2 >= x)
            {
                t = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        cur += t + 1;
        // cout << i << ' ' << t << ' ' << cur << '\n';
        sum = min(sum, cur);
    }
    cout << min(x, sum) << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}