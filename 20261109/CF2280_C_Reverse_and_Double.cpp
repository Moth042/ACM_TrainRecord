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
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<ll> p(n + 1);
    for (int i = 1; i < n; i++) p[i] = abs(a[i + 1] - a[i]);
    int LOG = __lg(n) + 1;
    vector<vector<ll>> st(n + 1, vector<ll>(LOG + 1));
    for (int i = 1; i < n; i++) st[i][0] = p[i];
    vector<ll> lg2(n + 1, 0);
    for (int i = 2; i <= n; i++) lg2[i] = lg2[i >> 1] + 1;
    for (int j = 1; j <= LOG; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
    auto getMax = [&](int l, int r) -> ll
    {
        ll k = lg2[r - l + 1];
        return max(st[l][k], st[r - (1 << k) + 1][k]);
    };
    auto f = [&](int l, int r) -> ll
    {
        ll mx = (l - 2 <= 0 ? 0 : getMax(1, l - 2));
        // cout << mx << '\n';
        if (l != r) mx = max(mx, getMax(l, r - 1) * 2);
        // cout << mx << '\n';
        if (r + 1 <= n) mx = max(mx, abs(a[l] * 2 - a[r + 1]));
        // cout << mx << '\n';
        if (l - 1 > 0) mx = max(mx, abs(a[r] * 2 - a[l - 1]));
        // cout << mx << '\n';
        if (r <= n - 2) mx = max(mx, getMax(r + 1, n - 1));
        // cout << mx << '\n';
        return mx;
    };
    ll mx = getMax(1, n - 1);
    vector<int> id;
    for (int i = 1; i <= n - 1; i++)
    {
        if (p[i] == mx) id.push_back(i);
    }
    if (id.size() >= 3) cout << mx << '\n';
    else if (id.size() == 2)
    {
        int l = id[0], r = id[1];
        cout << min(mx, f(l + 1, r)) << '\n';
    }
    else
    {
        int st = id[0];
        // r=st
        for (int i = 1; i <= st; i++) mx = min(mx, f(i, st));
        // l=st+1
        for (int i = st + 1; i <= n; i++) mx = min(mx, f(st + 1, i));
        cout << mx << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}