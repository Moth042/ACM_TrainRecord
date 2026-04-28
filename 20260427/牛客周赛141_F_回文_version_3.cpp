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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = " " + s;
    vector<vector<ll>> pre(n + 1, vector<ll>(27)), p1(n + 1, vector<ll>(27)), p2(n + 1, vector<ll>(27));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 26; j++)
        {
            pre[i][j] = pre[i - 1][j] + (s[i] == (char)('a' + j - 1));
            p1[i][j] = p1[i - 1][j] + pre[i][j];
            p2[i][j] = p2[i - 1][j] + pre[i - 1][j] * pre[i][j];
            // cout<<p2[i][j]<<' ';
        }
    }
    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        if (x == 1) cout << r - l + 1 << '\n';
        else if (x == 2)
        {
            ll ans = 0;
            for (int i = 1; i <= 26; i++)
            {
                ll t = pre[r][i] - pre[l - 1][i];
                ans += t * (t - 1) / 2;
            }
            cout << ans << '\n';
        }
        else
        {
            ll ans = 0;
            for (int i = 1; i <= 26; i++)
            {
                ans += pre[r][i] * (p1[r - 1][i] - p1[max(l - 2, 0)][i]);
                ans += pre[l - 1][i] * (p1[r][i] - p1[l - 1][i]);
                ans -= p2[r][i] - p2[l - 1][i];
                ans -= pre[l - 1][i] * pre[r][i] * (r - l + 1);
            }
            cout << ans << '\n';
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}