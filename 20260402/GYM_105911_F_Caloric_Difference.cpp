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
void moth()
{
    int n, k;
    cin >> n >> k;
    double r0, c0, p, l, r;
    cin >> r0 >> c0 >> p >> l >> r;
    vector<double> R(n + 1, l);
    for (int i = 1; i <= k; i++)
    {
        int x;
        double v;
        cin >> x >> v;
        R[x] = v;
    }
    double ans = 0;
    vector<double> C(n + 1);
    C[0] = c0, R[0] = r0;
    for (int i = 1; i <= n; i++)
    {
        C[i] = p * C[i - 1] + (1 - p) * R[i - 1];
        ans += (C[i] - R[i]);
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cout << fixed << setprecision(10);
    cin >> _;
    while (_--)
        moth();
    return 0;
}