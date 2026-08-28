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
    // n = randint(1, 50);
    // k = randint(1, n * n);
    // cout << n << ' ' << k << '\n';
    cin >> n >> k;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    if (k < n || k > n * n - n + 1)
    {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    vector<int> vis(n * n + 1);
    int st = n * n;
    for (int i = 1; i < n; i++)
    {
        a[i][i] = st;
        vis[st] = 1;
        st--;
    }
    a[n][n] = k;
    vis[k] = 1;
    int stt = 1;
    for (int i = 1; i < n; i++)
    {
        a[n][i] = stt;
        vis[stt] = 1;
        stt++;
    }
    st = n * n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j]) continue;
            while (st >= 1 && vis[st]) st--;
            a[i][j] = st;
            vis[st] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) cout << a[i][j] << " ";
        cout << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}