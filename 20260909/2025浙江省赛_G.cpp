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
struct Node
{
    int l, t;
};
void moth()
{
    int n, k;
    cin >> n >> k;
    vector<Node> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i].l;
    auto check = [&](int x) -> bool
    {
        int sum = 0;
        for (int i = 1; i <= n; i++) sum += max(0, x - (100 + a[i].l - 1) / a[i].l + 1);
        return sum <= k;
    };
    int x = -1;
    int l = 0, r = k + 99;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (check(mid))
        {
            x = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    int res = k;
    for (int i = 1; i <= n; i++)
    {
        a[i].t = max(0, x - (100 + a[i].l - 1) / a[i].l + 1);
        res -= a[i].t;
    }
    sort(a.begin() + 1, a.end(), [&](Node &u, Node &v) { return v.l * (100 + u.t * u.l) < u.l * (100 + v.t * v.l); });
    for (int i = 1; i <= res; i++) a[i].t++;
    long double ans = 1;
    for (int i = 1; i <= n; i++) ans *= (1.0L * a[i].l * a[i].t / 100 + 1);
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cout << fixed << setprecision(10);
    cin >> _;
    while (_--) moth();
    return 0;
}