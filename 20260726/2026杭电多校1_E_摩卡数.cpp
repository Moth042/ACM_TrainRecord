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
vector<int> kmp(string s)
{
    int n = s.size();
    vector<int> f(n + 1);
    for (int i = 1, j = 0; i < n; i++)
    {
        while (j && s[i] != s[j]) j = f[j];
        j += (s[i] == s[j]);
        f[i + 1] = j;
    }
    return f;
}
void moth()
{
    // string s;
    // cin >> s;
    // int n = s.length();
    // auto f = kmp(s);
    // s = " " + s;
    // // for (int i = 1; i <= n; i++) cout << f[i] << ' ';
    // int k = 0;
    // vector<int> cnt(n + 1);
    // for (int i = 1; i <= n - 1; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         char c = (char)('a' + j);
    //         int pos = i;
    //         while (pos > 0 && c != s[pos + 1])
    //         {
    //             // cout << i << ' ';
    //             k++;
    //             cnt[i]++;
    //             pos = f[pos];
    //         }
    //     }
    // }
    // cout << k << '\n';
    // for (int i = 1; i <= n; i++) cout << cnt[i] << " ";
    ll m;
    cin >> m;
    ll l = 1, r = 1e5;
    while (l < r)
    {
        ll mid = (l + r + 1) >> 1;
        if (mid * (mid - 1) / 2 <= m) l = mid;
        else r = mid - 1;
    }
    ll s = m - l * (l - 1) / 2;
    cout << l + s << ' ' << 2 << '\n';
    for (int i = 1; i <= l; i++) cout << "a";
    for (int i = 1; i <= s; i++) cout << "b";
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}