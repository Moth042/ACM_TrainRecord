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
    string s, t;
    cin >> s >> t;
    s = " " + s;
    t = " " + t;
    vector<vector<int>> p(n + 1, vector<int>(4));
    for (int i = 1; i <= n; i++)
    {
        int cur = 2 * (s[i] - '0') + (t[i] - '0');
        for (int j = 0; j < 4; j++) p[i][j] = p[i - 1][j] + (j == cur);
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int c00 = p[r][0] - p[l - 1][0], c01 = p[r][1] - p[l - 1][1], c10 = p[r][2] - p[l - 1][2], c11 = p[r][3] - p[l - 1][3];
        if (abs(c01 - c10) <= c00 + c11) cout << "YES\n";
        else cout << "NO\n";
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