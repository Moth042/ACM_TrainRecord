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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (n == k)
    {
        for (int i = 1; i <= n; i++) cout << '-';
        cout << '\n';
        return;
    }
    // int fst = 1, lst = n;
    vector<char> ans(n + 1, '+');
    // for (int i = 0; i < k; i++)
    // {
    //     if (s[i] == '0')
    //     {
    //         if (fst - 1 >= 1 && ans[fst - 1] == '?')
    //         {
    //             ans[fst - 1] = '-';
    //             if (fst <= lst && ans[fst] == '+') ans[fst++] = '?';
    //         }
    //         else ans[fst++] = '-';
    //     }
    //     else if (s[i] == '1')
    //     {
    //         if (lst + 1 <= n && ans[lst + 1] == '?')
    //         {
    //             ans[lst + 1] = '-';
    //             if (fst <= lst && ans[lst] == '+') ans[lst--] = '?';
    //         }
    //         else ans[lst--] = '-';
    //     }
    //     else ans[fst++] = ans[lst--] = '?';
    // }
    // for (int i = 1; i <= n; i++) cout << ans[i];
    // cout << '\n';
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (auto i : s)
    {
        if (i == '0') cnt0++;
        if (i == '1') cnt1++;
        if (i == '2') cnt2++;
    }
    int l = 1, r = n;
    for (int i = 1; i <= cnt0; i++)
    {
        ans[i] = '-';
        l++;
    }
    for (int i = n; i >= n - cnt1 + 1; i--)
    {
        ans[i] = '-';
        r--;
    }
    int t = 0;
    while (l <= r && t < cnt2)
    {
        ans[l++] = ans[r--] = '?';
        t++;
    }
    for (int i = 1; i <= n; i++) cout << ans[i];
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