#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int N = 2e5 + 9;
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
        if (c == '-')
            s = -1;
        c = getchar();
    }
    return x * s;
}
// 快写
void write(i128 x)
{
    if (x > 9)
        write(x / 10);
    putchar(x % 10 | 48);
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int randint(int l, int r)
{
    return uniform_int_distribution{l, r}(rnd);
}
int p[N], vis[N], cnt;
int a[N]; // 记录i的最小质因子的次数
int d[N]; // 记录i的约数个数
void get_d(int n)
{
    d[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            p[++cnt] = i;
            a[i] = 1;
            d[i] = 2;
        }
        for (int j = 1; i * p[j] <= n; j++)
        {
            int m = i * p[j];
            vis[m] = 1;
            if (i % p[j] == 0)
            {
                a[m] = a[i] + 1;
                d[m] = d[i] / a[m] * (a[m] + 1);
                break;
            }
            else
            {
                a[m] = 1;
                d[m] = 2 * d[i];
            }
        }
    }
}
void moth()
{
    int n, k;
    cin >> n >> k;
    vector<int> ans(n + 1);
    // cout << d[1] << ' ' << d[6] << '\n';
    // cout << d[9] << '\n';
    for (int i = 1; i <= n; i++)
    {
        ans[i] = d[i] - 1 + (n / i - 1);
        // cout << ans[i] << " \n"[i == n];
    }
    sort(ans.begin() + 1, ans.end(), greater());
    cout << ans[k] << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    get_d(200000);
    int _ = 1;
    cin >> _;
    while (_--)
        moth();
    return 0;
}