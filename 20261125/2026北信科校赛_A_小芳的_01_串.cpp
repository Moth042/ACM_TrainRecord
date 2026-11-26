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
    string s, t;
    cin >> n >> s >> t;
    int sc0 = 0, tc0 = 0;
    ll ans = 0;
    for (int i = 0; i < n;)
    {
        int j = i;
        // while (j < n && ((!sc0 && !tc0) || sc0 != tc0))
        // {
        //     if (s[j] == '0') sc0++;
        //     if (t[j] == '0') tc0++;
        //     j++;
        // }
        do
        {
            if (j >= n) break;
            if (s[j] == '0') sc0++;
            if (t[j] == '0') tc0++;
            j++;
        } while (j < n && sc0 != tc0);

        sc0 = 0, tc0 = 0;
        ans += 1ll * max(0, j - i - 1);
        i = j;
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