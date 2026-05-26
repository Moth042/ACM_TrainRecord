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
    vector<ll> a(n + 1), b(n * 2 + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        b[n + i] = b[i];
    }
    vector<vector<ll>> vis(401, vector<ll>(401, 1e9)), cost(401, vector<ll>(401, 1e9));
    for (int i = 1; i <= 400; i++) vis[i][i] = 0;

    for (int i = 1; i <= m; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        vis[x][y] = min(vis[x][y], z);
    }

    for (int k = 1; k <= 400; k++)
    {
        for (int i = 1; i <= 400; i++)
        {
            for (int j = 1; j <= 400; j++)
            {
                vis[i][j] = min(vis[i][j], vis[i][k] + vis[k][j]);
            }
        }
    }
    for (int i = 1; i <= 400; i++)
    {
        for (int j = 1; j <= 400; j++)
        {
            for (int k = 1; k <= 400; k++)
            {
                cost[i][j] = min(cost[i][j], vis[i][k] + vis[j][k]);
            }
        }
    }
    ll ans = 1e18;
    for (int i = 0; i < n; i++)
    {
        bool ok = 1;
        ll sum = 0;
        for (int j = 1; j <= n; j++)
        {
            ll mn = cost[a[j]][b[j + i]];
            if (mn == 1e9)
            {
                ok = 0;
                break;
            }
            sum += mn;
        }
        if (!ok) continue;
        ans = min(ans, sum);
    }
    if (ans == 1e18) ans = -1;
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}