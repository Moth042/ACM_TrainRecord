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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int df = 0, mx = 0, sz = 0;
    int l = 1, r = 1;
    vector<pair<int, int>> ans;
    int cnt = 0;
    bool tag = 0;
    for (r = 1; r <= n;)
    {
        // mx = max(mx, a[r] - df);
        // sz++;
        // if (sz > 0 && mx == sz)
        // {
        //     df += sz;
        //     if (r != l && a[l] > a[r]) ans.push_back({l, r});
        //     r++;
        //     l = r;
        //     mx = sz = 0;
        // }
        // else r++;
        if (!tag && a[r] == r)
        {
            r++;
            l = r;
            cnt = 0;
            continue;
        }
        tag = 1;
        // cout<<a[l]<<' '<<a[r]<<'\n';
        if (a[r] == l || a[r] == l + 1) cnt++;
        if (cnt == 2)
        {
            while (r <= n && a[l] < a[r]) r++;
            ans.push_back({l, r});
            sort(a.begin() + l, a.begin() + r + 1);
            cnt = 0;
            r = l + 2;
            l = r;
            tag = 0;
            continue;
        }
        r++;
    }
    cout << ans.size() << '\n';
    for (auto [l, r] : ans) cout << l << ' ' << r << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}