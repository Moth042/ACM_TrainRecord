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
    ll n, m, k;
    cin >> n >> m >> k;
    ll sum = 0;
    vector<vector<ll>> a(n + 1, vector<ll>(m + 1));
    for (int i = 1; i <= n; i++) a[i][1] = (i % 2 ? 1 : 2), sum += a[i][1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 2; j <= m; j++)
        {
            if (a[i][j - 1] == 1) a[i][j] = 2;
            else a[i][j] = 1;
            sum += a[i][j];
        }
    }
    if (sum > k) cout << "NO\n";
    else if (sum == k)
    {
        cout << "YES\n";
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++) cout << a[i][j] << ' ';
            cout << '\n';
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int t = a[i][j];
                // cout << k <<' ' <<sum<<' '<<a[i][j]<< '\n';
                a[i][j] = k - (sum - a[i][j]);

                bool ok = 1;
                for (int p = 0; p < 4; p++)
                {
                    int nx = i + dx[p], ny = j + dy[p];
                    if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == a[i][j])
                    {
                        ok = 0;
                        a[i][j] = t;
                        break;
                    }
                }
                if (ok)
                {
                    cout << "YES\n";
                    for (int i = 1; i <= n; i++)
                    {
                        for (int j = 1; j <= m; j++) cout << a[i][j] << " ";
                        cout << '\n';
                    }
                    return;
                }
            }
        }
        cout << "NO\n";
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