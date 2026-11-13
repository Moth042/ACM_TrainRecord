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
    string s;
    cin >> n >> s;
    s = " " + s;
    vector<vector<int>> idx(27);
    vector<int> fa(27);
    for (int i = 1; i < 27; i++) fa[i] = i;
    for (int i = 1; i <= n; i++) idx[(int)(s[i] - 'a') + 1].push_back(i);
    for (int i = 2; i <= 26; i++)
    {
        for (auto j : idx[i])
        {
            int tj = n - j + 1;
            if (s[tj] < s[j]) fa[(int)(s[j] - 'a') + 1] = min(fa[(int)(s[j] - 'a') + 1], fa[(int)(s[tj] - 'a') + 1]);
        }
    }
    // for (int i = 0; i < 26; i++) cout << fa[i] << " ";
    // int LOG = __lg(27) + 1;
    // vector<vector<ll>> st(27, vector<ll>(LOG + 1));
    // for (int i = 1; i <= 27; i++) st[i][0] = fa[i];
    // vector<ll> lg2(27, 0);
    // for (int i = 2; i <= 27; i++) lg2[i] = lg2[i >> 1] + 1;
    // for (int j = 1; j <= LOG; j++)
    // {
    //     for (int i = 1; i + (1 << j) - 1 <= n; i++) st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    // }
    // auto getMin = [&](int l, int r) -> ll
    // {
    //     ll k = lg2[r - l + 1];
    //     return min(st[l][k], st[r - (1 << k) + 1][k]);
    // };
    for (int i = 1; i <= 26; i++)
    {
        int t = fa[i];
        for (int j = t; j <= i; j++) fa[i] = min(fa[i], fa[j]);
    }
    // for (int i = 1; i <= 26; i++) cout << fa[i] << ' ';
    int ans = 0;
    for (int i = 26; i >= 1; i--)
    {
        if (fa[i] == i) continue;
        int f = fa[i];
        ans += i - f;
        i = f + 1;
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