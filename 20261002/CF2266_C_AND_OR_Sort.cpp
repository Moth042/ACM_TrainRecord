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
    string s;
    cin >> s;
    s = " " + s;
    vector<int> p0(n + 1);
    for (int i = 1; i <= n; i++) p0[i] = p0[i - 1] + (s[i] == '0');
    if (s[1] == '1')
    {
        cout << p0[n] << '\n';
        return;
    }
    int st = -1;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1')
        {
            st = i;
            break;
        }
    }
    if (st == -1) cout << 0 << '\n';
    else
    {
        int ans = 1e9;
        for (int i = st; i <= n + 1; i++)
        {
            int cur = i - 1 - p0[i - 1] + p0[n] - p0[i - 1];
            ans = min(ans, cur);
        }
        cout << ans << '\n';
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