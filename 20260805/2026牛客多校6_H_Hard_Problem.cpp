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
    // vector<int> a(n);
    auto p = [&](int n) -> bool
    {
        if (n == 1) return 0;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0) return 0;
        }
        return 1;
    };
    // iota(a.begin(), a.end(), 1);
    // do
    // {
    //     bool ok = 1;
    //     for (int i = 0; i < n; i++)
    //     {
    //         if (!ok) break;
    //         if (p(abs(a[i] - a[(i + 1) % n]))) ok = 0;
    //     }
    //     if (ok)
    //     {
    //         for (int i = 0; i < n; i++) cout << a[i] << " ";
    //         cout << '\n';
    //         return;
    //     }
    // } while (next_permutation(a.begin(), a.end()));
    // cout << -1 << '\n';
    if (!p(n - 1))
    {
        for (int i = 1; i <= n; i++) cout << i << " ";
        cout << '\n';
    }
    else
    {
        if (n == 3 || n == 4 || n == 6) cout << -1 << '\n';
        else
        {
            for (int i = 1; i <= n - 4; i++) cout << i << " ";
            for (int i = n; i > n - 4; i--) cout << i << " ";
            cout << '\n';
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