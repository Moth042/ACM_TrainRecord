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
    ll n, x;
    cin >> n >> x;
    // ll one=(n-1)/4+1,preone=(x-1)/4+1;
    // ll three=(n-3)/4+1,prethree=(x-3)/4+1;
    // cout<<((preone%MOD)*((one-(x-2)/4+1)%MOD) % MOD+(prethree %MOD)*((three-(one-(x-4)/4+1))%MOD))%MOD<<'\n';
    ll x1 = (n - 1) / 4 + 1;
    ll px1;
    if (x == 1) px1 = 0;
    else px1 = (x - 1 - 1) / 4 + 1;
    ll x3, px3;
    if (n < 3)
    {
        x3 = 0;
        px3 = 0;
    }
    else
    {
        x3 = (n - 3) / 4 + 1;
        if (x <= 3) px3 = 0;
        else px3 = (x - 4) / 4 + 1;
    }
    cout << (((px1 % MOD) * ((x1 - px1) % MOD) % MOD) + ((px3 % MOD) * ((x3 - px3) % MOD) % MOD) + (x3 - px3) % MOD) %
                MOD
         << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) moth();
    return 0;
}