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
    ll n, r1, s1, p1, r2, s2, p2;
    cin >> n >> r1 >> s1 >> p1 >> r2 >> s2 >> p2;
    ll ans1 = 0, ans2 = 0;

    ll rr1 = r1, ss1 = s1, pp1 = p1, rr2 = r2, ss2 = s2, pp2 = p2;
    ll df1 = min(rr1, ss2), df2 = min(ss1, pp2), df3 = min(pp1, rr2);
    rr1 -= df1;
    ss2 -= df1;
    ans1 += df1;
    ss1 -= df2;
    pp2 -= df2;
    ans1 += df2;
    pp1 -= df3;
    rr2 -= df3;
    ans1 += df3;
    ll df4 = min(rr1, rr2), df5 = min(ss1, ss2), df6 = min(pp1, pp2);
    rr1 -= df4;
    rr2 -= df4;
    ss1 -= df5;
    ss2 -= df5;
    pp1 -= df6;
    pp2 -= df6;
    ans1 -= min(rr1, pp2);
    ans1 -= min(ss1, rr2);
    ans1 -= min(pp1, ss2);
    // cout << ans1 << '\n';
    rr1 = r1, ss1 = s1, pp1 = p1, rr2 = r2, ss2 = s2, pp2 = p2;
    swap(rr1, rr2);
    swap(ss1, ss2);
    swap(pp1, pp2);
    df1 = min(rr1, ss2), df2 = min(ss1, pp2), df3 = min(pp1, rr2);
    rr1 -= df1;
    ss2 -= df1;
    ans2 -= df1;
    ss1 -= df2;
    pp2 -= df2;
    ans2 -= df2;
    pp1 -= df3;
    rr2 -= df3;
    ans2 -= df3;
    df4 = min(rr1, rr2), df5 = min(ss1, ss2), df6 = min(pp1, pp2);
    rr1 -= df4;
    rr2 -= df4;
    ss1 -= df5;
    ss2 -= df5;
    pp1 -= df6;
    pp2 -= df6;
    ans2 += min(rr1, pp2);
    ans2 += min(ss1, rr2);
    ans2 += min(pp1, ss2);
    cout << ans1 << ' ' << ans2 << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}