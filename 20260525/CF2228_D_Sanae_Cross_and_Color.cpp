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
    vector<pair<int, int>> a(n + 1);
    vector<int> vis(n + 1);
    int mxx = 0;
    vector<vector<int>> px(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
        vis[a[i].second] = 1;
        mxx = max(mxx, a[i].first);
        px[a[i].first].push_back(a[i].second);
    }
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + vis[i];
    vector<int> lmx(mxx + 1, 0), rmx(mxx + 2, 0), lmn(mxx + 1, n + 1), rmn(mxx + 2, n + 1);
    for (int i = 1; i <= mxx; i++)
    {
        lmx[i] = lmx[i - 1];
        lmn[i] = lmn[i - 1];
        for (auto y : px[i])
        {
            lmx[i] = max(lmx[i], y);
            lmn[i] = min(lmn[i], y);
        }
    }
    for (int i = mxx; i >= 1; i--)
    {
        rmx[i] = rmx[i + 1];
        rmn[i] = rmn[i + 1];
        for (auto y : px[i])
        {
            // cout << i << ' ' << y << '\n';
            rmx[i] = max(rmx[i], y);
            rmn[i] = min(rmn[i], y);
        }
    }
    // cout << lmn[2] << ' ' << rmn[2] << '\n';
    ll ans = 0;
    for (int i = 1; i < mxx; i++)
    {
        if (px[i].empty()) continue;
        int l = max(lmn[i], rmn[i + 1]), r = min(lmx[i], rmx[i + 1]);
        // cout << i << ' ' << l << ' ' << r << '\n';
        if (l <= r) ans += pre[r - 1] - pre[l - 1];
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