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
    if (n == 1)
    {
        cout << "impossible\n";
        return;
    }
    vector<int> a(n), vis(n);
    a[0] = 1, a[1] = 0;
    vis[0] = vis[1] = 1;
    int num = 2;
    for (int i = 2; i < n; i += 2)
    {
        a[i] = num;
        if (i + 1 < n) a[i + 1] = num + 2;
        vis[num] = vis[num + 2] = 1;
        while (num < n && vis[num]) num++;
    }
    ll p = 0;
    for (int i = 0; i < n; i++) p ^= i;
    if (p == 0) cout << "impossible\n";
    else
    {
        for (int i = 0; i < n; i++) cout << a[i] << ' ';
        cout << '\n';
    }
    // iota(a.begin(), a.end(), 0);
    // do
    // {
    //     int p = a[0];
    //     bool ok = 1;
    //     if (p == 0) continue;
    //     for (int i = 1; i < n; i++)
    //     {
    //         p ^= a[i];
    //         if (p == 0) ok = 0;
    //     }
    //     if (ok)
    //     {
    //         for (int i = 0; i < n; i++) cout << a[i] << " ";
    //         cout << '\n';
    //         return;
    //     }
    // } while (next_permutation(a.begin(), a.end()));
    // cout << -1 << '\n';
    // cout << (1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7) << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}