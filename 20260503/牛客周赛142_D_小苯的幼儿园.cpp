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
    vector<ll> a(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % n)
    {
        cout << "NO\n";
        return;
    }
    sum /= n;
    // vector<int> vis(n + 1);
    // for (int i = 1; i <= n; i++)
    // {
    //     if (abs(a[i] - sum) > 1)
    //     {
    //         cout << "NO\n";
    //         return;
    //     }
    // }
    // for (int i = 1; i <= n; i++)
    // {
    //     // if (i == 1 && (a[i] != sum && a[n] != sum && a[i] == a[n]))
    //     // {
    //     //     cout << "NO\n";
    //     //     return;
    //     // }
    //     // if (a[i] != sum && a[i - 1] != sum && a[i] == a[i - 1])
    //     // {
    //     //     cout << "NO\n";
    //     //     return;
    //     // }
    //     // if(vis[i])continue;
    //     if (a[i] > sum)
    //     {
    //         if (vis[i])
    //         {
    //             cout << "NO\n";
    //             return;
    //         }
    //         a[i]--;
    //         vis[i] = 1;
    //         if (i != n) a[i + 1]++;
    //         else a[1]++;
    //     }
    //     else if (a[i] < sum)
    //     {
    //         if (i == 1)
    //         {
    //             if (a[n] == 0 || vis[n])
    //             {
    //                 cout << "NO\n";
    //                 return;
    //             }
    //             a[n]--;
    //             a[i]++;
    //             vis[n] = 1;
    //         }
    //         else
    //         {
    //             if (a[i - 1] == 0 || vis[i - 1])
    //             {
    //                 cout << "NO\n";
    //                 return;
    //             }
    //             a[i - 1]--;
    //             a[i]++;
    //             vis[i - 1] = 1;
    //         }
    //     }
    // }

    // // cout << "YES\n";
    // for (int i = 1; i <= n; i++)
    // {
    //     if (a[i] != sum)
    //     {
    //         cout << "NO\n";
    //         return;
    //     }
    // }
    // cout << "YES\n";
    vector<int> vis(n + 1);
    for (int k = 1; k <= 2; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > sum && !vis[i])
            {
                a[i]--;
                vis[i] = 1;
                if (i == n) a[1]++;
                else a[i + 1]++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != sum)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}