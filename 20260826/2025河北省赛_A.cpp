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
    vector<vector<ll>> a(3, vector<ll>(n + 1));
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    }
    if (n % 2)
    {
        ll ans1 = 0, ans2 = 0;
        int win1 = -2, win2 = -2;
        for (int i = 1; i <= n / 2; i++)
        {
            ans1 += a[1][i];
            ans2 += a[2][n - i + 1];
        }
        // 1 down
        ll df1 = 0, df2 = 0;
        for (int i = 1; i <= n / 2; i++)
        {
            df1 += a[2][i];
            df2 += a[1][n + 1 - i];
        }
        df2 += a[1][(n + 1) / 2] + a[2][(n + 1) / 2];
        if (ans1 + df1 > ans2 + df2) win1 = 1;
        else if (ans1 + df1 == ans2 + df2) win1 = 0;

        // 1 right
        df1 = df2 = 0;
        // for (int i = 1; i <= n / 2; i++)
        // {
        //     df1 += a[2][i];
        //     df2 += a[1][n + 1 - i];
        // }
        df1 += a[1][(n + 1) / 2];
        // 2 up
        for (int i = 1; i <= n / 2; i++)
        {
            df1 += a[2][i];
            df2 += a[1][n + 1 - i];
        }
        df1 += a[2][(n + 1) / 2];
        if (ans2 + df2 > ans1 + df1) win2 = 1;
        else if (ans2 + df2 == ans1 + df1) win2 = max(win2, 0);
        // 2 left
        df1 = df2 = 0;
        for (int i = 1; i <= (n + 1) / 2; i++)
        {
            df2 += a[2][i];
            df1 += a[1][n + 1 - i];
        }
        if (ans2 + df2 > ans1 + df1) win2 = 1;
        else if (ans2 + df2 == ans1 + df1) win2 = max(win2, 0);

        if (win1 == 1) cout << "Mandy\n";
        else if (win1 == 0)
        {
            if (win2 == -2) cout << "Mandy\n";
            else cout << "draw\n";
        }
        else
        {
            if (win2 == 1) cout << "brz\n";
            else if (win2 == 0) cout << "draw\n";
            else cout << "Mandy\n";
        }
    }
    else
    {
        ll ans1 = 0, ans2 = 0;
        for (int i = 1; i <= n / 2; i++) ans1 += a[1][i];
        for (int i = n; i >= n / 2 + 2; i--) ans2 += a[2][i];
        int win1 = -2, win2 = -2;
        // 2 up
        ll df1 = 0, df2 = 0;
        for (int i = n / 2 + 2; i <= n; i++) df2 += a[1][i];
        for (int i = n / 2 + 1; i >= 1; i--) df1 += a[2][i];
        df1 += a[1][n / 2 + 1];
        if (ans2 + df2 > ans1 + df1) win2 = 1;
        else if (ans2 + df2 == ans1 + df1) win2 = max(win2, 0);
        df1 = df2 = 0;

        // 2 left
        df2 += a[2][n / 2 + 1];
        // 1 right
        for (int i = n / 2 + 1; i <= n; i++)
        {
            df1 += a[1][i];
            df2 += a[2][n + 1 - i];
        }
        if (ans1 + df1 > ans2 + df2) win1 = 1;
        else if (ans1 + df1 == ans2 + df2) win1 = max(win1, 0);
        // 1 down
        df1 = df2 = 0;
        df2 += a[2][n / 2 + 1];
        for (int i = 1; i <= n / 2; i++)
        {
            df1 += a[2][i];
            df2 += a[1][n + 1 - i];
        }
        if (ans1 + df1 > ans2 + df2) win1 = 1;
        else if (ans1 + df1 == ans2 + df2) win1 = max(win1, 0);

        if (win2 == 1) cout << "brz\n";
        else if (win2 == 0)
        {
            if (win1 == -2) cout << "brz\n";
            else cout << "draw\n";
        }
        else
        {
            if (win1 == 1) cout << "Mandy\n";
            else if (win1 == 0) cout << "draw\n";
            else cout << "brz\n";
        }
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