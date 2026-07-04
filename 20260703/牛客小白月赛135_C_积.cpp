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
    int p3 = 0, p9 = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] % 3 == 0) p3++;
        if (a[i] % 9 == 0) p9++;
    }
    if (p9 > 0 || p3 >= 2) cout << 0 << '\n';
    else
    {
        vector<ll> to9(n + 1), to3(n + 1);
        for (int i = 1; i <= n; i++)
        {
            ll cur = a[i];
            to9[i] = (cur + 8) / 9 * 9 - cur;
            to3[i] = (cur + 2) / 3 * 3 - cur;
        }
        ll ans1 = 1e18, ans2 = 1e18;
        for (int i = 1; i <= n; i++)
        {
            ans1 = min(ans1, to9[i]);
            // ans2 = min(ans2, to3[i]);
        }
        if (n == 1)
        {
            cout << ans1 << '\n';
            return;
        }
        if (p3 == 1)
        {
            for (int i = 1; i <= n; i++)
            {
                if (to3[i]) ans2 = min(ans2, to3[i]);
            }
            cout << min(ans1, ans2) << '\n';
        }
        else
        {
            sort(to3.begin() + 1, to3.end());
            cout << min(ans1, to3[1] + to3[2]) << '\n';
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