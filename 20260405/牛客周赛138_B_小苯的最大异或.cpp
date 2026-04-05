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
        if (c == '-')
            s = -1;
        c = getchar();
    }
    return x * s;
}
// 快写
void write(i128 x)
{
    if (x > 9)
        write(x / 10);
    putchar(x % 10 | 48);
}
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int randint(int l, int r)
{
    return uniform_int_distribution{l, r}(rnd);
}
void moth()
{
    ll x, y;
    cin >> x >> y;
    vector<ll> tx, ty;
    if (x)
        tx.push_back(0);
    if (y)
        ty.push_back(0);
    while (1)
    {
        tx.push_back(x);
        x /= 2;
        if (x == 0)
            break;
    }
    while (1)
    {
        ty.push_back(y);
        y /= 2;
        if (y == 0)
            break;
    }
    ll ans = 0;
    for (int i = 0; i < tx.size(); i++)
    {
        for (int j = 0; j < ty.size(); j++)
        {
            // cout << tx[i] << ' ' << ty[j] << ' ' << (tx[i] ^ ty[j]) << '\n';
            ans = max(ans, (tx[i] ^ ty[j]));
        }
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--)
        moth();
    return 0;
}