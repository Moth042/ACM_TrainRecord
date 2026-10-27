#include <bits/stdc++.h>
using namespace std;
#define int long long
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
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    auto check = [&](int mid) -> bool
    {
        int cnt = 0;
        vector<int> vis(n + 1);
        // for (int i = 2; i <= n; i++)
        // {
        //     if (a[i] - a[i - 1] <= mid)
        //     {
        //         vis[i] = vis[i - 1] = 1;
        //         continue;
        //     }
        //     if (i == 2)
        //     {
        //         int L = a[i - 1] + mid, R = a[i] - mid;
        //         if (R <= L) cnt++;
        //         else cnt += 2;
        //     }
        //     else cnt++;
        //     // int L = a[i - 1] + mid, R = a[i] - mid;

        //     // if (R <= L) cnt++;
        //     // else cnt += 2;
        //     // // int m = (a[i - 1] + a[i]) / 2;
        //     // if (vis[i - 1]) cnt--;
        //     // if (vis[i]) cnt--;
        //     // cout << L << ' ' << R << ' ' << cnt << '\n';

        //     vis[i] = vis[i - 1] = 1;
        // }
        int lst = -2e9;
        for (int i = 1; i <= n; i++)
        {
            // cout << lst << ' ' << cnt << '\n';
            if (vis[i])
            {
                lst = a[i];
                continue;
            }
            if (a[i] - lst <= mid)
            {
                lst = a[i];
                vis[i] = 1;
                continue;
            }
            if (i + 1 <= n && a[i + 1] - a[i] <= mid)
            {
                lst = a[i + 1];
                vis[i] = vis[i + 1] = 1;
                continue;
            }
            lst = a[i] + mid;
            cnt++;
        }
        return cnt <= x;
    };
    // cout << check(1) << '\n';
    int l = 1, r = 1e9;
    int ans = 1e9;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        // cout << mid << ' ' << check(mid) << '\n';
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}