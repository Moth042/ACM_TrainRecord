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
    vector<ll> x1, x2;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        if (y == 1) x1.push_back(x);
        else x2.push_back(x);
    }
    sort(x1.begin(), x1.end());
    sort(x2.begin(), x2.end());
    int num1 = x1.size(), num2 = x2.size();
    vector<ll> px1(num1 + 1), px2(num2 + 1);
    for (int i = 0; i < num1; i++) px1[i + 1] = px1[i] + x1[i];
    for (int i = 0; i < num2; i++) px2[i + 1] = px2[i] + x2[i];
    int mx = 0;
    ll mxx = 0;
    for (int i = 0; i <= num1 / 2; i++)
    {
        int j = num1 - i * 2;
        int p = num2 - i;
        if (p < 0) continue;
        int q = min(p / 2, j);
        mx = max(mx, i + q);
    }
    for (int i = 0; i <= num1 / 2; i++)
    {
        int j = num1 - i * 2;
        int p = num2 - i;
        if (p < 0) continue;
        int q = min(p / 2, j);
        if (i + q == mx) mxx = max(mxx, px1[num1] - px1[num1 - i] - px1[i] + px2[num2] - px2[num2 - q] - px2[q]);
    }
    cout << mx << ' ' << mxx << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) moth();
    return 0;
}