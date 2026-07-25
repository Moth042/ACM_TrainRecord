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
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<vector<int>>> cnt(30, vector<vector<int>>(2, vector<int>(2)));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            int x = (a[i] >> j) & 1, y = (j + 1 < 30 ? (a[i] >> (j + 1)) & 1 : 0);
            cnt[j][x][y]++;
        }
    }
    auto cal = [&](int op, int x, int y) -> int
    {
        if (op == 1) return x & y;
        if (op == 2) return x | y;
        return x ^ y;
    };
    int q;
    cin >> q;
    while (q--)
    {
        int op, x;
        cin >> op >> x;
        for (int bit = 0; bit < 30; bit++)
        {
            vector<vector<int>> tmp(2, vector<int>(2));
            int p = (x >> bit) & 1;
            int q = (bit + 1 < 30 ? (x >> (bit + 1)) & 1 : 0);
            for (int i = 0; i <= 1; i++)
            {
                for (int j = 0; j <= 1; j++) tmp[cal(op, i, p)][cal(op, j, q)] += cnt[bit][i][j];
            }
            for (int i = 0; i <= 1; i++)
            {
                for (int j = 0; j <= 1; j++) cnt[bit][i][j] = tmp[i][j];
            }
        }
        int ans = 0;
        for (int bit = 0; bit < 30; bit++) ans += cnt[bit][1][0];
        cout << ans << '\n';
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