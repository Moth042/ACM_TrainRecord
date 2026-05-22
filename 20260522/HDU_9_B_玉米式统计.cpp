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
    int cnt1 = 0, cnt2 = 0, cnt3 = 0, win1 = 0, win2 = 0, win3 = 0;
    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1 && b == 0)
        {
            cnt1++;
            win1 += c;
        }
        else if (a == 0 && b == 1)
        {
            cnt2++;
            win2 += c;
        }
        else if (a == 1 && b == 1)
        {
            cnt3++;
            win3 += c;
            cnt2++;
            win2 += c;
            cnt1++;
            win1 += c;
        }
    }
    double ans1 = (cnt1 == 0 ? 0 : 1.0 * win1 * 100 / cnt1), ans2 = (cnt2 == 0 ? 0 : 1.0 * win2 * 100 / cnt2),
           ans3 = (cnt3 == 0 ? 0 : 1.0 * win3 * 100 / cnt3);
    cout << fixed << setprecision(2) << max(ans1, max(ans2, ans3)) << "%\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}