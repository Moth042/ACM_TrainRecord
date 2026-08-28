#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
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
    int mx, mn;
    vector<int> cur;
};
void moth()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> cnt;
    for (int i = 1; i <= n; i++) cin >> a[i], cnt[a[i]]++;
    sort(a.begin() + 1, a.end());
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int md = a[i], mn = a[j], mx = md * 2 - mn;
            if (md < mn || md > mx || !cnt.count(mx)) continue;
            int len = cnt[md];
            int lower = lower_bound(a.begin() + 1, a.end(), md) - lower_bound(a.begin() + 1, a.end(), mn);
            int upper = upper_bound(a.begin() + 1, a.end(), mx) - upper_bound(a.begin() + 1, a.end(), md);
            if (lower == upper) len += lower + upper;
            else if (lower < upper)
            {
                // if(lower<upper)len+=lower;
                int l = lower, r = upper;
                int df = lower;
                while (l <= r)
                {
                    int mid = (l + r) >> 1;
                    if ((lower + len + mid + 1) / 2 <= lower + len)
                    {
                        df = mid;
                        l = mid + 1;
                    }
                    else r = mid - 1;
                }
                len += lower + df;
            }
            else
            {
                int l = upper, r = lower;
                int df = upper;
                while (l <= r)
                {
                    int mid = (l + r) >> 1;
                    if ((upper + len + mid + 1) / 2 > mid)
                    {
                        df = mid;
                        l = mid + 1;
                    }
                    else r = mid - 1;
                }
                len += upper + df;
            }
            ans = max(ans, len);
        }
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