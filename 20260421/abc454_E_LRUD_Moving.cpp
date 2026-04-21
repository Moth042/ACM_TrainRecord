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
void cal(int n, int m, int a, int b)
{
    if (n == 2 && m == 2)
    {
        if (a == 1) cout << "DR";
        else cout << "RD";
        return;
    }
    if (a > 2)
    {
        for (int i = 1; i < m; i++) cout << "R";
        cout << "D";
        for (int i = 1; i < m; i++) cout << "L";
        cout << "D";
        cal(n - 2, m, a - 2, b);
        return;
    }
    if (b > 2)
    {
        for (int i = 1; i < n; i++) cout << "D";
        cout << "R";
        for (int i = 1; i < n; i++) cout << "U";
        cout << "R";
        cal(n, m - 2, a, b - 2);
        return;
    }
    if (a <= n - 2)
    {
        cal(n - 2, m, a, b);
        cout << "D";
        for (int i = 1; i < m; i++) cout << "L";
        cout << "D";
        for (int i = 1; i < m; i++) cout << "R";
        return;
    }
    if (b <= m - 2)
    {
        cal(n, m - 2, a, b);
        cout << "R";
        for (int i = 1; i < n; i++) cout << "U";
        cout << "R";
        for (int i = 1; i < n; i++) cout << "D";
        return;
    }
}
void moth()
{
    int n, a, b;
    cin >> n >> a >> b;
    if (n % 2) cout << "No\n";
    else if (a % 2 == b % 2) cout << "No\n";
    else
    {
        cout << "Yes\n";
        cal(n, n, a, b);
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