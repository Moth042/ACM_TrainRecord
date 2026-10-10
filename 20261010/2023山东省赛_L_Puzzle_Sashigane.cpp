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
    int n, x, y;
    cin >> n >> x >> y;
    cout << "Yes\n";
    vector<array<int, 4>> ans;
    // LU
    if ((x - 1 >= 1 && y - 1 >= 1) || (x + 1 <= n && y + 1 <= n))
    {
        int t = 1;
        while (x - t >= 1 && y - t >= 1)
        {
            ans.push_back({x - t, y - t, t, t});
            t++;
        }
        --t;
        int s = 1;
        while (x + s <= n && y + s <= n)
        {
            ans.push_back({x + s, y + s, (x - t) - (x + s), (y - t) - (y + s)});
            s++;
        }
        --s;
        int p = 1;
        while (x - t - p >= 1 && y + s + p <= n)
        {
            int len = y + s + p - 1;
            ans.push_back({x - t - p, y + s + p, len, -len});
            p++;
        }
        int q = 1;
        while (x + s + q <= n && y - t - q >= 1)
        {
            int len = x + s + q - 1;
            ans.push_back({x + s + q, y - t - q, -len, len});
            q++;
        }
    }
    else
    {
        int t = 1;
        while (x - t >= 1 && y + t <= n)
        {
            ans.push_back({x - t, y + t, t, -t});
            t++;
        }
        --t;
        int s = 1;
        while (x + s <= n && y - s >= 1)
        {
            ans.push_back({x + s, y - s, (x - t) - (x + s), (y + t) - (y - s)});
            s++;
        }
        --s;
        int p = 1;
        while (x + s + p <= n && y + t + p <= n)
        {
            int len = y + t + p;
            ans.push_back({x + s + p, y + t + p, len, -len});
            p++;
        }
        int q = 1;
        while (x - t - q >= 1 && y - s - q >= 1)
        {
            int len = n - (x - t - q);
            ans.push_back({x + s + q, y - t - q, -len, len});
            q++;
        }
    }
    cout << ans.size() << '\n';
    for (auto [x, y, h, w] : ans) cout << x << ' ' << y << ' ' << h << ' ' << w << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}