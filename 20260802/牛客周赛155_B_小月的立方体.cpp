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
    vector<vector<vector<ll>>> a(n + 1, vector<vector<ll>>(n + 1, vector<ll>(n + 1)));
    int cnt = 0;
    int k = 0;
    while (k <= n)
    {
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {

                cin >> a[i][j][k];
                cnt++;
                // cout << i << " " << j << " " << k << " "<<a[i][j][k]<<"\n";
                if (cnt % ((n + 1) * (n + 1)) == 0) k++;
            }
        }
    }
    // ll ans = a[0][0][0] + a[0][0][n] + a[0][n][0] + a[0][n][n] + a[n][0][0] + a[n][0][n] + a[n][n][0] + a[n][n][n];
    // if (n % 2 == 0) ans += a[n / 2][n / 2][n / 2] * 4;
    // cout << ans << '\n';
    // cout<<a[0][0][0]<<" "<<a[0][0][n]<<" "<<a[0][n][0]<<" "<<a[0][n][n]<<" "<<a[n][0][0]<<" "<<a[n][0][n]<<" "<<a[n][n][n]<<" "<<
    ll ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans += a[n - i][i][i];
        ans += a[i][i][n - i];
        ans += a[i][n - i][i];
        ans += a[i][i][i];
    }
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