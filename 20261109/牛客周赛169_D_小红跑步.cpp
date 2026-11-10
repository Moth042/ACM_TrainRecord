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
    int n, m;
    cin >> n >> m;
    vector<string> a(n + 1);
    int sx = -1, sy = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] = " " + a[i];
        // cout << a[i] << '\n';
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == '*')
            {
                if (sx == -1 && sy == -1)
                {
                    sx = i;
                    sy = j;
                }
            }
        }
    }
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int px = -1, py = -1;
    int x = sx, y = sy;
    int st = -1, ed = -1;
    int cnt = 0;
    do
    {
        // cout << x << ' ' << y << ' ' << px << ' ' << py << '\n';
        // if (cnt > 21) break;
        if (x == x1 && y == y1) st = cnt;
        if (x == x2 && y == y2) ed = cnt;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            // if (x == 1 && y == 4 && nx == 2 && ny == 4) cout << a[nx][ny] << '\n';
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '*' && (nx != px || ny != py))
            {
                px = x;
                py = y;
                x = nx;
                y = ny;
                break;
            }
        }
        cnt++;
    } while (x != sx || y != sy);
    cout << (ed - st + cnt) % cnt << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}