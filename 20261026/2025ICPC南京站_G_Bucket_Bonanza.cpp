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
    vector<ll> v(n + 1), l(n + 1), pv(n + 1), pl(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> l[i];
    sort(v.begin() + 1, v.end(), greater());
    sort(l.begin() + 1, l.end());
    for (int i = 1; i <= n; i++)
    {
        pv[i] = pv[i - 1] + v[i];
        pl[i] = pl[i - 1] + l[i];
    }
    int q;
    cin >> q;
    while (q--)
    {
        ll t;
        cin >> t;
        int low = 1, high = n;
        int st = -1;
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            if (v[mid] > t * l[mid])
            {
                st = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        if (st == -1) cout << 0 << ' ';
        else cout << max(0ll, pv[st] - t * pl[st]) << ' ';
    }
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