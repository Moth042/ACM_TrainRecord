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
    map<int, int> ji, ou;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        if (i % 2) ji[x]++;
        else ou[x]++;
    }
    ji[0] = ou[0] = 0;
    int mxj = 0, mxo = 0, mx2j = 0, mx2o = 0;
    for (auto [k, v] : ji)
    {
        if (v > ji[mxj])
        {
            mx2j = mxj;
            mxj = k;
        }
        else if (v == ji[mxj]) mx2j = k;
        else if (v > ji[mx2j]) mx2j = k;
    }
    for (auto [k, v] : ou)
    {
        if (v > ou[mxo])
        {
            mx2o = mxo;
            mxo = k;
        }
        else if (v == ou[mxo]) mx2o = k;
        else if (v > ou[mx2o]) mx2o = k;
    }
    if (mxj != mxo) cout << n - ji[mxj] - ou[mxo];
    else
    {
        if (mx2j == 0 && mx2o == 0) cout << n / 2;
        else if (mx2j == 0) cout << n / 2 - ou[mx2o];
        else if (mx2o == 0) cout << (n + 1) / 2 - ji[mx2j];
        else cout << min(n / 2 - ou[mx2o] + (n + 1) / 2 - ji[mxj], (n + 1) / 2 - ji[mx2j] + n / 2 - ou[mxo]);
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