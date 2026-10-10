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
    vector<int> h(n + 1);
    string s;
    for (int i = 1; i <= n; i++) cin >> h[i];
    cin >> s;
    s = " " + s;
    vector<int> pmx(n + 1), smx(n + 2);
    for (int i = 1; i <= n; i++) pmx[i] = max(pmx[i - 1], h[i]);
    for (int i = n; i >= 1; i--) smx[i] = max(smx[i + 1], h[i]);
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (h[i] > pmx[i - 1]) a[i] = 1;
        if (h[i] > smx[i + 1]) b[i] = 1;
        // cout << a[i] << " " << b[i] << '\n';
    }
    int sum = 0, ans = 0;
    vector<int> d(n + 1), pd(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'L')
        {
            sum += a[i];
            d[i] = b[i] - a[i];
        }
        else
        {
            sum += b[i];
            d[i] = a[i] - b[i];
        }
        pd[i] = pd[i - 1] + d[i];
        // cout << d[i] << ' ';
    }
    // cout << '\n';
    ans = sum;
    int st = 0;
    for (int k = 1; k <= n; k++)
    {
        if (sum + pd[k] > ans)
        {
            ans = sum + pd[k];
            st = k;
        }
    }
    cout << ans << ' ' << st << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}