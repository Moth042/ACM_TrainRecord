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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> h(n + 1, vector<int>(m + 1));
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x1, y1, x2, y2, k;
            cin >> x1 >> y1 >> x2 >> y2 >> k;
            for (int i = x1; i <= x2; i++)
            {
                for (int j = y1; j <= y2; j++) h[i][j] += k;
            }
        }
        else
        {
            int x, y;
            cin >> x >> y;
            int cnt = 0;
            for (int i = x; i >= 1; i--)
            {
                if (h[i][y] <= h[x][y]) cnt++;
                else break;
            }
            for (int i = x + 1; i <= n; i++)
            {
                if (h[i][y] <= h[x][y]) cnt++;
                else break;
            }
            for (int i = y; i >= 1; i--)
            {
                if (h[x][i] <= h[x][y]) cnt++;
                else break;
            }
            for (int i = y + 1; i <= m; i++)
            {
                if (h[x][i] <= h[x][y]) cnt++;
                else break;
            }
            cout << cnt - 1 << ' ';
        }
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