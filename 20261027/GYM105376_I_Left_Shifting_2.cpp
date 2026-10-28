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
    string s;
    cin >> s;
    int n = s.length();
    s = " " + s;
    int R = 1, sum = 0;
    for (int i = 1; i <= n;)
    {
        while (R <= n && s[i] == s[R]) R++;
        sum += (R - i) / 2;
        i = R;
    }
    int l = 1, r = n;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == s[1]) l = i;
        else break;
    }
    for (int i = n; i >= 1; i--)
    {
        if (s[i] == s[n]) r = i;
        else break;
    }
    if (r <= l)
    {
        cout << sum << '\n';
        return;
    }
    R = 1;
    int ans = sum;
    for (int i = 1; i <= n;)
    {
        int cur = sum;
        while (R <= n && s[i] == s[R]) R++;
        if ((R - i) % 2 == 0)
        {
            cur--;
            int len = min(l, i) + min(n - r + 1, n - i);
            if (s[1] == s[n] && len % 2 == 0) cur++;
        }
        i = R;
        ans = min(ans, cur);
    }
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}