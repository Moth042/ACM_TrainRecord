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
    vector<pair<ll, ll>> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            auto [x1, y1] = a[i];
            auto [x2, y2] = a[j];
            int e1 = 0, e2 = 0;
            for (int k = 1; k <= n; k++)
            {
                if (k == i || k == j) continue;
                auto [x3, y3] = a[k];
                if (x1 == x2)
                {
                    if (x3 > x1) e1++;
                    else if (x3 < x1) e2++;
                }
                else if (y1 == y2)
                {
                    if (y3 > y1) e1++;
                    else if (y3 < y1) e2++;
                }
                else
                {
                    if ((y2 - y1) * (x3 - x1) + (x2 - x1) * y1 > (x2 - x1) * y3) e1++;
                    else if ((y2 - y1) * (x3 - x1) + (x2 - x1) * y1 < (x2 - x1) * y3) e2++;
                }
            }
            if (e1 == e2) ans++;
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}