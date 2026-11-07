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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    // vector<ll> p(n + 1);
    // for (int i = 1; i <= n; i++) p[i] = p[i - 1] + a[i];
    // vector<int> cnt(n + 1), cnt2(n + 1);
    // cnt[1] = 1;
    // for (int i = 2; i <= n; i++)
    // {
    //     cnt[i] = cnt[i - 1];
    //     if (a[i] * (i - 1) >= p[i - 1]) cnt[i]++;
    // }
    // auto b = a;
    // reverse(b.begin() + 1, b.end());
    // cnt2[1] = 1;

    // vector<ll> p2(n + 1);
    // int duan = -1;
    // for (int i = 1; i <= n; i++) p2[i] = p2[i - 1] + b[i];
    // for (int i = 2; i <= n; i++)
    // {
    //     cnt2[i] = cnt2[i - 1];
    //     if (b[i] * (i - 1) >= p2[i - 1]) cnt2[i]++;
    // }
    // for (int i = 0; i <= n; i++)
    // {
    //     // b:[1,n-i]
    //     int l = 1, r = n - i;
    //     int st = n - i + 1;
    //     while (l <= r)
    //     {
    //         int mid = (l + r) >> 1;
    //         if (b[mid] * (i + mid - 1) >= p[i] + p2[mid - 1])
    //         {
    //             st = mid;
    //             r = mid - 1;
    //         }
    //         else l = mid + 1;
    //     }
    //     if (cnt[i] + (n - i - st + 1) == k)
    //     {
    //         duan = i;
    //         break;
    //     }
    // }
    // if (duan != -1)
    // {
    //     cout << "YES\n";
    //     for (int i = 1; i <= duan; i++) cout << a[i] << " ";
    //     for (int i = n; i > duan; i--) cout << a[i] << " ";
    //     cout << '\n';
    //     return;
    // }
    // for (int i = 0; i <= n; i++)
    // {
    //     // a:[1,n-i]
    //     int l = 1, r = n - i;
    //     int st = 0;
    //     while (l <= r)
    //     {
    //         int mid = (l + r) >> 1;
    //         if (a[mid] * (i + mid - 1) >= p2[i] + p[mid - 1])
    //         {
    //             st = mid;
    //             l = mid + 1;
    //         }
    //         else r = mid - 1;
    //     }
    //     if (cnt2[i] + st == k)
    //     {
    //         duan = i;
    //         break;
    //     }
    // }
    // if (duan != -1)
    // {
    //     cout << "YES\n";
    //     for (int i = 1; i <= duan; i++) cout << b[i] << " ";
    //     for (int i = n; i > duan; i--) cout << b[i] << " ";
    //     cout << '\n';
    //     return;
    // }
    // cout << "NO\n";
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == a[n]) cnt++;
    }
    if (k < cnt)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = n - k + 1; i <= n; i++) cout << a[i] << " ";
    for (int i = n - k; i >= 1; i--) cout << a[i] << " ";
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}