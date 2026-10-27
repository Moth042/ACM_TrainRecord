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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> viss(n + 1);
    vector<int> ff(n + 1);
    int mexx = 0;
    for (int i = 1; i <= n; i++)
    {
        viss[a[i]] = 1;
        while (mexx <= n && viss[mexx]) mexx++;
        ff[i] = mexx;
    }
    sort(ff.begin() + 1, ff.end(), greater());
    int mx = ff[k];
    int ansi = -1, ansj = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            auto b = a;
            swap(b[i], b[j]);
            vector<int> f(n + 1), vis(n + 1);
            int mex = 0;
            for (int p = 1; p <= n; p++)
            {
                vis[b[p]] = 1;
                while (mex <= n && vis[mex]) mex++;
                f[p] = mex;
            }
            sort(f.begin() + 1, f.end(), greater());
            if (f[k] > mx)
            {
                mx = f[k];
                ansi = i, ansj = j;
            }
        }
    }
    if (ansi == -1) cout << -1 << '\n';
    else cout << ansi << ' ' << ansj << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}