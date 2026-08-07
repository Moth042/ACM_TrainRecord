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
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> a(x + 1), b(y + 1);
    for (int i = 1; i <= x; i++) cin >> a[i];
    for (int i = 1; i <= y; i++) cin >> b[i];
    // n,m-1
    // ll ans1 = 0, ans2 = 0;
    // int h = 0, l = 0;
    // int st = x;
    // while (st >= 1)
    // {
    //     if (h >= n) break;
    //     if (cnt[a[st]])
    //     {
    //         st--;
    //         continue;
    //     }
    //     ans1 += 1ll * a[st];
    //     cnt[a[st]] = 1;
    //     h++;
    //     st--;
    // }
    // st = y;
    // while (st >= 1)
    // {
    //     if (l >= m - 1) break;
    //     if (cnt[b[st]])
    //     {
    //         st--;
    //         continue;
    //     }
    //     ans1 += 1ll * b[st];
    //     cnt[b[st]] = 1;
    //     l++;
    //     st--;
    // }
    // for (int i = 0; i <= n + m; i++) cnt[i] = 0;
    // h = l = 0;
    // st = y;
    // // n-1 m
    // while (st >= 1)
    // {
    //     if (l >= m) break;
    //     if (cnt[b[st]])
    //     {
    //         st--;
    //         continue;
    //     }
    //     ans2 += 1ll * b[st];
    //     cnt[b[st]] = 1;
    //     l++;
    //     st--;
    // }
    // st = x;
    // while (st >= 1)
    // {
    //     if (h >= n - 1) break;
    //     if (cnt[a[st]])
    //     {
    //         st--;
    //         continue;
    //     }
    //     ans2 += 1ll * a[st];
    //     cnt[a[st]] = 1;
    //     h++;
    //     st--;
    // }
    // cout << max(ans1, ans2) << '\n';
    vector<int> h, l, wz;
    vector<vector<int>> cnt(n + m + 1, vector<int>(2));
    for (int i = 1; i <= x; i++) cnt[a[i]][0] = 1;
    for (int i = 1; i <= y; i++) cnt[b[i]][1] = 1;
    for (int i = n + m; i >= 1; i--)
    {
        if (cnt[i][0] == 0 && cnt[i][1] == 0) continue;
        if (h.size() + l.size() + wz.size() >= n + m - 1) break;
        if (cnt[i][0] == 1 && cnt[i][1] == 1)
        {
            // if (h.size() < n && l.size() < m) wz.push_back(i);
            // else if(h.size() == n && l.size()<m-1)l.push_back(i);
            // else if(l.size() == m && h.size() < n-1)h.push_back(i);
            wz.push_back(i);
            // cout << i << " " << "wz\n";
        }
        else if (cnt[i][0] == 1)
        {
            if (h.size() < n) h.push_back(i);
            // cout << i << " " << "h\n";
        }
        else
        {
            if (l.size() < m) l.push_back(i);
            // cout << i << " l\n";
        }
    }
    ll ans = 0;
    for (auto i : h) ans += 1ll * i;
    for (auto i : l) ans += 1ll * i;
    for (auto i : wz) ans += 1ll * i;
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