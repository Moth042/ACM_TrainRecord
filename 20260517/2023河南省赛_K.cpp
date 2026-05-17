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
    auto check = [&](int t) -> bool
    {
        if (t <= 1) return 0;
        for (int i = 2; i * i <= t; i++)
        {
            if (t % i == 0) return 0;
        }
        return 1;
    };
    if (n <= 10)
    {
        vector<int> a(n + 1);
        iota(a.begin(), a.end(), 0);
        do
        {
            bool ok = 1;
            for (int i = 1; i <= n; i++)
            {
                if (!check(abs(a[i] - a[i % n + 1])))
                {
                    ok = 0;
                    break;
                }
            }
            if (ok)
            {
                for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
                return;
            }
        } while (next_permutation(a.begin() + 1, a.end()));
        cout << -1 << '\n';
    }
    else
    {
        if (n == 11)
        {
            cout << "1 3 5 10 7 2 9 11 8 6 4\n";
            return;
        }
        if (n % 2)
        {
            for (int i = 1; i <= n; i += 2)
            {
                cout << i << ' ';
                if (i == 5) cout << 2 << ' ';
                if (i == n - 6) cout << n - 1 << ' ';
            }
            for (int i = n - 3; i >= 4; i -= 2) cout << i << ' ';
            cout << '\n';
        }
        else
        {
            for (int i = 1; i <= n - 3; i += 2)
            {
                cout << i << ' ';
                if (i == 5) cout << 2 << ' ';
            }
            for (int i = n; i >= 4; i -= 2)
            {
                cout << i << ' ';
                if (i == n - 6) cout << n - 1 << ' ';
            }
            cout << '\n';
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}