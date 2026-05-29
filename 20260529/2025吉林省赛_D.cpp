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
vector<int> p, vis;
void sieve(int n)
{
    vis.assign(n + 1, 0);
    p.clear();
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i]) p.push_back(i);
        for (auto j : p)
        {
            if (i * j > n) break;
            vis[i * j] = 1; // 被标记的不是素数
            if (i % j == 0) break;
        }
    }
}
void moth()
{
    // int cnt=0;
    // while(cnt<=1000000)
    // {
    //     ll x = randint(1, 100), y = randint(x + 2, 102);
    //     if(__gcd(x,y)!=1&&__gcd(x+1,y)!=1&&__gcd(x,y-1)!=1)
    //     {
    //         cout<<x<<' '<<y<<'\n';
    //         break;
    //     }
    //     cnt++;
    // }
    // cout<<__gcd(2200,2189);
    // for(int i=5;i<=54;i++)
    // {
    //     if(__gcd(i,4)==1&&__gcd(i,55)==1)
    //     {
    //         cout<<i<<'\n';
    //         return;
    //     }
    // }
    ll x, y;
    cin >> x >> y;
    // if (y - x == 2)
    // {
    //     cout << x + 1 << '\n';
    //     return;
    // }
    // if (__gcd(x + 1, y) == 1)
    // {
    //     cout << x + 1 << '\n';
    //     return;
    // }
    // if (__gcd(x, y - 1) == 1)
    // {
    //     cout << y - 1 << '\n';
    //     return;
    // }
    // for (auto i : p)
    // {
    //     // if (i >= y - x) break;
    //     if (x % i && y % i)
    //     {
    //         // cout << x + i << '\n';
    //         // ll t = i;
    //         // while (t < y)
    //         // {
    //         //     if (t > x && t < y)
    //         //     {
    //         //         cout << t << '\n';
    //         //         return;
    //         //     }
    //         //     if (x + t < y && __gcd(x + t, y) == 1)
    //         //     {
    //         //         cout << x + t << '\n';
    //         //         return;
    //         //     }
    //         //     t *= i;
    //         // }

    //     }
    // }
    // cout << -1 << '\n';
    for (ll i = x + 1; i <= min(x + 10000, y - 1); i++)
    {
        if (__gcd(x, i) == 1 && __gcd(y, i) == 1)
        {
            cout << i << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}
int main()
{
    sieve(10000);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}