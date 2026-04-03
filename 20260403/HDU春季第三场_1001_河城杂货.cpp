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
        if (c == '-')
            s = -1;
        c = getchar();
    }
    return x * s;
}
// 快写
void write(i128 x)
{
    if (x > 9)
        write(x / 10);
    putchar(x % 10 | 48);
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int randint(int l, int r)
{
    return uniform_int_distribution{l, r}(rnd);
}
void moth()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1), b(n + 2), pre1(n + 2), pre2(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n + 1; i++)
        cin >> b[i];
    sort(a.begin() + 1, a.end(), greater());
    sort(b.begin() + 1, b.end(), greater());
    auto check = [&](ll x) -> bool
    {
        int st = n + 1;
        i128 ans = 0;
        // bool tag = 0;
        // for (int i = 1; i <= n; i++)
        // {
        //     if (a[i] >= x)
        //         ans += a[i] * b[st];
        //     else if(!tag)
        //         ans += x * b[st], i--,  tag = 1;
        //     cout << ans << '\n';
        //     st++;
        // }
        for (int i = 1; i <= n; i++)
        {
            if (a[i] < x)
            {
                st = i;
                break;
            }
        }
        if (st != n + 1)
        {
            for (int i = 1; i <= st - 1; i++)
                ans += (i128)a[i] * b[i];
            for (int i = st; i <= n; i++)
                ans += (i128)a[i] * b[i + 1];
            ans += (i128)x * b[st];
        }
        else
        {
            for (int i = 1; i <= n; i++)
                ans += (i128)a[i] * b[i];
            ans += (i128)x * b[n + 1];
        }
        return ans >= m;
    };
    ll l = 0, r = 1e18;
    // cout << check(2) << '\n';
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--)
        moth();
    return 0;
}