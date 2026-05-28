#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
const int N = 30;
const int mod = 1e9 + 9;
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
struct matrix
{
    ll c[N][N];
    // 构造默认函数，在创建matrix对象时自动调用
    matrix()
    {
        memset(c, 0, sizeof c);
    }
} A, res;
ll n, m, k, d;

// 矩阵乘法（运算符*重载）
matrix operator*(matrix &x, matrix &y)
{
    matrix t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++) t.c[i][j] = (t.c[i][j] + x.c[i][k] * y.c[k][j]) % mod;
        }
    }
    return t;
}
void ksm(ll k)
{
    memset(res.c, 0, sizeof res.c);
    for (int i = 1; i <= n; i++) res.c[i][i] = 1; // 单位矩阵
    while (k)
    {
        if (k & 1) res = res * A;
        A = A * A;
        k >>= 1;
    }
}
void moth()
{
    cin >> n >> m >> k >> d;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    vector<int> s(k);
    for (int i = 0; i < k; i++) cin >> s[i];
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u][v] = a[v][u] = 1;
    }
    auto cal = [&](int x) -> ll
    {
        matrix dp;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++) A.c[i][j] = a[i][j];
            dp.c[1][i] = 1;
        }
        vector<int> vis(n + 1);
        for (int i = 0; i < k; i++)
        {
            if ((x >> i) & 1)
            {
                int tt = s[i];
                for (int j = 1; j <= n; j++) A.c[tt][j] = A.c[j][tt] = 0;
                vis[tt] = 1;
                dp.c[1][tt] = 0;
            }
        }
        ksm(d - 1);
        dp = dp * res;
        ll sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i]) continue;
            sum += dp.c[1][i];
            sum %= mod;
        }
        return sum;
    };
    ll ans = 0;
    for (int i = 0; i < (1 << k); i++)
    {
        if (__builtin_popcount(i) % 2) ans = (ans - cal(i) + mod) % mod;
        else ans = (ans + cal(i)) % mod;
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