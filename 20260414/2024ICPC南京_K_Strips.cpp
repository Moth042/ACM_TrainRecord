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
    ll n, m, k, w;
    cin >> n >> m >> k >> w;
    vector<ll> rd(n + 1), blk(m + 1);
    for (int i = 1; i <= n; i++) cin >> rd[i];
    for (int i = 1; i <= m; i++) cin >> blk[i];
    sort(rd.begin() + 1, rd.end());
    sort(blk.begin() + 1, blk.end());
    vector<ll> b;
    b.push_back(0);
    for (int i = 1; i <= m; i++) b.push_back(blk[i]);
    b.push_back(w + 1);
    int t = 1;
    vector<ll> ans;
    for (int i = 1; i < b.size(); i++)
    {
        ll L = b[i - 1] + 1, R = b[i] - 1;
        if (R < L) continue;
        vector<ll> cur;
        while (t <= n && rd[t] < L) t++;
        while (t <= n && rd[t] <= R)
        {
            cur.push_back(rd[t]);
            t++;
        }
        ll cover = L - 1;
        vector<ll> need;
        for (auto x : cur)
        {
            if (x > cover)
            {
                need.push_back(x);
                cover = x + k - 1;
            }
        }
        int sz = need.size();
        vector<ll> st(sz);
        for (int j = sz - 1; j >= 0; j--)
        {
            ll mn = max(L, need[j] - k + 1), mx = min(R - k + 1, need[j]);
            if (j + 1 < sz) mx = min(mx, st[j + 1] - k);
            if (mx < mn)
            {
                cout << -1 << '\n';
                return;
            }
            st[j] = mx;
        }
        for (auto x : st) ans.push_back(x);
    }
    cout << ans.size() << '\n';
    for (auto i : ans) cout << i << " \n"[i == ans.back()];
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}