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
    vector<ll> a(n + 1), p(n + 1);
    vector<vector<int>> idx(k);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
        // idx[p[i] % k].push_back(i);
    }
    idx[0].push_back(0);
    ll ans = 0;
    for (int r = 1; r <= n; r++)
    {
        // if (r < k) continue;
        if (r >= k)
        {
            int up = r - k;
            int lo = 0, hi = idx[p[r] % k].size() - 1;
            int st = -1;
            while (lo <= hi)
            {
                int mid = (lo + hi) >> 1;
                if (idx[p[r] % k][mid] < up)
                {
                    st = mid;
                    lo = mid + 1;
                }
                else hi = mid - 1;
            }
            // cout << r << ' ' << st << '\n';
            // if (st != -1) cout << r - idx[p[r] % k][st] << '\n';
            // if (st == -1 || idx[p[r] % k][st] > up) continue;
            if (st != -1 && idx[p[r] % k][st] < up) ans += 1ll * (st + 1);
        }

        idx[p[r] % k].push_back(r);
    }
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